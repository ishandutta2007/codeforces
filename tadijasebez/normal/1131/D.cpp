#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N=2050;
vector<int> E[N];
int in[N],val[N],p[N];
int Find(int x){ return p[x]==x?x:p[x]=Find(p[x]);}
void Union(int x, int y){ p[Find(x)]=Find(y);}
char s[N][N];
int main()
{
	int n,m,i,j;
	scanf("%i %i",&n,&m);
	for(i=1;i<=n+m;i++) p[i]=i;
	for(i=1;i<=n;i++)
	{
		scanf("%s",s[i]+1);
		for(j=1;j<=m;j++)
		{
			if(s[i][j]=='=') Union(i,n+j);
		}
	}
	for(i=1;i<=n;i++) for(j=1;j<=m;j++)
	{
		if(s[i][j]=='<') E[Find(i)].pb(Find(n+j)),in[Find(n+j)]++;
		if(s[i][j]=='>') E[Find(n+j)].pb(Find(i)),in[Find(i)]++;
	}
	queue<int> q;
	for(i=1;i<=n+m;i++) if(Find(i)==i && in[i]==0) q.push(i),val[i]=1;
	while(q.size())
	{
		int u=q.front();
		q.pop();
		for(int v:E[u])
		{
			in[v]--;
			val[v]=max(val[v],val[u]+1);
			if(in[v]==0) q.push(v);
		}
	}
	for(int i=1;i<=n+m;i++) if(in[i]) return 0*printf("No\n");
	printf("Yes\n");
	for(i=1;i<=n;i++) printf("%i ",val[Find(i)]);printf("\n");
	for(i=n+1;i<=n+m;i++) printf("%i ",val[Find(i)]);printf("\n");
	return 0;
}