#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int N=400050;
const int M=2*N;
map<char,int> go[M];
int link[M],len[M],tsz,sz[M],lf[M];
vector<int> E[M];
int Extend(int u, char c)
{
	int v=++tsz;len[v]=len[u]+1;lf[v]=1;
	while(u!=-1 && !go[u].count(c)) go[u][c]=v,u=link[u];
	if(u!=-1)
	{
		int p=go[u][c];
		if(len[p]==len[u]+1) link[v]=p;
		else
		{
			tsz++;len[tsz]=len[u]+1;go[tsz]=go[p];link[tsz]=link[p];
			while(u!=-1 && go[u][c]==p) go[u][c]=tsz,u=link[u];
			link[p]=link[v]=tsz;
		}
	}
	return v;
}
void DFS(int u){ for(int v:E[u]) sz[v]+=sz[u],DFS(v);}
char t[N],s[N];
int n,m,ln[N],st[N];
void Solve(int cnt[])
{
	int cur=0;link[0]=-1;
	for(int i=0;i<m;i++) cur=Extend(cur,t[i]);
	for(int i=1;i<=tsz;i++) E[link[i]].pb(i);
	for(int i=1;i<=n;i++)
	{
		cur=0;
		for(int j=st[i];j<st[i]+ln[i];j++)
		{
			if(go[cur].count(s[j])) cur=go[cur][s[j]];
			else{ cur=-1;break;}
		}
		if(cur!=-1) sz[cur]++;
	}
	DFS(0);
	for(int i=1;i<=tsz;i++) if(lf[i]) cnt[len[i]]=sz[i];
	for(int i=0;i<=tsz;i++)
	{
		E[i].clear();go[i].clear();
		link[i]=sz[i]=len[i]=lf[i]=0;
	}
	tsz=0;
}
int L[N],R[N];
int main()
{
	scanf("%s",t);
	m=strlen(t);
	scanf("%i",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s+st[i]);
		ln[i]=strlen(s+st[i]);
		st[i+1]=st[i]+ln[i];
	}
	Solve(L);
	reverse(t,t+m);
	for(int i=1;i<=n;i++) reverse(s+st[i],s+st[i]+ln[i]);
	Solve(R);
	ll ans=0;
	for(int i=1;i<m;i++) ans+=(ll)L[i]*R[m-i];
	printf("%lld\n",ans);
	return 0;
}