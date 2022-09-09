#include <stdio.h>
#include <vector>
#include <map>
#include <cstring>
using namespace std;
#define mp make_pair
const int N=100050;
vector< pair<int,int> > E[N];
int dist[N];
bool vis[N];
void DFS(int c, int p, int d)
{
	dist[c]=d;
	vis[c]=true;
	int i;
	for(i=0;i<E[c].size();i++)
	{
		int v=E[c][i].first;
		int w=E[c][i].second;
		if(v!=p) DFS(v,c,d^w);
	}
}
int p[N],r[N];
int Find(int x)
{
	if(p[x]!=x) p[x]=Find(p[x]);
	return p[x];
}
void Union(int x, int y)
{
	if(r[x]>r[y]) p[y]=x;
	if(r[y]>r[x]) p[x]=y;
	if(r[y]==r[x]) r[x]++,p[y]=x;
}
vector<char> tmp;
char word[50];
map< vector<char> ,int> Hash;
int sol[N];
vector< pair< pair<int,int> , pair<int,int> > > Unsolved;
int main()
{
	int n,m,q,i,j,u,v,w,l;
	scanf("%i %i %i",&n,&m,&q);
	for(i=1;i<=n;i++) p[i]=i;
	for(i=1;i<=n;i++)
	{
		scanf("%s",&word);
		l=strlen(word);
		tmp.clear();
		for(j=0;j<l;j++) tmp.push_back(word[j]);
		Hash[tmp]=i;
	}
	for(i=1;i<=m;i++)
	{
		scanf("%i",&w);w--;
		scanf("%s",&word);
		l=strlen(word);
		tmp.clear();
		for(j=0;j<l;j++) tmp.push_back(word[j]);
		u=Hash[tmp];
		scanf("%s",&word);
		l=strlen(word);
		tmp.clear();
		for(j=0;j<l;j++) tmp.push_back(word[j]);
		v=Hash[tmp];
		int x=Find(u);
		int y=Find(v);
		if(x!=y)
		{
			Union(x,y);
			E[u].push_back(mp(v,w));
			E[v].push_back(mp(u,w));
			sol[i]=1;
		}
		else Unsolved.push_back(mp(mp(u,v),mp(w,i)));
	}
	for(i=1;i<=n;i++) if(!vis[i]) DFS(i,0,0);
	for(i=0;i<Unsolved.size();i++)
	{
		u=Unsolved[i].first.first;
		v=Unsolved[i].first.second;
		w=Unsolved[i].second.first;
		j=Unsolved[i].second.second;
		if(dist[u]^dist[v]==w) sol[j]=1;
	}
	for(i=1;i<=m;i++)
	{
		if(sol[i]) printf("YES\n");
		else printf("NO\n");
	}
	while(q--)
	{
		scanf("%s",&word);
		l=strlen(word);
		tmp.clear();
		for(j=0;j<l;j++) tmp.push_back(word[j]);
		u=Hash[tmp];
		scanf("%s",&word);
		l=strlen(word);
		tmp.clear();
		for(j=0;j<l;j++) tmp.push_back(word[j]);
		v=Hash[tmp];
		int x=Find(u);
		int y=Find(v);
		if(x!=y) printf("3\n");
		else printf("%i\n",(dist[u]^dist[v])+1);
	}
	return 0;
}