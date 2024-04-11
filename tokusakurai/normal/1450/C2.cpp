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
        vector<string> S(N);
        rep(i, N) cin >> S[i];

        vector<int> a(3, 0), b(3, 0);
        rep(i, N){
            rep(j, N){
                if(S[i][j] == 'X') a[(i+j)%3]++;
                if(S[i][j] == 'O') b[(i+j)%3]++;
            }
        }

        int id = -1, m = -inf;
        rep(i, 3) if(chmax(m, a[i]+b[i])) id = i;
        
        int p = -1, q = -1;
        rep(i, 3){
            if(i == id) continue;
            if(p == -1) p = i;
            else q = i;
        }

        if(b[p]+a[q] > b[q]+a[p]) swap(p, q);

        rep(i, N){
            rep(j, N){
                if(S[i][j] == 'O' && (i+j)%3 == p) S[i][j] = 'X';
                else if(S[i][j] == 'X' && (i+j)%3 == q) S[i][j] = 'O';
            }
        }

        rep(i, N) cout << S[i] << '\n';
    }
}