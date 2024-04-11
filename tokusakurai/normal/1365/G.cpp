#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
#define sp(x) fixed << setprecision(x)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
const int inf = (1<<30)-1;
const ll INF = (1LL<<60)-1;
const ld EPS = 1e-10;
template<typename T> bool chmax(T &x, const T &y) {return (x < y)? (x = y, true) : false;};
template<typename T> bool chmin(T &x, const T &y) {return (x > y)? (x = y, true) : false;};

int main(){
    int N;
    cin >> N;
    vector<vector<int>> perm[7];
    rep(i, 13){
        vector<int> v;
        v.pb(i);
        perm[1].pb(v);
    }
    rep2(i, 1, 5){
        for(auto &e: perm[i]){
            rep2(j, e.back()+1, 12){
                vector<int> v = e;
                v.pb(j);
                perm[i+1].pb(v);
            }
        }
    }
    vector<int> q[13];
    bool used[N][13];
    fill(used[0], used[N], false);
    rep(i, N){
        for(auto &e: perm[6][i]) q[e].pb(i), used[i][e] = true;
    }
    vector<ll> res(13, 0);
    rep(i, 13){
        if(q[i].empty()) break;
        cout << "? " << sz(q[i]) << ' ';
        for(auto &e: q[i]) cout << e+1 << ' '; cout << endl;
        cin >> res[i];
    }
    cout << "! ";
    ll all = 0;
    rep(i, 13) all |= res[i];
    rep(i, N){
        ll a = -1, b = 0;
        rep(j, 13){
            if(used[i][j]) a &= res[j];
            else b |= res[j];
        }
        ll ans = all;
        rep(j, 63){
            if((a&(1LL<<j)) && !(b&(1LL<<j))) ans &= ~(1LL<<j);
        }
        cout << ans << ' ';
    }
    cout << endl;
}