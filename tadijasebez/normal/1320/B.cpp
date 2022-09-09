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
const int N=200050;
vector<int> E[N],R[N];
int dist[N],a[N];
int main(){
	int n,m,k;
	scanf("%i %i",&n,&m);
	for(int i=1;i<=m;i++){
		int u,v;
		scanf("%i %i",&u,&v);
		E[u].pb(v);
		R[v].pb(u);
	}
	scanf("%i",&k);
	for(int i=1;i<=k;i++)scanf("%i",&a[i]);
	queue<int> q;
	for(int i=1;i<=n;i++)dist[i]=1e9+7;
	q.push(a[k]);dist[a[k]]=0;
	while(q.size()){
		int u=q.front();
		q.pop();
		for(int v:R[u])if(dist[v]>dist[u]+1){
			dist[v]=dist[u]+1;
			q.push(v);
		}
	}
	int mn=0,mx=0;
	for(int i=1;i<k;i++){
		if(dist[a[i]]==dist[a[i+1]]+1){
			int cnt=0;
			for(int y:E[a[i]])if(dist[y]+1==dist[a[i]])cnt++;
			if(cnt>1)mx++;
		}
		else mn++,mx++;
	}
	printf("%i %i\n",mn,mx);
	return 0;
}