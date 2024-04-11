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
int n; ll x,a[SZ];
const int MOD=998244353;
ll po2[SZ];
ll cany(int x) {
	return po2[x]-1;
}
ll cany(const vector<int>& x) {
	return po2[x.size()]-1;
}
ll f(int t,const vector<int>& a,const vector<int>& b) {
	if(!a.size()||!b.size()) return 0;
//	cout<<t<<":"<<a<<","<<b<<" "<<(x&(1LL<<t))<<"h\n";
	if(t<0) return cany(a.size())*cany(b.size())%MOD;
	vector<int> a0,b0,a1,b1;
	for(auto x:a) if(x&(1LL<<t)) a1.pb(x); else a0.pb(x);
	for(auto x:b) if(x&(1LL<<t)) b1.pb(x); else b0.pb(x);
	ll ans=0;
	if(!(x&(1LL<<t))) {
		ans+=f(t-1,a0,b0)+f(t-1,a1,b1);
	}
	else {
		ans+=(f(t-1,a0,b1)+1
		+cany(a0)+cany(b1))
		*(f(t-1,a1,b0)+1
		+cany(a1)+cany(b0))-1
		-cany(a0)*cany(a1)
		-cany(b0)*cany(b1)
		-cany(a0)-cany(a1)
		-cany(b0)-cany(b1);
	}
	return ans%MOD;
}
int main()
{
	po2[0]=1;
	for(int i=1;i<SZ;++i)
		po2[i]=po2[i-1]*2%MOD;
//	n=1.5e5; x=1LL<<29;
	scanf("%d%lld",&n,&x);
	for(int i=1;i<=n;++i) {
//		a[i]=0;
//		a[i]=rand()*32768+rand();
		scanf("%lld",a+i);
//		for(int j=0;j<=35;++j)
//			suf[j][a[i]^(a[i]&((1LL<<j)-1))]++;
	}
//	cerr<<"+\n";
	int w=30;
	while(w>=0&&!(x&(1LL<<w))) --w;
	ll ans=0;
	map<ll,int> s;
	int ww=max(w,0);
	for(int i=1;i<=n;++i)
		s[a[i]^(a[i]&((1LL<<ww)-1))]++;
	for(auto u:s)
		ans+=cany(u.se);
//	cout<<w<<","<<ans<<"?\n";
	if(w>=0) {
		map<ll,pair<vector<int>,vector<int>>> sb;
		for(int i=1;i<=n;++i) {
			ll tp=a[i]^(a[i]&((1LL<<w)-1));
			if(tp&(1LL<<w)) sb[tp^(1LL<<w)].fi.pb(a[i]);
			else sb[tp].se.pb(a[i]);
		}
		for(auto&g:sb) ans+=f(w-1,g.se.fi,g.se.se);
	}
	ans=(ans%MOD+MOD)%MOD;
	cout<<ans<<"\n";
}