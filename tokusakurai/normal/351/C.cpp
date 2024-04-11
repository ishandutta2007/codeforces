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

    vector<int> a(N), b(N);
    rep(i, N) cin >> a[i];
    rep(i, N) cin >> b[i];

    //rep(i, N) b[i] -= a[i], a[i] = 0;

    if(N%2 == 1){
        rep(i, N) a.eb(a[i]), b.eb(b[i]);
        N *= 2, M /= 2;
    }

    vector<int> c(N);
    rep(i, N) c[i] = b[i]-a[i];

    vector<int> v(N);
    iota(all(v), 0);
    sort(all(v), [&](int i, int j){
        if(c[i] != c[j]) return c[i] < c[j];
        return i > j;
    });

    vector<int> rank(N);
    rep(i, N) rank[v[i]] = i;

    vector<int> s(N+1, 0);
    rep(i, N){
        s[i+1] = s[i]+(rank[i] < N/2? 1 : -1);
    }

    int pos = 0, m = 0;
    rep(i, N+1){
        if(chmax(m, s[i])) pos = i;
    }

    int L = pos, R = N-L;

    vector<vector<int>> dp1(L+1, vector<int>(L+1, inf));
    dp1[0][0] = 0;
    rep(i, L){
        rep(j, L){
            chmin(dp1[i+1][j+1], dp1[i][j]+a[i]);
            if(j > 0) chmin(dp1[i+1][j-1], dp1[i][j]+b[i]);
        }
    }

    vector<vector<int>> dp2(R+1, vector<int>(R+1, inf));
    dp2[0][0] = 0;
    rep(i, R){
        rep(j, R){
            chmin(dp2[i+1][j+1], dp2[i][j]+b[N-1-i]);
            if(j > 0) chmin(dp2[i+1][j-1], dp2[i][j]+a[N-1-i]);
        }
    }

    int S = 0;
    rep(i, N){
        if(rank[i] < N/2) S += b[i];
        else S += a[i];
    }

    cout << S*(M-1) + dp1[L][L&1] + dp2[R][R&1] << '\n';
}