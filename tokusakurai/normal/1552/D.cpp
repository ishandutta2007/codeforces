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

bool solve(){
    int N; cin >> N;

    vector<int> a(N);
    rep(i, N) cin >> a[i];
    rep(i, N){
        a[i] = abs(a[i]);
        if(a[i] == 0) return true;
    }

    rep(i, 1<<N){
        if(i == 0) continue;
        int s = 0;
        rep(j, N){
            if((i>>j)&1) s += a[j];
        }

        int x = (1<<N)-1-i;
        for(int j = x; j >= 1; j--, j &= x){
            int t = 0;
            rep(k, N){
                if((j>>k)&1) t += a[k];
            }

            if(s == t) return true;
        }
    }

    return false;
}

int main(){
    int T; cin >> T;

    while(T--){
        cout << (solve()? "YES\n" : "NO\n");
    }
}