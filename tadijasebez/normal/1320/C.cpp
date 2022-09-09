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
const int N=1000050;
const int M=2*N;
const ll inf=2e15;
ll mx[M],lzy[M];
int ls[M],rs[M],tsz,root;
ll cost[N];
void Build(int &c,int ss,int se){
	c=++tsz;lzy[c]=0;
	if(ss==se){mx[c]=cost[ss];return;}
	int mid=ss+se>>1;
	Build(ls[c],ss,mid);
	Build(rs[c],mid+1,se);
	mx[c]=max(mx[ls[c]],mx[rs[c]]);
}
void Add(int c,int ss,int se,int qs,int qe,ll f){
	if(qs>qe || qs>se || ss>qe)return;
	if(qs<=ss && qe>=se){lzy[c]+=f;mx[c]+=f;return;}
	int mid=ss+se>>1;
	Add(ls[c],ss,mid,qs,qe,f);
	Add(rs[c],mid+1,se,qs,qe,f);
	mx[c]=max(mx[ls[c]],mx[rs[c]])+lzy[c];
}
int b[N],cb[N];
pair<int,int> a[N];
pair<int,pair<int,int>> huo[N];
int main(){
	int n,m,p;
	scanf("%i %i %i",&n,&m,&p);
	for(int i=1;i<=n;i++)scanf("%i %i",&a[i].first,&a[i].second);
	for(int i=1;i<=m;i++)scanf("%i %i",&b[i],&cb[i]);
	for(int i=1;i<=p;i++)scanf("%i %i %i",&huo[i].first,&huo[i].second.first,&huo[i].second.second);
	sort(a+1,a+1+n);
	sort(huo+1,huo+1+p);
	for(int i=1;i<N;i++)cost[i]=-inf;
	for(int i=1;i<=m;i++)cost[b[i]]=max(cost[b[i]],(ll)-cb[i]);
	Build(root,1,N-1);
	ll ans=-inf;
	for(int i=1,j=1;i<=n;i++){
		while(j<=p && huo[j].first<a[i].first){
			Add(root,1,N-1,huo[j].second.first+1,N-1,huo[j].second.second);
			j++;
		}
		ans=max(ans,mx[root]-a[i].second);
	}
	printf("%lld\n",ans);
	return 0;
}