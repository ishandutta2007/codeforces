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

    vector<vector<pii>> es(N);

    rep(i, M){
        int u, v, c; cin >> u >> v >> c;
        es[u].eb(c, v);
    }

    rep(i, N){
        sort(all(es[i]));
    }

    vector<vector<int>> d(N, vector<int>(N, inf));

    rep(i, N){
        int s = es[i][0].first;

        each(e, es[i]) d[i][e.second] = e.first;

        vector<int> ptr(N, 0);

        rep2(k, 1, N){
            rep(j, N){
                if(d[i][j] >= s+k) continue;
                if(d[i][j] == s+k-1){
                    chmin(d[i][(j+1)%N], s+k);
                }
                int t = s+k-d[i][j];

                while(ptr[j] < sz(es[j])){
                    pii e = es[j][ptr[j]];
                    if(e.first == t){
                        chmin(d[i][(e.second+d[i][j])%N], s+k);
                        ptr[j]++;
                    }
                    else{
                        break;
                    }
                }
            }
        }

        d[i][i] = 0;
    }

    rep(i, N){
        rep(j, N){
            cout << d[i][j] << (j == N-1? '\n' : ' ');
        }
    }
}