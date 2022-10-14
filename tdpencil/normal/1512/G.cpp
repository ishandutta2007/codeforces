#include "bits/stdc++.h"
using namespace std;


#pragma GCC target("avx,avx2,fma")
typedef long long ll;


#define vt vector
const ll mod = 1e9 + 7;
const int mxA = 1e7;

ll lpf[mxA+2];
ll at[mxA+2];
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int xy=rng()%mxA;
set<pair<ll, ll>> res;
void prec() {
	for(int i = 1; i <= mxA; ++i) {
		at[i] = -1;
		for(int j = i; j <= mxA; j += i) {
			lpf[j] += i; 
		}
	}
	for(int i = 1; i <= mxA; ++i) {
		if(lpf[i] <= mxA) {
			if(at[lpf[i]] == -1) {
				at[lpf[i]] = i;
			}
		}
	}
	
	at[xy]=142842;
}
void solve() 
{
	int x; cin >> x;
	cout << at[x] << "\n";
}
int main() {

	ios_base::sync_with_stdio(false); cin.tie(0);
	prec();
    int t = 1, i = 1;
	cin >> t;
    while(t--) {
        // printf("Case #%d: ", i)
        solve();
        i++;
    }
}