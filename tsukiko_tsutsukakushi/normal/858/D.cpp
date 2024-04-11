/**
 *    author:  otera    
**/
#include<iostream>
#include<string>
#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<deque>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<complex>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
#include<cassert>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ul;
typedef unsigned int ui;
typedef long double ld;
const int inf=1e9+7;
const ll INF=1LL<<60 ;
const ll mod=1e9+7 ;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef complex<ld> Point;
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<int, int> P;
typedef pair<ld, ld> LDP;
typedef pair<ll, ll> LP;
#define fr first
#define sc second
#define all(c) c.begin(),c.end()
#define pb push_back
#define debug(x)  cerr << #x << " = " << (x) << endl;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
 
// 
//  LCP 
struct RollingHash {
    static const int base1 = 10;
    vector<int> hash1, power1;
    // construct
    RollingHash(const string &S) {
        int n = (int)S.size();
        hash1.assign(n+1, 0);
        power1.assign(n+1, 1);
        for (int i = 0; i < n; ++i) {
            hash1[i+1] = hash1[i] * base1 + S[i];
            power1[i+1] = power1[i] * base1;
        }
    }
    
    // get hash of S[left:right)
    inline int get(int l, int r) const {
        int res1 = hash1[r] - hash1[l] * power1[r-l];
        return res1;
    }
};
 
void solve() {
	int n; cin >> n;
    vector<string> p(n);
    unordered_map<string, int> mp;
    unordered_map<string, int> mp1[70070];
    rep(i, n) {
        cin >> p[i];
        RollingHash rhp(p[i]);
        for(int j = 0; j < 9; ++ j) {
            for(int k = 1; k <= 9 - j; ++ k) {
                string q = p[i].substr(j, k);
                mp[q] ++;
                mp1[i][q] ++;
                //cerr << q << endl;
                //mp[rhp.get(j, j + k)] ++;
                //mp1[i][rhp.get(j, j + k)] ++;
            }
        }
    }
    rep(i, n) {
        int ans = 9;
        string res = p[i];
        RollingHash rhp(p[i]);
        // for(int j = 0; j < 9; ++ j) {
        //     for(int k = 1; k <= 9 - j; ++ k) {
        //         //string q = p[i].substr(j, k);
        //         //cerr << q << endl;
        //         if(mp[rhp.get(j, j + k)] == mp1[i][rhp.get(j, j + k)]) {
        //             if(chmin(ans, k)) {
        //                 res = p[i].substr(j, k);
        //             }
        //         }
        //     }
        // }
        for(auto x: mp1[i]) {
            if(mp[x.fr] == x.sc) {
                if(chmin(ans,(int) x.fr.size())) {
                    res = x.fr;
                }
            }
        }
        cout << res << endl;
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