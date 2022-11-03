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
#include<unordered_set>
#include<utility>
#include<cassert>
#include<array>
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
	int n, k; string s; cin >> n >> k >> s;
    vector<P> ans;
    rep(i, k - 1) {
        if(s[2 * i] == ')') {
            for(int j = 2 * i + 1; j < n; ++ j) {
                if(s[j] == '(') {
                    // cerr << s[2 * i] << " " << s[j] << endl;
                    ans.push_back({2 * i, j});
                    reverse(s.begin() + 2 * i, s.begin() + j + 1);
                    break;
                }
            }
        }
        if(s[2 * i + 1] == '(') {
            for(int j = 2 * i + 2; j < n; ++ j) {
                if(s[j] == ')') {
                    // cerr << s[2 * i + 1] << " " << s[j] << endl;
                    ans.push_back({2 * i + 1, j});
                    reverse(s.begin() + 2 * i + 1, s.begin() + j + 1);
                    break;
                }
            }
        }
    }
    // cerr << s << endl;
    for(int i = 2 * (k - 1); i < 2 * (k - 1) + n / 2 - (k - 1); ++ i) {
        if(s[i] == '(') continue;
        for(int j = i + 1; j < n; ++ j) {
            if(s[j] == '(') {
                    ans.push_back({i, j});
                    reverse(s.begin() + i, s.begin() + j + 1);
                    break;
                }
        }
    }
    // cerr << s << endl;
    cout << (int)ans.size() << endl;
    for(auto p: ans) {
        cout << p.fr + 1 << " " << p.sc + 1 << endl;
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