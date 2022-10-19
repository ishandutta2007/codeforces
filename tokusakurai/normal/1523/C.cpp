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
    int t; cin >> t;

    while(t--){
        int N; cin >> N;

        vector<vector<int>> b(N+1);
        
        rep(i, N){
            int a; cin >> a;
            b[i+1] = b[i];

            if(a == 1){
                b[i+1].eb(1);
            }
            else{
                while(b[i+1].back() != a-1) b[i+1].pop_back();
                b[i+1].pop_back();
                b[i+1].eb(a);
            }
        }

        rep2(i, 1, N){
            int n = sz(b[i]);
            rep(j, n){
                cout << b[i][j] << (j == n-1? '\n' : '.');
            }
        }
    }
}