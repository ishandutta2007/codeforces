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

    vector<int> c(N+2, 0);
    vector<vector<int>> L(N+2, vector<int>(2, 0)), R(N+2, vector<int>(2, M));

    rep2(i, 1, N){
        cin >> c[i];
        rep(j, 2) cin >> L[i][j] >> R[i][j];
    }

    vector<vector<int>> dp1(N+2, vector<int>(2, 0)), dp2(N+2, vector<int>(2, N+1));

    rep(j, 2){
        int m = N+1;
        rep3(i, N+1, 0){
            if(L[i][j] <= c[i] && c[i] <= R[i][j]){
                dp1[i][j] = m;
            }
            else{
                m = i-1;
                dp1[i][j] = m;
            }
        }
    }
    
    rep(j, 2){
        {
            vector<int> v(2*N+4);
            iota(all(v), 0);
            sort(all(v), [&](int a, int b){
                int s = (a >= N+2? L[a-(N+2)][j] : c[a]);
                int t = (b >= N+2? L[b-(N+2)][j] : c[b]);
                if(s != t) return s > t;
                return a < b;
            });
            set<int> s;
            s.emplace(N+2);
            each(e, v){
                if(e >= N+2){
                    s.emplace(e-(N+2));
                }
                else{
                    chmin(dp2[e][j], *s.lower_bound(e)-1);
                }
            }
        }

        {
            vector<int> v(2*N+4);
            iota(all(v), 0);
            sort(all(v), [&](int a, int b){
                int s = (a >= N+2? R[a-(N+2)][j] : c[a]);
                int t = (b >= N+2? R[b-(N+2)][j] : c[b]);
                if(s != t) return s < t;
                return a < b;
            });
            set<int> s;
            s.emplace(N+2);
            each(e, v){
                if(e >= N+2){
                    s.emplace(e-(N+2));
                }
                else{
                    chmin(dp2[e][j], *s.lower_bound(e)-1);
                }
            }
        }
    }
    
    vector<vector<bool>> ok(N+1, vector<bool>(2));
    rep(i, N+1){
        rep(j, 2){
            int k = j^1;
            ok[i][j] = (L[i+1][j] <= c[i] && c[i] <= R[i+1][j] && L[i+1][k] <= c[i+1] && c[i+1] <= R[i+1][k]);
        }
    }

    vector<vector<int>> pre(N+1, vector<int>(2, -1));
    vector<queue<int>> que(2);
    if(ok[0][0]) que[0].emplace(0);
    if(ok[0][1]) que[1].emplace(0);

    rep2(i, 1, N){
        rep(j, 2){
            if(!ok[i][j]) continue;
            int k = j^1;
            while(!empty(que[k])){
                int t = que[k].front();
                if(dp1[t+1][j] >= i && dp2[t][k] >= i){
                    pre[i][j] = t;
                    break;
                }
                que[k].pop();
            }
        }

        rep(j, 2){
            if(pre[i][j] != -1) que[j].emplace(i);
        }
    }
    
    if(pre[N][0] == -1 && pre[N][1] == -1){
        cout << "No\n";
        return 0;
    }

    cout << "Yes\n";
    vector<int> ans(N+1, -1);
    int p = N, q = (pre[N][0] == -1? 1 : 0);

    while(p > 0){
        int np = pre[p][q];
        rep3(i, p, np+1) ans[i] = q;
        p = np, q ^= 1;
    }

    rep2(i, 1, N) cout << ans[i] << (i == N? '\n' : ' ');
}