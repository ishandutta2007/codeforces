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

//#define int long long
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

char f(int k) {
    if(0 <= k && k < 26) {
        return ('a' + k);
    } else if(26 <= k && k < 52) {
        return ('A' + (k - 26));
    } else {
        return ('0' + k - 52);
    }
}

void solve() {
	int r, c, k; cin >> r  >> c >> k;
    vector<vector<char>> field(r, vector<char>(c));
    int sum = 0;
    rep(i, r) {
        rep(j, c) {
            cin >> field[i][j];
            if(field[i][j] == 'R') ++ sum;
        }
    }
    int co1 = sum % k, co2 = k - co1;
    int now = 0, cnt = co2, co = 0;
    vector<vector<char>> ans(r, vector<char>(c));
    rep(i, r) {
        if(i % 2 == 0) {
            rep(j, c) {
                ans[i][j] = f(now);
                if(field[i][j] == 'R') ++ co;
                if(co == sum / k && cnt > 0) {
                    -- cnt;
                    co = 0;
                    ++ now;
                } else if(co == sum / k + 1) {
                    ++ now;
                    co = 0;
                }
                if(now >= k) {
                    -- now;
                }
            }
        } else {
            per(j, c) {
                ans[i][j] = f(now);
                if(field[i][j] == 'R') ++ co;
                if(co == sum / k && cnt > 0) {
                    -- cnt;
                    co = 0;
                    ++ now;
                } else if(co == sum / k + 1) {
                    ++ now;
                    co = 0;
                }
                if(now >= k) {
                    -- now;
                }
            }
        }
        rep(j, c) {
            cout << ans[i][j];
        }
        cout << endl;
    }
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	int t; cin >> t; rep(i, t)solve();
	//solve();
    return 0;
}