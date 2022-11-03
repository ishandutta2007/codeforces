/**
 *    author:  otera    
**/
#include<bits/stdc++.h>
using namespace std;

// #define int long long
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
    vector<string> v(n);
    vector<int> left(n, -1), right(n, -1);
    vector<bool> num(n);
    vector<int> parent(n, -1);
    rep(i, n) {
        cin >> v[i];
        if(v[i] == "NOT") {
            cin >> left[i]; -- left[i];
            parent[left[i]] = i;
        } else if(v[i] == "IN") {
            int val; cin >> val;
            num[i] = val;
        } else {
            cin >> left[i] >> right[i];
            -- left[i], -- right[i];
            parent[left[i]] = i, parent[right[i]] = i;
        }
    }
    auto dfs = [&](auto &&self, int i) -> void {
        if(v[i] == "IN") return;
        else if(v[i] == "NOT") {
            self(self, left[i]);
            num[i] = !num[left[i]];
        } else{
            self(self, left[i]);
            self(self, right[i]);
            if(v[i] == "AND") {
                num[i] = (num[left[i]] & num[right[i]]);
            } else if(v[i] == "OR") {
                num[i] = (num[left[i]] | num[right[i]]);
            } else if(v[i] == "XOR") {
                num[i] = (num[left[i]] ^ num[right[i]]);
            }
        }
    };
    dfs(dfs, 0);
    // rep(i, n) cerr << num[i] << " \n"[i == n - 1];
    vector<bool> ans(n);
    ans[0] = !num[0];
    auto ddfs = [&](auto &&self, int i) -> void {
        if(v[i] == "IN") return;
        else if(v[i] == "NOT") {
            ans[left[i]] = ans[i];
            self(self, left[i]);
        } else{
            if(v[i] == "AND") {
                ans[left[i]] = ((!num[left[i]] & num[right[i]]) == num[i] ? num[0] : ans[i]);
                ans[right[i]] = ((num[left[i]] & !num[right[i]]) == num[i] ? num[0] : ans[i]);
            } else if(v[i] == "OR") {
                ans[left[i]] = ((!num[left[i]] | num[right[i]]) == num[i] ? num[0] : ans[i]);
                ans[right[i]] = ((num[left[i]] | !num[right[i]]) == num[i] ? num[0] : ans[i]);
            } else if(v[i] == "XOR") {
                ans[left[i]] = ((!(num[left[i]]) ^ num[right[i]]) == num[i] ? num[0] : ans[i]);
                ans[right[i]] = ((num[left[i]] ^ !(num[right[i]])) == num[i] ? num[0] : ans[i]);
            }
            self(self, left[i]);
            self(self, right[i]);
        }
    };
    ddfs(ddfs, 0);
    // rep(i, n) {
    //     cerr << ans[i] << " \n"[i == n - 1];
    // }
    rep(i, n) {
        if(v[i] == "IN") {
            cout << ans[i];
        }
    }
    cout << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(20);
	//int t; cin >> t; rep(i, t)solve();
	solve();
    return 0;
}