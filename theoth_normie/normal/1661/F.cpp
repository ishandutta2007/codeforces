#ifndef CPL_TEMPLATE
#define CPL_TEMPLATE
/*
	Normie's Template v2.5
	Changes:
    Added warning against using pragmas on USACO.
*/
// Standard library in one include.
#include <bits/stdc++.h>
using namespace std;
 
// ordered_set library.
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// #define ordered_set(el) tree<el,null_type,less<el>,rb_tree_tag,tree_order_statistics_node_update>
 
// AtCoder library. (Comment out these two lines if you're not submitting in AtCoder.) (Or if you want to use it in other judges, run expander.py first.)
//#include <atcoder/all>
//using namespace atcoder;

//Pragmas (Comment out these three lines if you're submitting in szkopul or USACO.)
// #pragma comment(linker, "/stack:200000000")
// #pragma GCC optimize("Ofast,unroll-loops,tree-vectorize")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
 
//File I/O.
#define FILE_IN "cseq.inp"
#define FILE_OUT "cseq.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
 
//Fast I/O.
#define fio ios::sync_with_stdio(0);cin.tie(0)
#define nfio cin.tie(0)
#define endl "\n"
 
//Order checking.
#define ord(a,b,c) ((a>=b)and(b>=c))
 
//min/max redefines, so i dont have to resolve annoying compile errors.
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

// Fast min/max assigns to use with AVX.
// Requires g++ 9.2.0.
// template<typename T>
// __attribute__((always_inline)) void chkmin(T& a, const T& b) {
//     a=(a<b)?a:b;
// }

// template<typename T>
// __attribute__((always_inline)) void chkmax(T& a, const T& b) {
//     a=(a>b)?a:b;
// }
 
//Constants.
#define MOD (ll(998244353))
#define MAX 300001
#define mag 320
const long double PI=3.14159265358979;
 
//Pairs and 3-pairs.
#define p1 first
#define p2 second.first
#define p3 second.second
#define fi first
#define se second
#define pii(element_type) pair<element_type,element_type>
#define piii(element_type) pair<element_type,pii(element_type)>
 
//Quick power of 2.
#define pow2(x) (ll(1)<<x)
 
//Short for-loops.
#define ff(i,__,___) for(int i=__;i<=___;i++)
#define rr(i,__,___) for(int i=__;i>=___;i--)
 
//Typedefs.
#define bi BigInt
typedef long long ll;
typedef long double ld;
typedef short sh;

// Binpow and stuff
ll BOW(ll a, ll x, ll p)
{
	if (!x) return 1;
	ll res=BOW(a,x/2,p);
	res*=res;
	res%=p;
	if (x%2) res*=a;
	return res%p;
}
ll INV(ll a, ll p)
{
	return BOW(a,p-2,p);
}
//---------END-------//
#endif
vector<int> vec;
ll n,m,i,j,k,t,t1,u,v,a,b,l,r,mid,cnt;
ll arr[200001];
ll check(ll x) {
	ll l,r,mid;
	ll u,v;
	ll d,rem;
	ll sum=0;
	cnt=0;
	for (i=1;i<=n;i++) {
		l=1;
		r=arr[i];
		while(l<r) {
			mid=(l+r)/2+1;
			d=arr[i]/mid;
			rem=arr[i]-d*mid;
			u=d*d*(mid-rem)+(d+1)*(d+1)*rem;
			mid--;
			d=arr[i]/mid;
			rem=arr[i]-d*mid;
			v=d*d*(mid-rem)+(d+1)*(d+1)*rem;
			mid++;
			if (v-u<x) r=mid-1; else l=mid;
		}
		d=arr[i]/l;
		rem=arr[i]-d*l;
		sum+=d*d*(l-rem)+(d+1)*(d+1)*rem;
		cnt+=l-1;
	}
	return sum;
}
int main()
{
	fio;
	cin>>n;
	for (i=1;i<=n;i++) {
		cin>>arr[i];
	}
	u=0; 
	for (i=n;i>=1;i--) arr[i]=arr[i]-arr[i-1];
	for (i=1;i<=n;i++) {
		u+=arr[i]*arr[i];
	}
	cin>>m;	
	if (m>=u) {
		return cout<<0,0;
	}
	r=1e18;
	l=0;
	while(l<r) {
		mid=(l+r)/2;
		if (check(mid)<=m) {
			l=mid+1;
		}
		else {
			r=mid;
		}
	}
	u=check(l);
	cnt+=ceil(ld(u-m)/(l-1));
	cout<<cnt;
}