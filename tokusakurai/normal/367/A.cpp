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
    string S; cin >> S;
    int N = sz(S);

    vector<vector<int>> cnt(N+1, vector<int>(3, 0));

    rep(i, N){
        rep(j, 3){
            cnt[i+1][j] = cnt[i][j]+(S[i] == char('x'+j)? 1 : 0);
        }
    }

    int Q; cin >> Q;

    while(Q--){
        int L, R; cin >> L >> R; L--;

        vector<int> a(3);
        rep(i, 3) a[i] = cnt[R][i]-cnt[L][i];
        sort(all(a));

        cout << (R-L <= 2 || a[2]-a[0] <= 1? "YES\n" : "NO\n");
    }
}