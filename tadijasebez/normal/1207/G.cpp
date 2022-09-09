#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
const int N=800050;
int go[N][26],root=1,tsz=1,node[N],link[N],dep[N];
int Add(int c, char ch)
{
	if(!go[c][ch-'a']) go[c][ch-'a']=++tsz;
	return go[c][ch-'a'];
}
int AddString(char s[], int n)
{
	int u=root;
	for(int i=0;i<n;i++) u=Add(u,s[i]);
	return u;
}
vector<int> E[N];
void BuildAhoCorasick()
{
	queue<int> q;
	for(int i=0;i<26;i++)
	{
		if(go[root][i])
		{
			q.push(go[root][i]);
			link[go[root][i]]=root;
			dep[go[root][i]]=1;
		}
		else go[root][i]=root;
	}
	while(q.size())
	{
		int u=q.front();
		q.pop();
		for(int i=0;i<26;i++)
		{
			if(go[u][i])
			{
				link[go[u][i]]=go[link[u]][i];
				q.push(go[u][i]);
				dep[go[u][i]]=dep[u]+1;
			}
			else go[u][i]=go[link[u]][i];
		}
	}
	for(int i=2;i<=tsz;i++) E[link[i]].pb(i);
}
char q_str[N];
int st[N],len[N],id[N],q_node[N],ans[N];
vector<int> Qs[N];
int lid[N],rid[N],tid;
void DFS(int u)
{
	lid[u]=++tid;
	for(int v:E[u]) DFS(v);
	rid[u]=tid;
}
struct BIT
{
	int sum[N];
	BIT(){}
	void Set(int i, int f){ for(;i<N;i+=i&-i) sum[i]+=f;}
	int Get(int i){ int ans=0;for(;i;i-=i&-i) ans+=sum[i];return ans;}
	int Get(int l, int r){ return Get(r)-Get(l-1);}
} ST;
void Solve(int u)
{
	ST.Set(lid[u],1);
	for(int qid:Qs[u])
	{
		ans[qid]=ST.Get(lid[q_node[qid]],rid[q_node[qid]]);
	}
	for(int i=0;i<26;i++) if(dep[u]+1==dep[go[u][i]])
	{
		Solve(go[u][i]);
	}
	ST.Set(lid[u],-1);
}
int main()
{
	int n,q;
	scanf("%i",&n);
	for(int i=1;i<=n;i++)
	{
		int t,j;char c;
		scanf("%i",&t);
		if(t==1) scanf(" %c",&c),node[i]=Add(root,c);
		else scanf("%i %c",&j,&c),node[i]=Add(node[j],c);
	}
	scanf("%i",&q);
	for(int i=1;i<=q;i++)
	{
		scanf("%i %s",&id[i],q_str+st[i]);
		len[i]=strlen(q_str+st[i]);
		st[i+1]=st[i]+len[i];
		q_node[i]=AddString(q_str+st[i],len[i]);
		Qs[node[id[i]]].pb(i);
	}
	BuildAhoCorasick();
	DFS(root);
	Solve(root);
	for(int i=1;i<=q;i++) printf("%i\n",ans[i]);
	return 0;
}