#include <stdio.h>
#include <vector>
using namespace std;
#define pb push_back
const int N=200050;
int p[N],on[N];
void Init(){ for(int i=0;i<N;i++) p[i]=i;}
int Find(int x){ return x==p[x]?x:p[x]=Find(p[x]);}
void Union(int x, int y){ p[Find(x)]=Find(y);}
vector<int> tmp[N];
int main()
{
	int n,m,i,b,x,u,v;
	scanf("%i %i",&n,&m);
	for(i=1;i<=n;i++) scanf("%i",&on[i]);
	for(i=1;i<=m;i++)
	{
		scanf("%i",&b);
		while(b--) scanf("%i",&x),tmp[x].pb(i);
	}
	Init();
	for(i=1;i<=n;i++)
	{
		u=tmp[i][0];
		v=tmp[i][1];
		if(on[i]) Union(u*2,v*2),Union(u*2+1,v*2+1);
		else Union(u*2,v*2+1),Union(u*2+1,v*2);
	}
	for(i=1;i<=m;i++) if(Find(i*2)==Find(i*2+1)) return printf("NO\n"),0;
	printf("YES\n");
	return 0;
}