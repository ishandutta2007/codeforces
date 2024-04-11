//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,ssse3,sse3,sse4,popcnt,tune=native")
#include<bits/stdc++.h>

using namespace std;

#define I(x, a) for(auto x : (a))
#define all(x) (x).begin(),(x).end()
#define F(i, l, r) for(auto i = (l); i < (r); i++)
#define DF(i, l, r) for(auto i = (l); i >= (r); i--)
#define E(i, l, r) for(auto i = (l); i <= (r); i++)
#define pb push_back
#define X first
#define Y second
#define mp make_pair
#define ret return
#define brk break
#define cont continue

typedef long long ll;
typedef long double dbl;
typedef pair<int, int> pii;
typedef unsigned long long ull;

ll kth(ll k, ll mod){
	ll A[2][2];
	ll R[2][2];
	R[0][0] = 1; R[0][1] = 0;
	R[1][0] = 0; R[1][1] = 1;
	A[0][0] = 0; A[0][1] = 1;
	A[1][0] = 1; A[1][1] = 1;
	while(k){
		if(k&1){
			ll t[2][2];
			F(i, 0, 2)F(j, 0, 2){t[i][j] = 0; F(k, 0, 2)t[i][j] += R[i][k] * A[k][j] % mod; t[i][j] %= mod;}
			F(i, 0, 2)F(j, 0, 2)R[i][j] = t[i][j];
		}
		ll t[2][2];
		F(i, 0, 2)F(j, 0, 2){t[i][j] = 0; F(k, 0, 2)t[i][j] += A[i][k] * A[k][j] % mod; t[i][j] %= mod;}
		F(i, 0, 2)F(j, 0, 2)A[i][j] = t[i][j];
		k >>= 1;
	}
	return R[0][1];
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll l, r, m, k;
	cin >> m >> l >> r >> k;
	ll x = r;
	ll best = 1;
	while(true){
		ll nxt = r/(r/x + 1);
		if((r/x) >= (l + x - 1)/x + k - 1){
			best = max(best, x);
		}
		if(r/x == r)break;
		if(nxt < 1)break;
		x = nxt;
	}
	cout << kth(best, m);
	return 0;
}