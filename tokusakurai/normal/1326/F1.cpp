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

template<typename T>
T next_combination(T comb){ //comb
    assert(comb > 0);
    T x = comb&(-comb), y = comb+x, z = comb&(~y);
    return ((z/x)>>1)|y;
}

int main(){
    int N; cin >> N;

    vector<string> S(N);
    rep(i, N) cin >> S[i];

    vector<int> id(1<<N, 0);
    vector<int> c(N+1, 0);

    vector<vector<int>> ps(N+1);

    rep2(i, 1, N){
        int x = (1<<i)-1, k = 0;

        while(x < (1<<N)){
            id[x] = k++;
            ps[i].eb(x);
            x = next_combination(x);
        }

        c[i] = k;
    }

    vector<vector<vector<ll>>> dp(c[1], vector<vector<ll>>(N, vector<ll>(1, 0)));
    rep(i, N){
        dp[id[1<<i]][i][0]++;
    }

    rep2(i, 1, N-1){
        vector<vector<vector<ll>>> tmp(c[i+1], vector<vector<ll>>(N, vector<ll>(1<<i, 0)));

        rep(j, c[i]){
            rep(k, N){
                rep(l, 1<<(i-1)){
                    if(dp[j][k][l] == 0) continue;

                    rep(m, N){
                        if((ps[i][j]>>m)&1) continue;

                        int nj = id[ps[i][j]|(1<<m)], nk = m, nl = l|((S[k][m]-'0')<<(i-1));
                        tmp[nj][nk][nl] += dp[j][k][l];
                    }
                }
            }
        }

        swap(dp, tmp);
    }

    rep(i, 1<<(N-1)){
        ll ans = 0;
        rep(j, c[N]){
            rep(k, N){
                ans += dp[j][k][i];
            }
        }
        cout << ans << (i == (1<<(N-1))-1? '\n' : ' ');
    }
}