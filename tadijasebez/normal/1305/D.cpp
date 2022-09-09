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
const int N=2050;
int now,n;
bool del[N];
vector<int> nodes,diam,E[N];
int dep[N],par[N];
void Ask(){
	printf("? %i %i\n",diam[0],diam.back());
	fflush(stdout);
	int b;
	scanf("%i",&b);
	for(int i:diam)if(i!=b)del[i]=1;
	now=b;
}
void DFS(int u,int p){
	dep[u]=dep[p]+1;
	par[u]=p;
	nodes.pb(u);
	for(int v:E[u])if(v!=p && !del[v])DFS(v,u);
}
bool FindDiam(){
	nodes.clear();
	DFS(now,0);
	int cen=0,den=0;
	for(int i:nodes)if(dep[i]>dep[cen])cen=i;
	nodes.clear();
	DFS(cen,0);
	for(int i:nodes)if(dep[i]>dep[den])den=i;
	if(dep[den]==1)return 0;
	diam.clear();
	for(int i=den;i;i=par[i])diam.pb(i);
	Ask();
	return 1;
}
int main(){
	scanf("%i",&n);
	for(int i=1,u,v;i<n;i++)scanf("%i %i",&u,&v),E[u].pb(v),E[v].pb(u);
	now=1;
	while(FindDiam());
	printf("! %i\n",now);
	fflush(stdout);
	return 0;
}