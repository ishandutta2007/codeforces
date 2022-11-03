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
    int d; cin >> d;
    int k; cin >> k;
    // vector<vector<int>> g(d + 1, vector<int>(d + 1, -1));
    // for(int i = 0; i <= d; i += k) {
    //     for(int j = (d / k) * k; j >= 0; j -= k) {
    //         if(i * i + j * j <= d * d) {
    //             g[i][j] = -2;
    //         }
    //     }
    // }
    // auto rec = [&](auto&& self, int i, int j) -> int {
    //     if(i * i + j * j > d * d) {
    //         return g[i][j] = -1;
    //     }
    //     if(g[i][j] != -1 and g[i][j] != -2) return g[i][j];
    //     // if(j + k > d or i + k > d) return g[i][j] = 0;
    //     if(j + k <= d and self(self, i, j + k) == 0) return g[i][j] = 1;
    //     if(i + k <= d and self(self, i + k, j) == 0) return g[i][j] = 1;
    //     if(j + k <= d and self(self, i, j + k) == -1) return g[i][j] = 0;
    //     if(i + k <= d and self(self, i + k, j) == -1) return g[i][j] = 0;
    //     return g[i][j] = 0;
    // };
    // for(int i = 0; i <= d; i += k) {
    //     for(int j = 0; j <= d; j += k) {
    //         cerr << rec(rec, i, j) << " ";
    //     }
    //     cerr << endl;
    // }
    int j = 0;
    for(int i = 0; i <= d; i += k) {
        if(i * i + i * i <= d * d) {
            j = i;
        }
    }
    // cerr << j << endl;
    if(j * j + (j + k) * (j + k) <= d * d) {
        // 1
        cout << "Ashish\n"; 
    } else {
        // 0
        cout << "Utkarsh\n";
    }
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(20);
	int t; cin >> t; rep(i, t)solve();
	// solve();
    return 0;
}