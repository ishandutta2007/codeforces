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
vector<int> E[N];
void BFS(int s,int n,int dist[]){
	for(int i=1;i<=n;i++)dist[i]=N;
	dist[s]=0;
	queue<int> q;
	q.push(s);
	while(q.size()){
		int u=q.front();
		q.pop();
		for(int v:E[u]){
			if(dist[v]>dist[u]+1){
				dist[v]=dist[u]+1;
				q.push(v);
			}
		}
	}
}
int d1[N],d2[N],a[N];
pair<int,int> tws[N];
int mx[N],sec[N];
void Add(int i,int x){
	if(mx[i]<x)sec[i]=mx[i],mx[i]=x;
	else ckmx(sec[i],x);
}
int main(){
	int n,m,k;
	scanf("%i %i %i",&n,&m,&k);
	for(int i=1;i<=k;i++)scanf("%i",&a[i]);
	for(int i=1,u,v;i<=m;i++)scanf("%i %i",&u,&v),E[u].pb(v),E[v].pb(u);
	BFS(1,n,d1);
	BFS(n,n,d2);
	for(int i=0;i<=n;i++)mx[i]=sec[i]=-N;
	for(int i=1;i<=k;i++)tws[i]={d1[a[i]],d2[a[i]]},Add(d1[a[i]],d2[a[i]]);
	for(int i=n-1;i>=0;i--){
		Add(i,mx[i+1]);
		Add(i,sec[i+1]);
	}
	int top=n,bot=0,mid,ans=d1[n];
	while(top>=bot){
		mid=top+bot>>1;
		bool ok=0;
		//printf("mid:%i\n",mid);
		for(int i=1;i<=k;i++){
			int fir=mid-d2[a[i]]-1;
			fir=max(fir,0);
			int tmp=mx[fir];
			if(d1[a[i]]>=fir && d2[a[i]]==mx[fir])tmp=sec[fir];
			//printf("%i %i %i %i %i %i\n",a[i],d1[a[i]],d2[a[i]],fir,tmp,mid-d1[a[i]]-1);
			if(tmp>=mid-d1[a[i]]-1)ok=1;
		}
		if(ok)ans=mid,bot=mid+1;
		else top=mid-1;
	}
	ans=min(ans,d1[n]);
	printf("%i\n",ans);
	return 0;
}