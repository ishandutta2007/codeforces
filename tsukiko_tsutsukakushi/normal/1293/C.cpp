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

void solve() {
	int n, q; cin >> n >> q;
    vector<vector<int>> check(2, vector<int>(n, 1));
    set<int> se;
    function<bool(int)> can_move = [&](int x) {
        //x -> x + 1
        if(!check[0][x + 1] && !check[1][x + 1]) {
            return false;
        } else if(!check[0][x] && !check[1][x]) {
            return false;
        } else if(!check[0][x] && !check[1][x + 1]) {
            return false;
        } else if(!check[1][x] && !check[0][x + 1]) {
            return false;
        } else {
            return true;
        }
    };
    rep(i, q) {
        int x, y; cin >> x >> y;
        --x; --y;
        //cerr << check[x][y] << endl;
        check[x][y] = 1 - check[x][y];
        //cerr << check[x][y] << endl;
        if(y >= 1 && y < n) {
            if(can_move(y - 1)) {
                if(se.find(y - 1) != se.end()) {
                    se.erase(y - 1);
                }
            } else {
                se.insert(y - 1);
            }
        }
        if(y + 1 < n) {
            if(can_move(y)) {
                if(se.find(y) != se.end()) {
                    se.erase(y);
                }
            } else {
                se.insert(y);
            }
        }
        
        //cerr << se.size() << endl;
        if(se.empty()) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
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