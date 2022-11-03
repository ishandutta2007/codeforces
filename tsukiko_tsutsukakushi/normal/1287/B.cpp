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
//#define int long long

void solve() {
	int n, k; cin >> n >> k;
    map<string, int> mp;
    vector<string> s(n);
    rep(i, n) {
        cin >> s[i];
        mp[s[i]] ++;
    }
    int ans = 0;
    // set<char> se;
    // se.insert('S');
    // se.insert('E');
    // se.insert('T');
    rep(i, n) {
        for(int j = i + 1; j < n; ++j) {
            string res;
            bool check = 1;
            rep(x, k) {
                // auto se1 = se;
                // se1.erase(s[i][x]);
                // se1.erase(s[j][x]);
                // if(se1.size() == 2) {
                //     res += s[i][x];
                // } else {
                //     res += *(se1.begin());
                //     check = 0;
                // }
                if(s[i][x] != s[j][x]) {
                    res += (s[i][x] == 'S' ? (s[j][x] == 'T' ? 'E' : 'T') : (s[i][x] == 'T' ? (s[j][x] == 'S' ? 'E' : 'S') : (s[j][x] == 'S' ? 'T' : 'S')));
                    check = 0;
                } else {
                    res += s[i][x];
                }
            }
            if(!check) {
                ans += mp[res];
            } else {
                ans += (mp[res] - 2);
            }
        }
    }
    cout << ans / 3 << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//init();
	//int t; cin >> t; rep(i, t)solve();
	solve();
	//cout << "finish" << endl;
    return 0;
}