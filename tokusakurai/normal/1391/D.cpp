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

vector<int> solve(vector<int> v, int st){
    int n = sz(v);
    vector<int> ret(n+1);
    ret[0] = st, v[0] ^= st;
    rep(i, n-1){
        ret[i+1] = v[i]^1;
        v[i+1] ^= ret[i+1];
    }
    ret[n] = v[n-1]^1;
    return ret;
}

int main(){
    int H, W;
    cin >> H >> W;
    string a[H];
    rep(i, H) cin >> a[i];
    if(H >= 4 && W >= 4) {cout << -1 << endl; return 0;}
    bool rev = H > W;
    if(rev) swap(H, W);
    int b[H][W];
    if(!rev) rep(i, H) rep(j, W) b[i][j] = a[i][j]-'0';
    else rep(i, H) rep(j, W) b[i][j] = a[j][i]-'0';
    if(H == 1) {cout << 0 << endl; return 0;}
    vector<vector<int>> c(H-1, vector<int>(W-1, 0));
    rep(i, H-1) rep(j, W-1){
        rep(k, 2) rep(l, 2) c[i][j] ^= b[i+k][j+l];
    }
    if(H == 2){
        vector<int> v1 = solve(c[0], 0), v2 = solve(c[0], 1);
        int cnt1 = 0, cnt2 = 0;
        for(auto &e: v1) cnt1 += e;
        for(auto &e: v2) cnt2 += e;
        cout << min(cnt1, cnt2) << endl;
    }
    else{
        int ans = inf;
        rep(k, 2) rep(l, 2){
            vector<int> v1 = solve(c[0], k), v2 = solve(c[1], l);
            int ret = 0;
            rep(i, W) ret += (v1[i]|v2[i]);
            chmin(ans, ret);
        }
        cout << ans << endl;
    }
}