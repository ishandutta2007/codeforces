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

#define int long long
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

void solve() {
	int n, m; cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    rep(i, n) {
        rep(j, m) {
            cin >> a[i][j];
        }
    }
    int x, y;
    function<bool(int)> check = [&](int X) {
        vector<int> mask(1<<m, -1);
        rep(i, n) {
            int bit = 0;
            rep(j, m) {
                if(a[i][j] >= X) {
                    bit += (1<<j);
                }
            }
            mask[bit] = i;
        }
        rep(i, 1<<m) {
            rep(j, 1<<m) {
                if(mask[i] != -1 && mask[j] != -1) {
                    if((i | j) == (1<<m) - 1) {
                        x = mask[i];
                        y = mask[j];
                        return true;
                    }
                }
            }
        }
        return false;
    };
    int ok = -1, ng = INF;
    while(ng - ok > 1) {
        int mid = (ok + ng) / 2;
        if(check(mid)) {
            //cerr << x << " " << y << endl;
            ok = mid;
        } else {
            ng = mid;
        }
    }
    //cerr << ok << endl;
    cout << x + 1 << " " << y + 1 << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//int t; cin >> t; rep(i, t)solve();
	solve();
    return 0;
}