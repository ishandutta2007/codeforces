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
        int N, K; cin >> N >> K;
        vector<bool> used(2*N, false);
        
        vector<int> x(N), y(N);
        rep(i, K){
            cin >> x[i] >> y[i];
            x[i]--, y[i]--;
            if(x[i] > y[i]) swap(x[i], y[i]);
            used[x[i]] = true, used[y[i]] = true;
        }

        vector<int> v;
        rep(i, 2*N){
            if(!used[i]) v.eb(i);
        }

        rep(i, N-K){
            x[K+i] = v[i], y[K+i] = v[N-K+i];
        }

        int ans = 0;
        rep(i, N){
            rep(j, i){
                int x1 = x[i], y1 = y[i], x2 = x[j], y2 = y[j];
                if(x1 > x2) swap(x1, x2), swap(y1, y2);
                if(x2 < y1 && y1 < y2) ans++;
            }
        }

        cout << ans << '\n';
    }
}