#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
const int N=100050;
const int S=317;
vector<int> E[N];
int len[N],all;
void DFS(int u, int p, int k)
{
	bool ok=0;
	len[u]=0;
	for(int v:E[u]) if(v!=p)
	{
		DFS(v,u,k);
		if(len[u]+len[v]>=k-1) ok=1;
		len[u]=max(len[u],len[v]);
	}
	if(ok || k==1) all++,len[u]=0;
	else len[u]++;
}
int sol[N];
void Solve(int l, int r, int L, int R)
{
	if(l>r) return;
	if(L==R){ for(int i=l;i<=r;i++) sol[i]=L;return;}
	int mid=l+r>>1;
	all=0;
	DFS(1,0,mid);
	sol[mid]=all;
	Solve(l,mid-1,sol[mid],R);
	Solve(mid+1,r,L,sol[mid]);
}
int main()
{
	int n,u,v,i;
	scanf("%i",&n);
	for(i=1;i<n;i++) scanf("%i %i",&u,&v),E[u].pb(v),E[v].pb(u);
	Solve(1,n,0,n);
	for(i=1;i<=n;i++) printf("%i\n",sol[i]);
	return 0;
}