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
	int n; cin >> n;
    vector<int> c(n);
    rep(i, n) {
        cin >> c[i];
    }
    if(n == 1) {
        cout << 0 << endl;
        return;
    }
    vector<vector<int>> ans;
    rep(i, n - 1) {
        // n - i
        int pos = -1;
        rep(j, n) {
            if(c[j] == n - i) {
                pos = j;
            }
        }
        if(i == 0) {
            if(pos == 0 or pos == n - 1) continue;
            else {
                vector<int> d = {pos, n - pos};
                ans.push_back(d);
                vector<int> nxtc(n);
                for(int j = pos; j < n; ++ j) {
                    nxtc[j - pos] = c[j];
                }
                for(int j = 0; j < pos; ++ j) {
                    nxtc[j + n - pos] = c[j];
                }
                swap(c, nxtc);
            }
        } else if(i != n - 2) {
            vector<int> d;
            if(c[0] == n) {
                rep(j, i) d.push_back(1);
                if(pos == i) {
                    // d = {i, n - i};
                    d.push_back(1);
                    d.push_back(n - i - 1);
                } else {
                    // d = {i, pos, n - i - pos};
                    d.push_back(pos + 1 - i);
                    if(pos + 1 != n) d.push_back(n - pos - 1);
                }
                ans.push_back(d);
            } else {
                if(pos == 0) {
                    // d = {n - i, i};
                    d.push_back(n - i);
                } else {
                    // d = {pos, n - i - pos, i};
                    d.push_back(pos);
                    if(n - i - pos != 0) d.push_back(n - i - pos);
                }
                rep(j, i) d.push_back(1);
                ans.push_back(d);
            }
            int cur = n - 1;
            int sz = (int)d.size();
            vector<int> nxtc;
            per(i, sz) {
                for(int j = cur - d[i] + 1; j <= cur; ++ j) {
                    nxtc.push_back(c[j]);
                }
                cur -= d[i];
            }
            swap(c, nxtc);
        } else if(i == n - 2) {
            vector<int> d;
            if(c[0] == n) {
                rep(j, i) d.push_back(1);
                if(pos == i) {
                    continue;
                } else {
                    d.push_back(2);
                }
                ans.push_back(d);
            } else {
                if(pos == 0) {
                    d.push_back(2);
                } else {
                    continue;
                }
                rep(j, i) d.push_back(1);
                ans.push_back(d);
            }
            int cur = n - 1;
            int sz = (int)d.size();
            vector<int> nxtc;
            per(i, sz) {
                for(int j = cur - d[i] + 1; j <= cur; ++ j) {
                    nxtc.push_back(c[j]);
                }
                cur -= d[i];
            }
            swap(c, nxtc);
        }
        // cerr << i << endl;
        // rep(j, n) {
        //     cerr << c[j] << " \n"[j == n - 1];
        // }
    }
    if(c[0] == n) {
        vector<int> d(n, 1);
        ans.push_back(d);
        reverse(all(c));
    }
    cout << (int)ans.size() << endl;
    for(auto x: ans) {
        cout << (int)x.size() << " ";
        for(int y: x) {
            cout << y << " ";
        }
        cout << endl;
    }
        //     rep(j, n) {
        //     cerr << c[j] << " \n"[j == n - 1];
        // }
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//int t; cin >> t; rep(i, t)solve();
	solve();
    return 0;
}