#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <stdlib.h>
#include <ctime>
#include <cmath>
#include <complex>
#include <iostream>
#include <cctype>
#include <cstring>
#include <bitset>
#include <stack>
#include <functional>
#include <cassert>
#include <tuple>
#include <iomanip>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define ldb long double
#define mt make_tuple
template<typename T> bool ckmn(T &a, T b){ T c=a;a=min(a,b);return a!=c;}
template<typename T> bool ckmx(T &a, T b){ T c=a;a=max(a,b);return a!=c;}
const int N=2005;
vector<int> E[N];
int c[N];
int a[N],sz[N];
void Inc(int u, int mn, int f)
{
	if(a[u]>=mn) a[u]+=f;
	for(int v:E[u]) Inc(v,mn,f);
}
void No()
{
	printf("NO\n");
	exit(0);
}
void DFS(int u)
{
	//printf("u:%i ",u);
	//for(int i=1;i<=3;i++) printf("%i ",a[i]);
	//printf("\n");
	sz[u]=1;
	for(int v:E[u])
	{
		DFS(v);
		Inc(v,0,sz[u]-1);
		sz[u]+=sz[v];
	}
	if(sz[u]<c[u]+1) No();
	Inc(u,c[u]+1,1);
	a[u]=c[u]+1;
	//printf("%i %i\n",u,c[u]+1);
}
int main()
{
	int n,root;
	scanf("%i",&n);
	for(int i=1;i<=n;i++)
	{
		int p;
		scanf("%i %i",&p,&c[i]);
		if(p) E[p].pb(i);
		else root=i;
	}
	DFS(root);
	printf("YES\n");
	for(int i=1;i<=n;i++) printf("%i ",a[i]);
	return 0;
}