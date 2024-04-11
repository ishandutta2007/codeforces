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
    int N, Q; cin >> N >> Q;
    string S; cin >> S;

    vector<vector<vector<int>>> a(3, vector<vector<int>>(3, vector<int>(N, 0)));
    rep(i, 3) rep(j, 3){
        rep(k, N){
            if(k%3 == i && S[k]-'a' == j){
                a[i][j][k]++;
            }
        }
    }

    vector<vector<vector<int>>> s(3, vector<vector<int>>(3, vector<int>(N+1, 0)));
    rep(i, 3) rep(j, 3){
        rep(k, N){
            s[i][j][k+1] = s[i][j][k]+a[i][j][k];
        }
    }
    
    while(Q--){
        int L, R; cin >> L >> R; L--;
        vector<int> v(3);
        iota(all(v), 0);
        int ans = inf;

        do{
            int tmp = R-L;
            rep(i, 3){
                int j = v[i];
                tmp -= s[i][j][R]-s[i][j][L];
            }
            chmin(ans, tmp);
        } while(next_permutation(all(v)));

        cout << ans << '\n';
    }
}