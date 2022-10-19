#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define each(e, v) for(auto &e: v)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) (int)x.size()
using ll = long long;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const int MOD = 1000000007;
//const int MOD = 998244353;
const int inf = (1<<30)-1;
const ll INF = (1LL<<60)-1;
template<typename T> bool chmax(T &x, const T &y) {return (x < y)? (x = y, true) : false;};
template<typename T> bool chmin(T &x, const T &y) {return (x > y)? (x = y, true) : false;};

struct io_setup{
    io_setup(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout << fixed << setprecision(15);
    }
} io_setup;

vector<int> mul(vector<int> v){
    int n = sz(v);
    vector<int> ret(n+1, 0);
    rep(i, n){
        ret[i] += v[i]*9;
        ret[i+1] += ret[i]/10, ret[i] %= 10;
    }
    if(ret[n] == 0) ret.pop_back();
    return ret;
}

vector<int> add(vector<int> a, vector<int> b){
    if(sz(a) < sz(b)) swap(a, b);
    a.pb(0);
    rep(i, sz(b)){
        a[i] += b[i];
        if(a[i] >= 10) a[i] -= 10, a[i+1]++;
    }
    if(a.back() == 0) a.pop_back();
    return a;
}

bool comp(vector<int> a, vector<int> b){ //a<=b
    if(sz(a) != sz(b)) return sz(a) < sz(b);
    reverse(all(a)), reverse(all(b));
    rep(i, sz(a)){
        if(a[i] != b[i]) return a[i] < b[i];
    }
    return true;
}

vector<int> sub(vector<int> a, vector<int> b){
    rep(i, sz(b)){
        a[i] -= b[i];
        if(a[i] < 0) a[i] += 10, a[i+1]--;
    }
    while(sz(a) > 1 && a.back() == 0) a.pop_back();
    return a;
}

int main(){
    string S; cin >> S;

    reverse(all(S));
    vector<int> v;
    each(e, S) v.eb(e-'0');
    v = mul(v);

    int ans = inf;

    rep2(x, -460, 460){
        vector<int> T; //
        int K; //
        if(x < 0){
            vector<int> a;
            int memo = -x;
            while(memo) a.eb(memo%10), memo /= 10;
            if(comp(a, v)) T = sub(v, a), K = x;
            else T = sub(a, v), K = -x;
        }
        else{
            vector<int> a;
            int memo = x;
            while(memo) a.eb(memo%10), memo /= 10;
            T = add(v, a), K = x;
        }

        int n = sz(T);
        vector<vector<int>> dp(3, vector<int>(1000, inf)); 
        dp[1][500] = 0;

        rep(i, n){
            vector<vector<int>> tmp(3, vector<int>(1000, inf)); 
            rep(j, 1000){
                rep2(l, 0, 2){
                    if(dp[l][j] == inf) continue;
                    rep2(k, -9, 9){
                        int m = l+k-1;
                        if(m == T[i]-10) chmin(tmp[0][j+k], dp[l][j]+i*abs(k));
                        if(m == T[i]) chmin(tmp[1][j+k], dp[l][j]+i*abs(k));
                        if(m == T[i]+10) chmin(tmp[2][j+k], dp[l][j]+i*abs(k));
                    }
                }
            }
            swap(dp, tmp);
        }

        chmin(ans, dp[0][500+K-1]+n);
        chmin(ans, dp[1][500+K]);
        chmin(ans, dp[2][500+K+1]+n);
    }

    cout << ans << '\n';
}