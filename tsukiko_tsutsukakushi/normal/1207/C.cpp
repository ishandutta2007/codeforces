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
	int n, a, b; cin >> n >> a >> b;
    string s; cin >> s;
    int ans = b;
    for(int i = 0; i < n - 1;) {
        if(s[i] == '0' && s[i + 1] == '0') {
            if(i == n - 2) {
                ans += 2 * (a + b);
                cout << ans << endl;
                return;
            }
            ans += a + b;
            ++i;
            continue;
        } else if(s[i] == '0' && s[i + 1] == '1') {
            ans += 2 * a + 2 * b;
            ++i;
            continue;
        } else {
            //s[i] == '1'
            if(s[i] == '1' && s[i + 1] == '1') {
                ans += a + 2 * b;
                ++i;
                continue;
            } else if(s[i + 1] == '0') {
                int j = i + 1;
                while(j < n && s[j] == '0') {
                    ++j;
                }
                if(j == n) {
                    ans += a + 2 * b + 2 * a + b + (a + b) * (n - i - 2);
                    cout << ans << endl;
                    return;
                }
                if(2 * a - b * (j - i - 2) > 0) {
                    ans += (a + 2 * b) * (j - i);
                    i = j;
                    continue;
                } else {
                    ans += (a + 2 * b) * (j - i) + 2 * a - b * (j - i - 2);
                    i = j;
                    continue;
                }
            }
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