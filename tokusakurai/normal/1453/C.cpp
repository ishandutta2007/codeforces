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
        string S[N];
        rep(i, N) cin >> S[i];
        vector<int> idx[10][N], idy[10][N];
        
        rep(i, N){
            rep(j, N){
                int k = S[i][j]-'0';
                idx[k][i].eb(j);
            }
        }
        rep(j, N){
            rep(i, N){
                int k = S[i][j]-'0';
                idy[k][j].eb(i);
            }
        }

        rep(i, 10){
            int ans = 0;
            rep(j, N){
                if(sz(idx[i][j]) < 2) continue;
                int d = idx[i][j].back()-idx[i][j].front();
                chmax(ans, d*(max(j, N-1-j)));
            }
            rep(j, N){
                if(sz(idy[i][j]) < 2) continue;
                int d = idy[i][j].back()-idy[i][j].front();
                chmax(ans, d*(max(j, N-1-j)));
            }
            rep(j, N){
                rep(k, N){
                    if(sz(idx[i][j]) == 0 || sz(idy[i][k]) == 0) continue;
                    int l1 = idx[i][j].front(), r1 = idx[i][j].back();
                    int l2 = idy[i][k].front(), r2 = idy[i][k].back();
                    chmax(ans, max(k, N-1-k) * max(abs(j-l2), abs(j-r2)));
                    chmax(ans, max(j, N-1-j) * max(abs(k-l1), abs(k-r1)));
                }
            }
            cout << ans << ' ';
        }
        cout << '\n';
    }
}