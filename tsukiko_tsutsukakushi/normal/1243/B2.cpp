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

void solveeasy() {
	int n; string s, t;
    cin >> n >> s >> t;
    int cnt = 0; set<int> se;
    rep(i, n) {
        if(s[i] != t[i]) {
            ++ cnt;
            se.insert(i);
        }
    }
    if(cnt != 2) {
        cout << "No" << endl;
    } else {
        auto ite = se.begin();
        int i = *ite;
        ite ++;
        int j = *ite;
        if(s[i] == s[j] && t[i] == t[j]) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}

void solvedif() {
    int n; string s, t;
    cin >> n >> s >> t;
    map<int, int> mp;
    rep(i, n) {
        int cs = s[i] - 'a';
        int ct = t[i] - 'a';
        mp[cs] ++, mp[ct] ++;
    }
    for(int i = 0; i < 26; ++ i) {
        if(mp[i] % 2 != 0) {
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
    vector<P> ans;
    rep(i, n) {
        if(s[i] == t[i]) continue;
        bool ok = 0;
        for(int j = i + 1; j < n; ++ j) {
            if(s[i] == s[j]) {
                ans.pb({j, i});
                swap(s[j], t[i]);
                ok = 1;
                break;
            }
        }
        if(ok) continue;
        for(int j = i + 1; j < n; ++ j) {
            if(s[i] == t[j]) {
                ans.pb({j, j});
                swap(s[j], t[j]);
                ans.pb({j, i});
                swap(s[j], t[i]);
                break;
            }
        }
    }
    cout << (int)ans.size() << endl;
    for(auto p: ans) {
        cout << p.fr + 1 << " " << p.sc + 1 << endl;
    }
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	int t; cin >> t; rep(i, t)solvedif();
	//solve();
    return 0;
}