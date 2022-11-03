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

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> s(n, vector<int>(m));
    rep(i, n) {
        rep(j, m) {
            char c; cin >> c;
            s[i][j] = c - '0';
        }
    }
    vector<vector<P>> ans;
    vector<P> ones, zeros;
    auto op = [&](vector<P> res) {
        assert(res.size() == 3);
        for(auto p: res) {
            s[p.fr][p.sc] ^= 1;
        }
    };
    auto f4 = [&](auto&& self,int i, int j) -> void {
        ones.clear(), zeros.clear();
        rep(k, 2) {
            rep(l, 2) {
                // cerr << s[i + k][j + l] << " "; 
                if(s[i + k][j + l] == 0) zeros.push_back({i + k, j + l});
                else ones.push_back({i + k, j + l});
            }
        }
        // cerr << zeros.size() << " " << ones.size() << " ";
        // cerr << endl;
        vector<P> res;
        if(ones.empty()) return;
        else if(ones.size() == 3) {
            rep(k, 3) res.emplace_back(ones[k]);
            ans.push_back(res);
            op(res);
            self(self, i, j);
        } else if(ones.size() == 2) {
            rep(k, 1) res.emplace_back(ones[k]);
            rep(k, 2) res.emplace_back(zeros[k]);
            ans.push_back(res);
            op(res);
            self(self, i, j);
        } else if(ones.size() == 1) {
            rep(k, 1) res.emplace_back(ones[k]);
            rep(k, 2) res.emplace_back(zeros[k]);
            ans.push_back(res);
            op(res);
            self(self, i, j);
        } else if(ones.size() == 4) {
            rep(k, 3) res.emplace_back(ones[k]);
            ans.push_back(res);
            op(res);
            self(self, i, j);
        }
        return;
    };
    auto f1 = [&](int i, int j, int k, int l, int nk, int nl) { 
        if(s[k][l] == 0 and s[nk][nl] == 0) return;
        vector<P> res;
        if(s[nk][nl] == 1) res.emplace_back(nk, nl);
        if(s[k][l] == 1) res.emplace_back(k, l);
        // cerr << i << " " << j << endl;
        rep(x, 2) {
            rep(y, 2) {
                int nx = i + x, ny = j + y;
                // cerr << nx << " " << ny << endl;
                if((nx != k or ny != l) and (nx != nk or ny != nl)) {
                    if((int)res.size() < 3) {
                        // cerr << nx << " " << ny << endl;
                        res.emplace_back(nx, ny);
                    }
                }
            }
        }
        ans.push_back(res);
        op(res);
        return;
    };
    rep(i, n - 1) {
        if(i % 2 == 0) {
            rep(j, m - 1) {
                if(j != m - 2) {
                    f1(i, j, i, j, i + 1, j);
                } else {
                    if(i == n - 2) {
                        f4(f4, i, j);
                    } else {
                        f1(i, j, i, j, i, j + 1);
                    }
                }
            }
        } else {
            for(int j = m - 2; j >= 0; -- j) {
                if(j != 0) {
                    f1(i, j, i, j + 1, i + 1, j + 1);
                } else {
                    if(i == n - 2) {
                        f4(f4, i, j);
                    } else {
                        f1(i, j, i, j, i, j + 1);
                    }
                }
            }
        }
    }
    rep(i, n) {
        rep(j, m) {
            assert(s[i][j] == 0);
        }
    }
    assert((int)ans.size() <= n * m);
    cout << (int)ans.size() << "\n";
    rep(i, (int)ans.size()) {
        rep(j, 3) {
            cout << ans[i][j].fr + 1 << " " << ans[i][j].sc + 1 << " \n"[j == 2];
        }
    }
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	int t; cin >> t; rep(i, t)solve();
	// solve();
    return 0;
}