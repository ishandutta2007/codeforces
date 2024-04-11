#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
#define N 5005
struct Edge
{
	int to,nxt;
};
Edge edge[N];
int fir[N],ss;
void add(int u,int v)
{
	ss++; edge[ss].to=v,edge[ss].nxt=fir[u],fir[u]=ss;
}
int dgr[N];
int fr[N],ed[N];
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int n=read(),m=read();
	for(int i=1;i<=m;i++)
	{
		fr[i]=read(),ed[i]=read();
		add(fr[i],ed[i]);
		dgr[ed[i]]++;
	}
	queue<int> q;
	for(int i=1;i<=n;i++)
	{
		if(dgr[i]==0) q.push(i);
	}
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(int i=fir[u];i!=0;i=edge[i].nxt)
		{
			int v=edge[i].to;
			dgr[v]--;
			if(dgr[v]==0) q.push(v);
		}
	}
	bool ok=true;
	for(int i=1;i<=n;i++)
	{
		if(dgr[i]!=0) ok=false;
	}
	if(ok)
	{
		cout<<1<<endl;
		for(int i=1;i<=m;i++) printf("1 ");
		cout<<"\n";
		return 0;
	}
	cout<<"2\n";
	for(int i=1;i<=m;i++)
	{
		if(fr[i]>ed[i]) cout<<"1 ";
		else cout<<"2 ";
	}
	cout<<"\n";
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}