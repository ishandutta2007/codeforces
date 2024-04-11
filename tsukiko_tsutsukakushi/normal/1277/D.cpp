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
    int cnt00 = 0, cnt01 = 0, cnt10 = 0, cnt11 = 0;
    set<int> se00, se01, se10, se11;
    map<int, string> mp;
    set<string> se;
    rep(i, n) {
        string s; cin >> s;
        se.insert(s);
        mp[i] = s;
        int sz = (int)s.size();
        int ini = s[0] - '0', fin = s[sz - 1] - '0';
        if(ini == 0) {
            if(fin == 0) ++cnt00, se00.insert(i);
            else ++cnt01, se01.insert(i);
        } else {
            if(fin == 0) ++cnt10, se10.insert(i);
            else ++cnt11, se11.insert(i);
        }
    }
    if(cnt01 == 0 && cnt10 == 0) {
        if(cnt00 > 0 && cnt11 > 0) {
            cout << -1 << endl;
            return;
        } else {
            cout << 0 << endl << endl;
            return;
        }
    } else {
        //cnt01, cnt10ok
        if(abs(cnt01 - cnt10) <= 1) {
            cout << 0 << endl << endl;
            return;
        }
        if(cnt01 > cnt10) {
            int cnt = (cnt01 - cnt10) / 2;
            int cnt_ = cnt;
            set<int> ans;
            for(auto v: se01) {
                if(cnt == 0) break;
                string t = mp[v];
                reverse(all(t));
                if(se.find(t) != se.end()) continue;
                ans.insert(v + 1);
                --cnt;
            }
            if(cnt > 0) {
                cout << -1 << endl;
            }
            cout << cnt_ << endl;
            for(auto v: ans) cout << v << " ";
            cout << endl;
        } else {
            int cnt = (cnt10 - cnt01) / 2;
            int cnt_ = cnt;
            set<int> ans;
            for(auto v: se10) {
                if(cnt == 0) break;
                string t = mp[v];
                reverse(all(t));
                if(se.find(t) != se.end()) continue;
                ans.insert(v + 1);
                --cnt;
            }
            if(cnt > 0) {
                cout << -1 << endl;
            }
            cout << cnt_ << endl;
            for(auto v: ans) cout << v << " ";
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