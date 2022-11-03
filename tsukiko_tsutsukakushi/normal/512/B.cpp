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
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
#define fr first
#define sc second
#define all(c) c.begin(),c.end()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

ll gcd(ll a,ll b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}

int n;
vector<ll> l, c;

const ll INF = 1LL<<60;

void solve() {
	cin >> n;
    l.resize(n), c.resize(n);
    ll sum = 0;
    rep(i, n) {
        cin >> l[i];
        sum = gcd(sum, l[i]);
    }
    rep(i, n) {
        cin >> c[i];
    }
    if(sum != 1) {
        cout << -1 << "\n";
        return;
    }
    vector<ll> cand;
    rep(i, n) {
        for(int j = 1; j * j <= l[i]; ++ j) {
            if(l[i] % j == 0) {
                cand.push_back(j);
                if(j * j != l[i]) cand.push_back(l[i] / j);
            }
        }
    }
    sort(all(cand));
    cand.erase(unique(all(cand)), cand.end());
    int sz = (int)cand.size();
    vector<int> dp(sz, INF);
    rep(i, n) {
        int id = lower_bound(all(cand), l[i]) - cand.begin();
        chmin(dp[id], c[i]);
        rep(j, sz) {
            if(dp[j] == INF) continue;
            ll nxt = gcd(cand[j], l[i]);
            int nxtid = lower_bound(all(cand), nxt) - cand.begin();
            chmin(dp[nxtid], dp[j] + c[i]);
        }
    }
    cout << dp[0] << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//int t; cin >> t; rep(i, t)solve();
	solve();
    return 0;
}