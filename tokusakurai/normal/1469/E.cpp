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
        cin >> N >> K;
        string S;
        cin >> S;
        rep(i, N){
            if(S[i] == '0') S[i] = '1';
            else S[i] = '0';
        }

        int L = 0;
        while((1<<L) <= N-K+1) L++;
        chmin(L, K);

        vector<bool> cnt(1<<L, false);

        int pre = -1; //1
        rep(i, N){
            if(pre < i-(K-L) && i+L <= N){
                int tmp = 0;
                rep(j, L){
                    if(S[i+j] == '1') tmp |= (1<<(L-1-j));
                }
                cnt[tmp] = true;
            }
            if(S[i] == '1') pre = i;
        }

        vector<int> s((1<<L)+1, 0);
        rep(i, 1<<L) s[i+1] = s[i]+cnt[i];

        vector<int> ans(L);
        int l = 0, r = 1<<L;
        bool flag = true;

        rep(i, L){
            int m = (l+r)>>1;
            if(s[m]-s[l] < m-l){
                ans[i] = 0, r = m;
            }
            else if(s[r]-s[m] < r-m){
                ans[i] = 1, l = m;
            }
            else{
                flag = false; break;
            }
        }

        if(!flag) cout << "NO\n";
        else{
            cout << "YES\n";
            rep(i, K-L) cout << 0;
            rep(i, L) cout << ans[i];
            cout << '\n';
        }
    }
}