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
    int T;
    cin >> T;
    while(T--){
        vector<int> N(3);
        rep(i, 3) cin >> N[i];
        vector<vector<ll>> w(3);
        rep(i, 3){
            w[i].resize(N[i]);
            rep(j, N[i]) cin >> w[i][j];
            w[i].eb(inf);
            sort(all(w[i]));
        }

        ll ans = INF*4;
        rep(i, 3) rep(j, 3){
            if(i == j) continue;
            int k = -1;
            rep(l, 3){
                if(l != i && l != j) k = l;
            }
            rep(l, N[i]){
                int L = lower_bound(all(w[j]), w[i][l])-begin(w[j]);
                int R = lower_bound(all(w[j]), w[i][l+1])-begin(w[j]);
                rep2(m, L, R-1){
                    ll a = w[i][l], b = w[j][m], c;
                    c = *lower_bound(all(w[k]), b);
                    if(c == inf) continue;
                    chmin(ans, (a-b)*(a-b)+(b-c)*(b-c)+(c-a)*(c-a));
                }
            }
        }

        cout << ans << '\n';
    }
}