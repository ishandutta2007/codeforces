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

    vector<int> a(N);
    rep(i, N) cin >> a[i];
    sort(all(a));

    vector<int> s1(N+1, 0), s2(N+1, 0), s3(N+1, 0);
    rep(i, N){
        s1[i+1] = s1[i]+a[i];
        s2[i+1] = s2[i]+max(0, 3-a[i]);
        s3[i+1] = s3[i]+max(0, a[i]-3);
    }

    int S = s1[N], ans = inf;

    rep2(i, 0, N){
        if(S > 4*(N-i)) continue;

        if(s1[i] >= s2[N]-s2[i]) chmin(ans, s1[i]);
        else if(s1[i]+s3[N]-s3[i] >= s2[N]-s2[i]) chmin(ans, s2[N]-s2[i]);
    }

    cout << (ans == inf? -1 : ans) << '\n';
}