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

        vector<int> ids;
        ids.eb(0);
        rep(i, N-1){
            if(a[i] == a[i+1]) ids.eb(i+1);
        }
        ids.eb(N);

        int K = 0;
        vector<int> cnt(N, 0);
        rep(i, sz(ids)-1){
            K++;
            int l = ids[i], r = ids[i+1]-1;
            cnt[a[l]]++, cnt[a[r]]++;
        }

        int id = -1, M = -inf;
        rep(i, N) if(chmax(M, cnt[i])) id = i;

        if(M <= K+1) {cout << K-1 << '\n'; continue;}

        int n = 0;
        rep(i, N-1){
            if(a[i] == a[i+1]) continue;
            if(a[i] == id || a[i+1] == id) continue;
            n++;
        }

        cout << (n >= M-1-K? M-2 : -1) << '\n';
    }
}