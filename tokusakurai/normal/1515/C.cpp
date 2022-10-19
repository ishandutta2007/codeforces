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
    int T; cin >> T;

    while(T--){
        int N, M, x; cin >> N >> M >> x;

        vector<int> a(N);
        rep(i, N) cin >> a[i];

        priority_queue<pii, vector<pii>, greater<pii>> que;
        rep(i, M){
            que.emplace(0, i);
        }

        vector<int> ans(N);
        rep(i, N){
            auto p = que.top(); que.pop();
            ans[i] = p.second+1;
            que.emplace(p.first+a[i], p.second);
        }

        cout << "YES\n";
        rep(i, N) cout << ans[i] << (i == N-1? '\n' : ' ');
    }
}