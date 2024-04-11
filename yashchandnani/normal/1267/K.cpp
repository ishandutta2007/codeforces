#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); ++i)
#define repA(i, a, n) for(int i = a; i <= (n); ++i)
#define repD(i, a, n) for(int i = a; i >= (n); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define fill(a) memset(a, 0, sizeof (a))
#define fst first
#define snd second
#define mp make_pair
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll ncr[30][30];

ll ncrr(ll n, ll r){
	if(n <= 0) return 0;
	r = min(r,n-r);
	if(r == 1) return n;
	if(r == 0) return 1;
	if(ncr[n][r] != -1) return ncr[n][r];
	ncr[n][r] = ncrr(n-1,r-1) + ncrr(n-1,r);
	return ncr[n][r];
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	rep(i,30) rep(j,30) ncr[i][j] = -1;
	int t; cin >> t;
	while(t--){
		ll k; cin >> k;
		vi rem; 
		repA(i,2,100){
			if(k == 0) break;
			rem.pb(k%i);
			k /= i;
		}
		sort(all(rem));
		reverse(all(rem));
		int m = sz(rem);
		ll ans1 = 1;
		ll ans2 = 0;
		rep(i,m){
			int cc = 1; int u = i;
			while(i+1 < m && rem[i] == rem[i+1]){
				i++;
				cc++;
			}
			ans1 = ans1*ncrr(m-u-rem[i]+1 - (rem[i] == 0) , cc);
		}
		if(rem.back() == 0){
			ans2 = 1;
			rep(i,m-1){
				int cc = 1; int u = i;
				while(i+1 < m-1 && rem[i] == rem[i+1]){
					i++;
					cc++;
				}
				ans2 = ans2*ncrr(m-u-rem[i]-(rem[i] == 0), cc);
			}
		}
		cout << ans1 - ans2 - 1<< endl;
	}
	return 0;
}