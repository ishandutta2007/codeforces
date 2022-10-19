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
    int N, K; cin >> N >> K;

    vector<int> a(N);
    rep(i, N) cin >> a[i];
    sort(all(a));

    int MAX = 1000000;

    vector<int> lb(2*MAX+1, N);
    rep(i, N){
        int pre = (i == 0? -1 : a[i-1]);

        rep2(j, pre+1, a[i]){
            lb[j] = i;
        }
    }

    rep3(i, a[0], 1){
        bool flag = true;

        for(int j = 0; j <= MAX; j += i){
            int p = lb[j+i]-1;
            if(p >= 0 && a[p] > j+K) flag = false;
        }

        if(flag) {cout << i << '\n'; return 0;}
    }
}