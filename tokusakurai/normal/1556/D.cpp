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

ll query(int i, int j){
    ll x, y;
    cout << "and " << i+1 << ' ' << j+1 << endl;
    cin >> x;
    cout << "or " << i+1 << ' ' << j+1 << endl;
    cin >> y;
    return x+y;
}

int main(){
    int N, M; cin >> N >> M; M--;

    vector<ll> S(N); //a[0]+a[i]
    rep2(i, 1, N-1){
        S[i] = query(0, i);
    }
    ll K = query(1, 2);

    vector<ll> a(N);
    a[0] = (S[1]+S[2]+K)/2 - K;

    rep2(i, 1, N-1) a[i] = S[i]-a[0];

    sort(all(a));
    cout << "finish " << a[M] << endl;
}