/**
 *    author:  otera    
**/
#include<bits/stdc++.h>
using namespace std;

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

void solve() {
	int n; cin >> n;
    vector<string> s(n);
    rep(i, n) {
        cin >> s[i];
    }
    const int MAX = 26;
    vector<vector<int>> g(MAX, vector<int>());
    vector<int> deg(MAX, 0);
    rep(i, n) {
        for(int j = i + 1; j < n; ++ j) {
            int sz = s[i].size(), sz1 = s[j].size();
            bool check = 0;
            rep(k, min(sz, sz1)) {
                if(s[i][k] != s[j][k]) {
                    int a = s[i][k] - 'a', b = s[j][k] - 'a';
                    g[a].push_back(b);
                    deg[b] ++;
                    check = 1;
                    break;
                }
            }
            if(!check) {
                if(sz > sz1) {
                    cout << "Impossible" << endl;
                    return;
                }
            }
        }
    }
    queue<int> que;
    vector<int> ans;
    rep(i, MAX) {
        if(deg[i] == 0) {
            que.push(i);
        }
    }
    while(que.size()) {
        int v = que.front(); que.pop();
        ans.push_back(v);
        for(int nv: g[v]) {
            -- deg[nv];
            if(deg[nv] == 0) {
                que.push(nv);
            }
        }
    }
    if((int)ans.size() != MAX) {
        cout << "Impossible" << endl;
    } else {
        for(auto i: ans) {
            cout << (char)('a' + i);
        }
        cout << "\n";
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