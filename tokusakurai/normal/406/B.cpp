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
    int N; cin >> N;

    int M = 1000000;

    vector<bool> u(M, false);
    vector<ll> x(N);
    rep(i, N){
        cin >> x[i]; x[i]--;
        u[x[i]] = true;
    }

    vector<int> rem;
    int K = 0;
    rep(i, M/2){
        if(u[i] && u[M-1-i]) K++;
        if(!u[i] && !u[M-1-i]) rem.eb(i);
    }

    cout << N << '\n';
    vector<int> ans;

    rep(i, M/2){
        if(u[i]^u[M-1-i]){
            ans.eb(u[i]? M-i : i+1);
        }
    }
    rep(i, K){
        //cout << rem[i] << '\n';
        ans.eb(rem[i]+1), ans.eb(M-rem[i]);
    }

    rep(i, N){
        cout << ans[i] << (i == N-1? '\n' : ' ');
    }
}