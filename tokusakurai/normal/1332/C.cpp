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
        int N, K;
        string S;
        cin >> N >> K >> S;

        int L = N/K;
        int ans = 0;
        rep(i, K/2){
            vector<int> cnt(26, 0);
            rep(j, L){
                cnt[S[K*j+i]-'a']++, cnt[S[K*j+K-1-i]-'a']++;
            }
            int M = 0;
            each(e, cnt) ans += e, chmax(M, e);
            ans -= M;
        }

        if(K%2 == 1){
            vector<int> cnt(26, 0);
            rep(j, L){
                cnt[S[K*j+(K/2)]-'a']++;
            }
            int M = 0;
            each(e, cnt) ans += e, chmax(M, e);
            ans -= M;
        }

        cout << ans << '\n';
    }
}