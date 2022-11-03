/**
 *    author:  otera    
**/
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const int inf=1e9+7;
const ll INF=1LL<<60;
#define rep(i, n) for(int i = 0; i < n; ++ i)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
#define fr first
#define sc second
#define all(c) c.begin(),c.end()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

void solve() {
    int n, I; 
    cin >> n >> I; 
    // n = rand() % 100, I = rand() % 1000;
    I *= 8;
    vector<int> a(n);
    rep(i, n) {
        cin >> a[i];
        // a[i] = rand() % 1000;
    }
    auto coma = a;
    sort(all(coma));
    coma.erase(unique(all(coma)), coma.end());
    int m = (int)coma.size();
    vector<int> cnt(m, 0);
    rep(i, n) {
        int val = lower_bound(all(coma), a[i]) - coma.begin();
        cnt[val] ++;
    }
    vector<int> sum(m + 1, 0);
    rep(i, m) {
        sum[i + 1] = sum[i] + cnt[i];
    }
    int k = min(I / n, 30);
    int K = (1LL<<k);
    // cerr << I << " " << n << "\n";
    // cerr << k << "\n";
    if(K >= m) {
        cout << 0 << "\n";
        return;
    }
    int ans = inf;
    // cerr << K << "\n";
    for(int l = 0; l <= m - K; ++ l) {
        // cerr << sum[l] << " " << sum[m] << " " << sum[l + K] << "\n"; 
        chmin(ans, sum[l] + sum[m] - sum[l + K]);
    }
    cout << ans << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(20);
	//int t; cin >> t; rep(i, t)solve();
	solve();
    return 0;
}