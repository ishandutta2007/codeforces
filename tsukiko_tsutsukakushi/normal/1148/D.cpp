/**
 *    author:  otera    
**/
#include<bits/stdc++.h>
using namespace std;

#define int long long
typedef long long ll;
typedef long double ld;
#define rep(i, n) for(int i = 0; i < n; ++ i)
#define per(i,n) for(int i=n-1;i>=0;i--)
typedef pair<int, pair<int, int>> P2;
typedef pair<ll, ll> LP;
#define fr first
#define sc second
#define all(c) c.begin(),c.end()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

void solve() {
    int n; cin >> n;
    vector<int> a(n), b(n);
    vector<P2> cand1, cand2;
    int co1 = 0, co2 = 0;
    rep(i, n) {
        cin >> a[i] >> b[i];
        if(a[i] < b[i]) {
            ++ co1;
            cand1.push_back({i, {a[i], b[i]}});
        }
        else {
            ++ co2;
            cand2.push_back({i, {a[i], b[i]}});
        }
    }
    if(co1 >= co2) {
        cout << co1 << endl;
        sort(all(cand1), [&](P2 x, P2 y){ return x.sc.sc > y.sc.sc;});
        rep(i, co1) {
            cout << cand1[i].fr + 1 << " \n"[i == co1 - 1];
        }
    } else {
        cout << co2 << endl;
        sort(all(cand2), [&](P2 x, P2 y){ return x.sc.fr < y.sc.fr;});
        rep(i, co2) {
            cout << cand2[i].fr + 1 << " \n"[i == co2 - 1];
        }
    }
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//int t; cin >> t; rep(i, t)solve();
	solve();
    return 0;
}