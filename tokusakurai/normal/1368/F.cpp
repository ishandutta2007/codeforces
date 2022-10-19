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

int N, K, M;
vector<bool> on;

void solve(){
    int cnt = 0;
    rep(i, N) cnt += on[i];
    if(cnt == M){
        cout << 0 << endl;
        return;
    }
    cnt = 0;
    cout << K;
    rep(i, N-1){
        if(cnt >= K) break;
        if(on[i] || i%K == K-1) continue;
        cnt++;
        on[i] = true;
        cout << ' ' << i+1;
    }
    cout << endl;
    int x;
    cin >> x; x--;
    rep(i, K) on[(x+i)%N] = false;
    solve();
}

int main(){
    cin >> N;
    K = floor(sqrt(N)+0.000001);
    M = N+1-(K+(N+K-1)/K);
    on.assign(N, false);
    solve();
}