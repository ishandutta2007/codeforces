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
 
int main(){
    int N; ll P; cin >> N >> P;
 
    vector<vector<ll>> comb(N+1, vector<ll>(N+1, 0));
    vector<ll> fac(N+1, 1);
    comb[0][0] = 1;
    fac[0] = 1;
 
    rep(i, N){
        rep(j, i+1){
            comb[i+1][j] += comb[i][j], comb[i+1][j] %= P;
            comb[i+1][j+1] += comb[i][j], comb[i+1][j+1] %= P;
        }
    }
 
    rep(i, N){
        fac[i+1] = fac[i]*(i+1), fac[i+1] %= P;
    }
 
    int M = N*(N+1)/2;
 
    vector<ll> dp(M+1, 0);
    vector<ll> S1(M+1, 0), S2(M+1, 0);
    dp[0] = 1;
    ll ans = 0;
 
    rep(i, N){ //N-1-i
        rep(j, M+1) S1[j] = dp[j];
        rep2(j, 1, M){
            S1[j] += S1[j-1];
            if(S1[j] >= P) S1[j] -= P;
        }
        
        rep(j, M+1) S2[j] = S1[j];
        rep2(j, 1, M){
            S2[j] += S2[j-1];
            if(S2[j] >= P) S2[j] -= P;
        }
 
        ll S = 0, res = 0;
 
        rep2(j, 2, M){
            S += S1[j-2]*i, S %= P;
 
            int L = j-3-i, R = j-3;
            if(R >= 0){
                S += P-S2[R];
                if(S >= P) S -= P;
            }
            if(L >= 0){
                S += S2[L];
                if(S >= P) S -= P;
            }
 
            res += S*dp[j], res %= P;
        }
 
        //cout << res << '\n';
        ll perm = comb[N][N-1-i]*fac[N-1-i]%P;
        ans += res*perm, ans %= P;
 
        ll T = 0;
 
        vector<ll> tmp(M+1, 0);
        rep(j, M+1){
            T += dp[j];
            if(T >= P) T -= P;
            if(j-1-i >= 0){
                T += P-dp[j-1-i];
                if(T >= P) T -= P;
            }
            tmp[j] = T;
        }
 
        swap(dp, tmp);
    }
 
    cout << ans << '\n';
}