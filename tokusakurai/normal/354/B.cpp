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

int N;
vector<vector<int>> dp;
vector<vector<bool>> used;
vector<string> S;

int rec(int i, int j){
    if(used[i][j]) return dp[i][j];

    used[i][j] = true;
    if(i == 2*N-2) return dp[i][j] = 0;
    dp[i][j] = (i&1? -inf : inf);

    rep(c, 26){
        int ni = i+1, nj = 0;
        rep(k, N){
            if(!((j>>k)&1)) continue;

            int x = k, y = i-k;
            if(x+1 < N && S[x+1][y]-'a' == c){
                nj |= 1<<(x+1);
            }
            if(y+1 < N && S[x][y+1]-'a' == c){
                nj |= 1<<x;
            }
        }

        if(nj > 0){
            if(i&1) chmax(dp[i][j], rec(ni, nj)+(c == 0? 1 : c == 1? -1 : 0));
            else chmin(dp[i][j], rec(ni, nj)+(c == 0? 1 : c == 1? -1 : 0));
        }
    }

    return dp[i][j];
}

int main(){
    cin >> N;

    S.resize(N);
    rep(i, N) cin >> S[i];

    dp.assign(2*N-1, vector<int>(1<<N, 0));
    used.assign(2*N-1, vector<bool>(1<<N, false));
    
    int ans = rec(0, 1)+(S[0][0] == 'a'? 1 : S[0][0] == 'b'? -1 : 0);
    //cout << ans << '\n';
    cout << (ans > 0? "FIRST\n" : ans < 0? "SECOND\n" : "DRAW\n");
}