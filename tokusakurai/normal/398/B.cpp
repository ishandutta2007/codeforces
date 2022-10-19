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
    int N, M; cin >> N >> M;

    vector<int> ux(N, 0), uy(N, 0);

    rep(i, M){
        int x, y; cin >> x >> y; x--, y--;
        ux[x] = 1, uy[y] = 1;
    }

    int A = 0, B = 0;
    rep(i, N){
        A += ux[i], B += uy[i];
    }

    vector<vector<double>> dp(N+1, vector<double>(N+1, 0));
    rep3(i, N, 0){
        rep3(j, N, 0){
            if(i == N && j == N) continue;
            double p = (1.0*i*j)/(1.0*N*N);
            double q = (1.0*i*(N-j))/(1.0*N*N);
            double r = (1.0*(N-i)*j)/(1.0*N*N);
            double s = (1.0*(N-i)*(N-j))/(1.0*N*N);

            double y = 1.0;
            if(j < N) y += q*dp[i][j+1];
            if(i < N) y += r*dp[i+1][j];
            if(i < N && j < N) y += s*dp[i+1][j+1];

            dp[i][j] = y/(1.0-p);
        }
    }

    cout << dp[A][B] << '\n';
}