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
        int N; cin >> N;

        vector<string> S(3);
        rep(i, 3) cin >> S[i];

        vector<int> a(3, 0), b(3, 0), c(3);
        rep(i, 3){
            each(e, S[i]){
                if(e == '0') a[i]++;
                else b[i]++;
            }
            if(a[i] >= b[i]) c[i] = 0;
            else c[i] = 1;
        }

        string A, B;
        int C;
        if(c[0] == c[1]) A = S[0], B = S[1], C = c[0];
        else if(c[0] == c[2]) A = S[0], B = S[2], C = c[0];
        else A = S[1], B = S[2], C = c[1];

        int ca = 0, cb = 0;
        string ans;
        char x = char('0'+C);

        rep(i, N){
            while(A[ca] != x) ans += A[ca++];
            while(B[cb] != x) ans += B[cb++];
            ans += x, ca++, cb++;
        }

        rep2(i, ca, 2*N-1) ans += A[i];
        rep2(i, cb, 2*N-1) ans += B[i];

        cout << ans << '\n';
    }
}