/**
 *    author:  otera    
**/
#include<bits/stdc++.h>
using namespace std;

#define int long long
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
    int n; cin >> n;
    vector<ll> a(2 * n);
    ll sum = 0;
    rep(i, 2 * n) {
        cin >> a[i];
        sum += a[i];
    }
    sort(all(a), greater<ll>());
    if(n == 1) {
        cout << "YES\n";
        cout << sum << "\n";
        cout << a[0] << " " << a[1] << "\n";
        return;
    }
    vector<bool> used(2 * n, 0);
    map<int, set<int>> mp;
    vector<P> ans;
    for(int j = 1; j < 2 * n; ++ j) {
        int x = a[0] + a[j];
        //cerr << a[0] << " " << a[j] << " " << x << "\n";
        used.assign(n, 0);
        ans.clear(); 
        mp.clear();
        used[0] = used[j] = 1;
        ans.push_back({a[0], a[j]});
        for(int k = 1; k < 2 * n; ++ k) {
            if(k == j) continue;
            mp[a[k]].insert(k);
        }
        bool ok = 1;
        int now = a[0];
        for(int k = 1; k < 2 * n; ++ k) {
            if(!used[k]) {
                mp[a[k]].erase(k);
                int b = now - a[k];
                used[k] = 1;
                if(mp[b].size()) {
                    int val = *mp[b].begin();
                    used[val] = 1;
                    ans.push_back({a[k], b});
                    mp[b].erase(val);
                    now = a[k];
                } else {
                    ok = 0;
                    break;
                }
            }
        }
        if(ok) {
            cout << "YES\n";
            cout << x << "\n";
            for(auto p: ans) {
                cout << p.fr << " " << p.sc << "\n";
            }
            return;
        }
    }
    cout << "NO\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(20);
	int t; cin >> t; rep(i, t)solve();
	// solve();
    return 0;
}