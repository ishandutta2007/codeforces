#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <bitset>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <sstream>
#include <stack>
#include <iomanip>
#include <assert.h>
using namespace std;
#define pb push_back
#define mp make_pair
typedef pair<int,int> pii;
typedef long long ll;
typedef double ld;
typedef vector<int> vi;
#define fi first
#define se second
#define fe first
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}
#define Edg int M=0,fst[SZ],vb[SZ],nxt[SZ];void ad_de(int a,int b){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;}void adde(int a,int b){ad_de(a,b);ad_de(b,a);}
#define Edgc int M=0,fst[SZ],vb[SZ],nxt[SZ],vc[SZ];void ad_de(int a,int b,int c){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;vc[M]=c;}void adde(int a,int b,int c){ad_de(a,b,c);ad_de(b,a,c);}
#define es(x,e) (int e=fst[x];e;e=nxt[e])
#define esb(x,e,b) (int e=fst[x],b=vb[e];e;e=nxt[e],b=vb[e])
#define SZ 666666
Edg
int n,k,m,d[SZ],w[SZ];
map<ll,ll> f[SZ];
//f[i][j]: j 
//f[i][j]=\sum_c f[c][j]
//f[i][j]=\sum_c f[c][d[i]]+w[i]  (j>=d[i])
void dp(int x)
{
	for esb(x,e,b)
	{
		dp(b);
		if(f[x].size()<f[b].size())
			swap(f[x],f[b]);
		for(auto t:f[b])
			f[x][t.fi]+=t.se;
	}
	ll u=w[x];
	f[x][d[x]]+=u;
	auto w=f[x].upper_bound(d[x]);
	while(1)
	{
		if(w==f[x].end()) break;
		if(w->se>u)
		{
			w->se-=u;
			break;
		}
		u-=w->se; f[x].erase(w++);
	}
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=2,f;i<=n;++i)
		scanf("%d",&f),ad_de(f,i);
	for(int i=1;i<=n;++i) d[i]=1;
	for(int i=1;i<=m;++i)
	{
		int v,dd,ww;
		scanf("%d%d%d",&v,&dd,&ww);
		d[v]=dd; w[v]=ww;
	}
	dp(1);
	ll ans=0;
	for(auto t:f[1]) ans+=t.se;
	printf("%lld\n",ans);
}