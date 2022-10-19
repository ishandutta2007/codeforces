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
    int N, M, Q; cin >> N >> M >> Q;

    vector<ll> a(N);

    rep(i, N) cin >> a[i];

    vector<int> S(M);
    vector<ll> A(M, 0), B(M, 0);
    vector<vector<int>> ids(M), ids2(N);

    rep(i, M){
        cin >> S[i];
        ids[i].resize(S[i]);

        rep(j, S[i]){
            cin >> ids[i][j]; ids[i][j]--;
            B[i] += a[ids[i][j]];
            ids2[ids[i][j]].eb(i);
        }
    }
    
    vector<int> v, id(M, -1);
    int D = 300;

    rep(i, M){
        if(S[i] >= D) id[i] = sz(v), v.eb(i);
    }

    int n = sz(v);

    vector<vector<ll>> cnt(M, vector<ll>(n, 0));

    rep(i, M){
        each(e, ids[i]){
            each(u, ids2[e]){
                if(id[u] != -1) cnt[i][id[u]]++;
            }
        }
    }
    
    while(Q--){
        char c; int k; cin >> c >> k; k--;

        if(c == '?'){
            if(id[k] == -1){
                ll ans = 0;

                each(e, ids[k]) ans += a[e];
                rep(i, n) ans += cnt[k][i]*A[v[i]];

                cout << ans << '\n';
            }
            else{
                cout << B[k] << '\n';
            }
        }
        else{
            ll x; cin >> x;
            
            rep(i, n) B[v[i]] += cnt[k][i]*x;

            if(id[k] == -1){
                each(e, ids[k]) a[e] += x;
            }
            else{
                A[k] += x;
            }
        }
    }
}