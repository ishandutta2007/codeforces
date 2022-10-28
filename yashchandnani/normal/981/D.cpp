#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;

#define rep(i, n)    for(int i = 0; i < (n); ++i)
#define repA(i, a, n)  for(int i = a; i <= (n); ++i)
#define repD(i, a, n)  for(int i = a; i >= (n); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define fill(a)  memset(a, 0, sizeof (a))
#define fst first
#define snd second
#define mp make_pair
#define pb push_back
typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<ll> vi;

void pre(){


}
vector<ll> a,p;
int dp[59][59];
bool chk(ll x,int n,int k){
	if(k==1&&n!=0) if((p[n]&x)==x) {
		dp[n][k] = 1;return true;
	}
	if(k==1) return false;
	if(dp[n][k]==1) return 1;
	if(dp[n][k]==-1) return 0;
	ll s =0;
	repD(i,n-1,0){
		s+=a[i];
		if((s&x)==x) if(chk(x,i,k-1)) {
			dp[n][k]=1;return true;
		}
	}
	dp[n][k] = -1;
	return false;
}
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();
	int n,k;cin>>n>>k;
	a.resize(n);p.resize(n+1,0);
	rep(i,n) cin>>a[i],p[i+1] = p[i]+a[i];
	if(k==1){
		ll sum = 0;
		trav(i,a) sum+=i;
		cout<<sum;return 0;
	}
	if(n==1){
		cout<<a[0];return 0;
	}
	ll res = 0;
	repD(i,60,0){
		ll z = (1ll<<i);
		fill(dp);
		if(chk(res|z,n,k)) res = res|z;
	}
	cout<<res;
	return 0;
}