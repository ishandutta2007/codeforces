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

int nl(int x){
    if(x == 0) return 0;
    return x+32-__builtin_clz(x);
}

int nr(int x){
    return nl(x+1)-1;
}

int main(){
    int N, Q; cin >> N >> Q;

    vector<vector<int>> L(N), R(N), C(N);
    vector<bool> used(1000000, false);

    while(Q--){
        int t; cin >> t;
        if(t == 1){
            int d, l, r, c; cin >> d >> l >> r >> c; d--, l--, r--, c--;
            L[d].eb(l), R[d].eb(r), C[d].eb(c);
        }
        else{
            int d, x; cin >> d >> x; d--, x--;
            int l = x, r = x;

            int ans = 0;

            rep2(i, d, N-1){
                rep(j, sz(L[i])){
                    if(R[i][j] < l || r < L[i][j]) continue;
                    if(!used[C[i][j]]){
                        ans++;
                        used[C[i][j]] = true;
                    }
                }
                l = nl(l), r = nr(r);
            }

            l = x, r = x;

            rep2(i, d, N-1){
                rep(j, sz(L[i])){
                    if(R[i][j] < l || r < L[i][j]) continue;
                    used[C[i][j]] = false;
                }
                l = nl(l), r = nr(r);
            }

            cout << ans << '\n';
        }
    }
}