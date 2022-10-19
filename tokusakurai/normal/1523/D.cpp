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

struct Random_Number_Generator{
    mt19937_64 mt;

    Random_Number_Generator() : mt(chrono::steady_clock::now().time_since_epoch().count()) {}

    int64_t operator () (int64_t l, int64_t r){
        uniform_int_distribution<int64_t> dist(l, r-1);
        return dist(mt);
    }

    int64_t operator () (int64_t r){ 
        return (*this)(0, r);
    }
} rng;

template<typename T>
void Fast_Zeta_Transform(vector<T> &f, bool upper){
    int n = f.size();
    assert((n&(n-1)) == 0);
    for(int i = 1; i < n; i <<= 1){
        for(int j = 0; j < n; j++){
            if(!(j&i)){
                if(upper) f[j] += f[j|i];
                else f[j|i] += f[j];
            }
        }
    }
}

template<typename T>
void Fast_Mobius_Transform(vector<T> &f, bool upper){
    int n = f.size();
    assert((n&(n-1)) == 0);
    for(int i = 1; i < n; i <<= 1){
        for(int j = 0; j < n; j++){
            if(!(j&i)){
                if(upper) f[j] -= f[j|i];
                else f[j|i] -= f[j];
            }
        }
    }
}

template<typename T>
void Fast_Hadamard_Transform(vector<T> &f, bool inverse = false){
    int n = f.size();
    assert((n&(n-1)) == 0);
    for(int i = 1; i < n; i <<= 1){
        for(int j = 0; j < n; j++){
            if(!(j&i)){
                T x = f[j], y = f[j|i];
                f[j] = x+y, f[j|i] = x-y;
            }
        }
    }
    if(inverse) for(auto &e : f) e /= n;
}

int main(){
    int N, M, P; cin >> N >> M >> P;

    vector<string> S(N);
    rep(i, N) cin >> S[i];

    int T = 100;
    int mx = 0;
    string ans(M, '0');

    while(T--){
        int k = rng(0, N);

        vector<int> ids;
        rep(j, M){
            if(S[k][j] == '1') ids.eb(j);
        }

        int K = sz(ids);
        vector<int> cnt(1<<K, 0);

        rep(i, N){
            int s = 0;
            rep(j, K){
                if(S[i][ids[j]] == '1') s |= (1<<j);
            }
            cnt[s]++;
        }

        Fast_Zeta_Transform(cnt, true);

        rep(i, 1<<K){
            if(cnt[i] >= (N+1)/2){
                if(chmax(mx, __builtin_popcount(i))){
                    ans = string(M, '0');
                    rep(j, K){
                        if((i>>j)&1) ans[ids[j]] = '1';
                    }
                }
            }
        }
    }

    cout << ans << '\n';
}