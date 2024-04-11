#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 2e5, M = 1e9+7;
// #define runcase LOL

void solve(int test_case = 0)
{
    // brute force all good digits
    vector<ll> good;
    for(int iter = 2; iter <= 12; iter += 2) {
		vector<string> res;
		for(int i = 0; i < (1<<iter); i++) {
			string v;
			int cnt1 = 0, cnt2 = 0;
			for(int j = 0; j < iter; j++) {
				if(i&(1<<j)) {
					v += '4';
					cnt1++;
				} else {
					v += '7';
					cnt2++;
				}
			}
			if(cnt1 == cnt2) res.push_back(v);
		}
		for(string &j : res) {
			if(!j.empty()) {
				good.push_back(stoll(j));
			}
		}
	}
	
	int n; cin >> n;
	ll mx = 1e18;
	for(ll i : good)  {
		if(i>=n) {
			mx=min(mx, i);
		}
	}
	cout << mx << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T = 1;
#ifdef runcase
    cin >> T;
#endif

    for(int nt = 0, i; nt < T; nt++) {
        solve(nt);
        ++i;
    }
}