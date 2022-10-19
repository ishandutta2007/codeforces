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
        int N; string A, B;
        cin >> N >> A >> B;
        vector<int> a(N), b(N);
        rep(i, N) a[i] = A[i]-'0', b[i] = B[i]-'0';

        vector<int> ans;
        rep(i, N){
            int s, t;
            if(i&1) s = a[N-(i+1)/2]^1, t = a[(i+1)/2]^1;
            else s = a[i/2], t = a[N-1-i/2];
            if(s == b[N-1-i]) ans.eb(1);
            ans.eb(N-i);
        }

        cout << sz(ans);
        each(e, ans) cout << ' ' << e; cout << '\n';
    }
}