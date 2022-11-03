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
	int n; cin >> n;
    vector<int> t(n);
    int j = -1;
    rep(i, n) {
        cin >> t[i];
    }
    rep(i, n) {
        if(t[i] == t[(i + 1) % n]) j = i;
    }
    if(count(all(t), t[0]) == n) {
        cout << 1 << endl;
        rep(i, n) {
            cout << 1 << " ";
        }
        cout << endl;
    } else if(n % 2 == 0) {
        cout << 2 << endl;
        rep(i, n) {
            if(i & 1) cout << 1 << " ";
            else cout << 2 << " ";
        }
        cout << endl;
    } else {
        if(j != -1) {
            cout << 2 << endl;
            vector<int> c(n);
            // c[j] = 1;
            // for(int i = j + 1; i < j + n; ++ i) {
            //     int k = i % n;
            //     if((i - j - 1) & 1) c[k] = 2;
            //     else c[k] = 1;
            // }
            for(int i = 0; i < j + 1; ++ i) {
                c[i] = 1 + i % 2;
            }
            for(int i = n - 1; i >= j + 1; -- i) {
                c[i] = 1 + (i + 1) % 2;
            }
            rep(i, n) {
                cout << c[i] << " ";
            }
            cout << endl;
        } else {
            cout << 3 << endl;
            int now = 1;
            cout << 3 << " ";
            rep(i, n - 1) {
                cout << 1 + i % 2 << " ";
            }
            cout << endl;
        }
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