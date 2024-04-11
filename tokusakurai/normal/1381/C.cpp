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
        int N, x, y; cin >> N >> x >> y;
        int n = N-x;
        y -= x;
        vector<int> b(N), cnt(N+1);
        vector<int> id[N+1];
        rep(i, N){
            cin >> b[i];
            id[--b[i]].eb(i);
        }

        priority_queue<pii> que;
        rep(i, N+1) que.emplace(cnt[i] = sz(id[i]), i);
        while(x--){
            int i = que.top().second; que.pop();
            que.emplace(--cnt[i], i);
        }

        vector<int> ans(N, -1);
        vector<int> surv, A;
        int rem = -1;
        rep(i, N+1){
            int j = sz(id[i]), k = j-cnt[i];
            rep(l, j-k){
                surv.eb(id[i][l]), A.eb(i);
            }
            rep2(l, j-k, j-1) ans[id[i][l]] = i;
            if(j == 0) rem = i; 
        }

        int m = que.top().first;
        if(2*(n-m) < y) {cout << "NO\n"; continue;}
        
        vector<int> B(n);
        rep(i, n) B[(i+m)%n] = A[i];
        
        int k = n-y;
        rep(i, n){
            if(B[i] == b[surv[i]]) B[i] = rem, k--; 
        }
        rep(i, n){
            if(k == 0) break;
            if(B[i] != rem) B[i] = rem, k--;
        }

        rep(i, n) ans[surv[i]] = B[i];

        cout << "YES\n";
        rep(i, N) cout << ans[i]+1 << ' '; cout << '\n';
    }
}