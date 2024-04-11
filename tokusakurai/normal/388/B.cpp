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
    int K; cin >> K;

    if(K == 1){
        cout << "2\n";
        cout << "NY\n";
        cout << "YN\n";
        return 0;
    }

    int t = 31-__builtin_clz(K);

    vector<string> es(1000, string(1000, 'N'));
    int N = 3*t+1;

    rep(i, t){
        int a = 3*i+1, b = 3*i+2, c = 3*i+3, d = 3*i+4;
        if(i == t-1) d = 0;
        es[a][b] = es[b][a] = 'Y';
        es[a][c] = es[c][a] = 'Y';
        es[b][d] = es[d][b] = 'Y';
        es[c][d] = es[d][c] = 'Y';
    }

    rep3(i, t-1, 0){
        if((K>>i)&1){
            int d = 2*(t-i)-1;
            rep2(j, N, N+d-2){
                es[j][j+1] = es[j+1][j] = 'Y';
            }
            es[3*i+1][N] = es[N][3*i+1] = 'Y';
            es[N+d-1][0] = es[0][N+d-1] = 'Y';
            N += d;
        }
    }

    cout << N << '\n';
    rep(i, N){
        cout << es[i].substr(0, N) << '\n';
    }
}