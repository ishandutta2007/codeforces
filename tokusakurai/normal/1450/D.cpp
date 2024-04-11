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
    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        vector<int> a(N);
        rep(i, N) cin >> a[i];
        rep(i, N) a[i]--;

        vector<int> ans(N+1, 0);
        vector<int> ids[N];
        rep(i, N){
            ids[a[i]].pb(i);
        }
        ans[1] = 1;
        rep(i, N) if(ids[i].empty()) ans[1] = 0;

        int now = 0;
        int l = 0, r = N-1;

        rep3(i, N, 2){
            if(!ids[N-i].empty()) ans[i] = 1;
            if(sz(ids[N-i]) != 1) break;
            if(ids[N-i][0] == l) l++;
            else if(ids[N-i][0] == r) r--;
            else break;
        }

        rep2(i, 1, N) cout << ans[i]; cout << '\n';
    }
}