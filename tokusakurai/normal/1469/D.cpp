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
    vector<int> table(500*500+1, -1);
    rep2(i, 1, 500){
        rep2(j, (i-1)*(i-1)+1, i*i){
            table[j] = i;
        }
    }

    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        vector<bool> used(N+1, false);
        vector<int> rem;
        int memo = N;
        while(memo > 2){
            rem.eb(memo), used[memo] = true;
            memo = table[memo];
        }
        rem.eb(2), used[2] = true;

        vector<pii> ans;
        rep2(i, 3, N){
            if(!used[i]) ans.eb(i, N);
        }

        rep(i, sz(rem)-1){
            rep(j, 2) ans.eb(rem[i], rem[i+1]);
        }

        cout << sz(ans) << '\n';
        each(e, ans) cout << e.first << ' ' << e.second << '\n';
    }
}