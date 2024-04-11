#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
const int N=1050;
vector<int> E[N];
bool fir[N],sec[N];
int AskA(int x){ printf("A %i\n",x);fflush(stdout);int b;scanf("%i",&b);return b;}
int AskB(int x){ printf("B %i\n",x);fflush(stdout);int b;scanf("%i",&b);return b;}
int Find(int u, int p=0)
{
	if(fir[u]==1) return u;
	for(int v:E[u]) if(v!=p)
	{
		int x=Find(v,u);
		if(x) return x;
	}
	return 0;
}
void Run()
{
	int n,u,v,i;
	scanf("%i",&n);
	for(i=1;i<=n;i++) E[i].clear(),fir[i]=sec[i]=0;
	for(i=1;i<n;i++) scanf("%i %i",&u,&v),E[u].pb(v),E[v].pb(u);
	int sz,x;scanf("%i",&sz);
	while(sz--) scanf("%i",&x),fir[x]=1;
	scanf("%i",&sz);
	while(sz--) scanf("%i",&x),sec[x]=1;
	//printf(":D\n");
	int y=AskB(x);
	int p=Find(y);
	int res=AskA(p);
	if(sec[res]) printf("C %i\n",p);
	else printf("C -1\n");
	fflush(stdout);
}
int main()
{
	int t;scanf("%i",&t);
	while(t--) Run();
	return 0;
}