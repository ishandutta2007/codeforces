#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <sstream>
#include <stack>
#include <iomanip>
using namespace std;
#define pb push_back
#define inf 1001001001
#define infll 1001001001001001001LL
#define FOR0(i,n) for(int (i)=0;(i)<(n);++(i))
#define FOR1(i,n) for(int (i)=1;(i)<=(n);++(i))
#define mp make_pair
#define pii pair<int,int>
#define ll long long
#define ld double
#define vi vector<int>
#define fi first
#define se second
#define RI(n) int (n); scanf("%d",&(n));
#define RI2(n,m) int (n),(m); scanf("%d %d",&(n),&(m));
#define RI3(n,m,k) int (n),(m),(k); scanf("%d %d %d",&(n),&(m),&(k));
template<typename T,typename TT> ostream& operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream& operator<<(ostream &s,vector<T> t){FOR0(i,sz(t))s<<t[i]<<" ";return s; }
#define dbg(vari) cerr<<#vari<<" = "<<(vari)<<endl
#define all(t) t.begin(),t.end()
#define FEACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define TESTS RI(testow)while(testow--)
#define FORZ(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define FORD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define gmax(a,b) (a)=max((a),(b))
#define gmin(a,b) (a)=min((a),(b))
#define ios0 ios_base::sync_with_stdio(0)
#define SZ 666666
int n,m;
int M=0,fst[SZ],vb[SZ],nxt[SZ];
void ad_de(int a,int b)
{
	++M; nxt[M]=fst[a]; fst[a]=M; vb[M]=b;
}
void adde(int a,int b) {ad_de(a,b); ad_de(b,a);}
ll ans=0,dis[SZ];
void gd(int x)
{
	int son=0;
	for(int e=fst[x];e;e=nxt[e])
	{
		int b=vb[e];
		if(dis[b]) continue;
		dis[b]=1; gd(b); ++son;
	}
	ans+=(x!=1)*son;
	ans+=(son-1)*(ll)son/2;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		adde(a,b);
	}
	dis[1]=1; gd(1);
	cout<<ans<<"\n";
}