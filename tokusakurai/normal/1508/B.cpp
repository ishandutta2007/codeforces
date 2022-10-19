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
        int N; ll K; cin >> N >> K;

        int x = 1;
        while(K > (1LL<<(x-1))) x++;

        if(x > N) {cout << "-1\n"; continue;}
        K = (1LL<<(x-1))-K+1;

        vector<int> ans(N);
        iota(all(ans), 0);

        int p = N-x;

        rep3(i, x-1, 0){
            if(K <= (1LL<<i) && (i == 0 || (1LL<<(i-1)) < K)){
                int np = N-i;
                reverse(begin(ans)+p, begin(ans)+np);
                p = np;
                if(i > 0) K -= (1LL<<(i-1));
            }
        }

        //cout << x << ' ' << K << '\n';

        rep(i, N) cout << ans[i]+1 << (i == N-1? '\n' : ' ');
    }
}