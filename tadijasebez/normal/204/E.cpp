#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
const int N=100050;
const int M=N*2;
map<char,int> go[M];
int link[M],sz[M],dep[M],root,tsz,dis[M];
char *s[M];
vector<int> ids[M];
int MakeNode(char *t, int len){ tsz++;s[tsz]=t;sz[tsz]=len;return tsz;}
void Extend(char *t, int n, int id)
{
	if(!root) root=MakeNode(NULL,0);
	int atnode=root,atlen=0,atedge=0,pleaf=0,pnode=0;
	for(int i=0;i<=n;i++)
	{
		while(1)
		{
			int tonode=atedge==n?0:go[atnode][t[atedge]];
			if(tonode && sz[tonode]<=atlen)
			{
				atedge+=sz[tonode];
				atlen-=sz[tonode];
				atnode=tonode;
				continue;
			}
			if(!tonode)
			{
				if(i==n)
				{
					ids[atnode].pb(id);
					if(pleaf) link[pleaf]=atnode;pleaf=0;
				}
				else
				{
					int leaf=MakeNode(t+i,n-i);
					go[atnode][t[i]]=leaf;
					ids[leaf].pb(id);
					if(pleaf) link[pleaf]=leaf;pleaf=leaf;
				}
				if(pnode) link[pnode]=atnode;pnode=0;
			}
			else if(i==n || t[i]!=s[tonode][atlen])
			{
				int node=MakeNode(s[tonode],atlen);
				sz[tonode]-=atlen;s[tonode]+=atlen;
				go[atnode][s[node][0]]=node;
				go[node][s[tonode][0]]=tonode;
				if(i==n)
				{
					ids[node].pb(id);
					if(pleaf) link[pleaf]=node;pleaf=0;
				}
				else
				{
					int leaf=MakeNode(t+i,n-i);
					go[node][t[i]]=leaf;
					ids[leaf].pb(id);
					if(pleaf) link[pleaf]=leaf;pleaf=leaf;
				}
				if(pnode) link[pnode]=node;pnode=node;
			}
			else
			{
				if(pnode) link[pnode]=atnode;pnode=0;
				atlen++;
				break;
			}
			if(atnode==root)
			{
				atedge++;
				if(atlen) atlen--;
				else break;
			}
			else atnode=link[atnode];
		}
	}
}
set<int> all[M];
void DFS(int u, int p)
{
	dep[u]=dep[p]+sz[u];
	for(auto f:go[u]) if(f.second)
	{
		DFS(f.second,u);
		if(all[u]>all[f.second]) all[u].swap(all[f.second]);
		for(int i:all[f.second]) all[u].insert(i);
	}
	for(int i:ids[u]) all[u].insert(i);
	dis[u]=all[u].size();
}
ll sol[N];
int k;
void Solve(int u, int p)
{
	if(dis[u]>=k) p=u;
	for(int i:ids[u]) sol[i]+=dep[p];
	for(auto f:go[u]) if(f.second) Solve(f.second,p);
}
char str[N];
int fir[N],len[N];
int main()
{
	int n,i;
	scanf("%i %i",&n,&k);
	for(i=1;i<=n;i++)
	{
		scanf("%s",str+fir[i]);
		len[i]=strlen(str+fir[i]);
		Extend(str+fir[i],len[i],i);
		fir[i+1]=fir[i]+len[i];
	}
	DFS(root,0);
	Solve(root,0);
	for(i=1;i<=n;i++) printf("%lld ",sol[i]);
	return 0;
}