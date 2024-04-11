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

    vector<vector<int>> a(N, vector<int>(M));

    rep(i, N){
        rep(j, M) cin >> a[i][j];
    }

    vector<int> check;
    int K = 0;

    rep(j, M){
        set<int> s;
        rep(i, N){
            s.emplace(a[i][j]);
        }
        if(sz(s) > 1) check.eb(j);
        K += sz(s)-1;
    }

    int n = sz(check);
    if(K > 2*N) {cout << "No\n"; return 0;}

    if(n <= 1){
        cout << "Yes\n";
        rep(i, M) cout << a[0][i] << (i == M-1? '\n' : ' ');
        return 0;
    }

    vector<int> deg(N, 0);
    rep(i, N){
        rep(j, M){
            if(a[0][j] != a[i][j]) deg[i]++;
        }
    }

    rep(i, n) rep(j, i){
        int u = check[j], v = check[i];

        bool flag = true;
        vector<pii> p, q;

        rep(k, N){
            int t = 0;

            if(a[0][u] != a[k][u]) t++;
            if(a[0][v] != a[k][v]) t++;

            if(deg[k]-t > 2) {flag = false; break;}

            if(deg[k]-t == 2) p.eb(a[k][u], a[k][v]);
            if(deg[k]-t == 1) q.eb(a[k][u], a[k][v]);
        }

        if(!flag) continue;

        if(!p.empty()){
            auto [U, V] = p[0];
            each(e, p){
                if(e.first != U || e.second != V) flag = false;
            }
            each(e, q){
                if(e.first != U && e.second != V) flag = false;
            }
            if(flag){
                cout << "Yes\n";
                a[0][u] = U, a[0][v] = V;
                rep(i, M) cout << a[0][i] << (i == M-1? '\n' : ' ');
                return 0;
            }
        }
        else if(q.empty()){
            cout << "Yes\n";
            rep(i, M) cout << a[0][i] << (i == M-1? '\n' : ' ');
            return 0;
        }
        else{
            int U1 = q[0].first, V1 = -1, U2 = -1, V2 = q[0].second;
            bool f1 = true, f2 = true;
            each(e, q){
                if(f1 && e.first != U1){
                    if(V1 != -1 && V1 != e.second) f1 = false;
                    V1 = e.second;
                }
                if(f2 && e.second != V2){
                    if(U2 != -1 && U2 != e.first) f2 = false;
                    U2 = e.first;
                }
            }

            if(!(f1 || f2)) continue;

            if(f1) a[0][u] = U1, a[0][v] = (V1 == -1? 1 : V1);
            else if(f2) a[0][u] = (U2 == -1? 1 : U2), a[0][v] = V2;

            cout << "Yes\n";
            rep(i, M) cout << a[0][i] << (i == M-1? '\n' : ' ');
            return 0;
        }
    }

    cout << "No\n";
}