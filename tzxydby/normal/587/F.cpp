#include<bits/stdc++.h>
using namespace std;
const int N=100005,B=400;
int n,m,tr[N][26],t=1,ch[N*2][26],fa[N*2],len[N*2],sz=1,p[N],ps[N];
long long ans[N];
string s[N];
struct qu{int l,r,d;};
vector<qu>q[N],qs[N*2];
vector<int>e[N*2],ap[N*2];
queue<int>qu;
int ins(int c,int las)
{
	int p=las,x=++sz;
	len[x]=len[p]+1;
	while(p&&!ch[p][c])
	{
		ch[p][c]=x;
		p=fa[p];
	}
	if(!p)
		fa[x]=1;
	else
	{
		int q=ch[p][c];
		if(len[p]+1==len[q])
			fa[x]=q;
		else
		{
			int nq=++sz;
			memcpy(ch[nq],ch[q],sizeof(ch[q]));
			fa[nq]=fa[q],len[nq]=len[p]+1;
			while(p&&ch[p][c]==q)
			{
				ch[p][c]=nq;
				p=fa[p];
			}
			fa[q]=fa[x]=nq;
		}
	}
	return x;
}
namespace block
{
	int b[N],c[N];
	void add(int x,int v)
	{
		for(int i=x/B+1;i<=n/B+1;i++)
			b[i]+=v;
		for(int i=x;i<x/B*B+B;i++)
			c[i]+=v;
	}
	int query(int x)
	{
		return b[x/B]+c[x];
	}
	int ask(int l,int r)
	{
		return query(r)-query(l-1);
	}
}
namespace sol0
{
	void dfs(int u)
	{
		for(auto i:ap[u])
			block::add(i,1);
		for(auto [l,r,d]:qs[u])
			ans[d]+=block::ask(l,r);
		for(auto v:e[u])
			dfs(v);
		for(auto i:ap[u])
			block::add(i,-1);
	}
	void main()
	{
		for(int i=1;i<=n;i++)
		{
			if(s[i].size()<=B)
			{
				int u=1;
				for(auto ch:s[i])
				{
					int c=ch-'a';
					u=tr[u][c];
					for(auto j:q[i])
						qs[ps[u]].push_back(j);
				}
			}
		}
		dfs(1);
	}
}
namespace sol1
{
	int b[N*2];
	long long pr[N];
	void dfs(int u)
	{
		for(auto v:e[u])
		{
			dfs(v);
			b[u]+=b[v];
		}
	}	
	void cal(int x)
	{
		for(int i=0;i<=sz;i++)
			b[i]=0;
		int u=1;
		for(auto ch:s[x])
		{
			int c=ch-'a';
			u=tr[u][c];
			b[ps[u]]++;
		}
		dfs(1);
		for(int i=1;i<=n;i++)
			pr[i]=pr[i-1]+b[ps[p[i]]];
		for(auto [l,r,d]:q[x])
			ans[d]+=pr[r]-pr[l-1];
	}
	void main()
	{
		for(int i=1;i<=n;i++)
			if(s[i].size()>B)
				cal(i);
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
		int u=1;
		for(auto ch:s[i])
		{
			int c=ch-'a';
			if(!tr[u][c])
				tr[u][c]=++t;
			u=tr[u][c];
		}
		p[i]=u;
	}
	for(int i=1;i<=m;i++)
	{
		int l,r,k;
		cin>>l>>r>>k;
		q[k].push_back({l,r,i});
	}
	ps[1]=1;
	qu.push(1);
	while(!qu.empty())
	{
		int u=qu.front();
		qu.pop();
		for(int i=0;i<26;i++)
		{
			int v=tr[u][i];
			if(v)
			{
				ps[v]=ins(i,ps[u]);
				qu.push(v);
			}
		}
	}
	for(int i=2;i<=sz;i++)
		e[fa[i]].push_back(i);
	for(int i=1;i<=n;i++)
		ap[ps[p[i]]].push_back(i);
	sol0::main();
	sol1::main();
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<"\n";
	return 0;
}