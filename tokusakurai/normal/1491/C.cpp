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
        ll N; cin >> N;

        vector<ll> S(N);
        rep(i, N) cin >> S[i];

        vector<int> next(N, N);
        rep3(i, N-1, 0){
            if(S[i] > 1){
                int j = i-1;
                while(j >= 0 && S[j] == 1) next[j] = i, j--;
            }
        }

        ll ans = 0;
        rep(i, N){
            if(S[i] == 1) continue;
            if(i+S[i] >= N){
                ans += S[i]-(N-i);
                S[i] = N-i;
            }
            
            while(S[i] > 1){
                ll ptr = i;
                ans++;
                
                while(ptr < N){
                    if(S[ptr] == 1) {ptr = next[ptr]; continue;}

                    ll nxt = ptr+S[ptr];
                    if(--S[ptr] == 1){
                        int j = ptr+1;
                        while(j < N && S[j] == 1) j++;
                        next[ptr] = j;
                    }

                    ptr = nxt;
                }
            }
        }

        cout << ans << '\n';
    }
}