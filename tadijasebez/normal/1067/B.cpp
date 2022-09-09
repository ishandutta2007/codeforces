#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
const int N=100050;
int dep[N],par[N];
vector<int> E[N];
void DFS(int u, int p){ dep[u]=dep[p]+1;par[u]=p;for(int v:E[u]) if(v!=p) DFS(v,u);}
bool ok=1;
void Check(int u, int p, int d, int k)
{
	int ch=0;
	for(int v:E[u]) if(v!=p)
	{
		ch++;
		Check(v,u,d+1,k);
	}
	if(ch==0){ if(d!=k+1) ok=0;}
	else if(ch<3) ok=0;
}
int main()
{
	int n,k,i,u,v;
	scanf("%i %i",&n,&k);
	for(i=1;i<n;i++) scanf("%i %i",&u,&v),E[u].pb(v),E[v].pb(u);
	DFS(1,0);
	int cen=0;
	for(i=1;i<=n;i++) if(dep[cen]<dep[i]) cen=i;
	DFS(cen,0);
	int den=0;
	for(i=1;i<=n;i++) if(dep[den]<dep[i]) den=i;
	int goal=(dep[den]+1)/2;
	int ctr=den;while(dep[ctr]>goal) ctr=par[ctr];
	Check(ctr,0,1,k);
	if(ok) printf("Yes\n");
	else printf("No\n");
	return 0;
}