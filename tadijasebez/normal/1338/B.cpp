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
const int N=300050;
vector<int> E[N];
int dep[N],cnt[2],sz[N],leaf;
void DFS(int u,int p){
	dep[u]=dep[p]+1;
	if(E[u].size()==1){
		cnt[dep[u]&1]++;
		sz[p]++;
		leaf++;
	}
	for(int v:E[u])if(v!=p)DFS(v,u);
}
int main(){
	int n;
	scanf("%i",&n);
	for(int i=1,u,v;i<n;i++)scanf("%i %i",&u,&v),E[u].pb(v),E[v].pb(u);
	int root=1;
	for(int i=1;i<=n;i++)if(E[i].size()>1)root=i;
	DFS(root,0);
	int mn;
	if(cnt[0]==0 || cnt[1]==0)mn=1;
	else mn=3;
	int mx=n-1;
	for(int i=1;i<=n;i++)if(sz[i]){
		mx-=sz[i]-1;
	}
	printf("%i %i\n",mn,mx);
	return 0;
}