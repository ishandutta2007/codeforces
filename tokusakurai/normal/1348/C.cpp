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
        sort(all(S));
        
        vector<pii> p;
        int ptr = 0;
        while(ptr < N){
            int j = 0;
            while(ptr+j < N && S[ptr] == S[ptr+j]) j++;
            p.eb(S[ptr]-'a', j);
            ptr += j;
        }

        if(p[0].second < K) {cout << S[K-1] << '\n'; continue;}

        int n = sz(p), cnt = K;
        string ans;
        rep(i, n){
            char x = 'a'+p[i].first;
            if(i == n-1){
                rep(j, (p[i].second+cnt-1)/cnt) ans += x;
            }
            else if(i == 0){
                if(p[i].second == K) ans += x;
                else{
                    rep(j, p[i].second-K+1) ans += x;
                    cnt = 1;
                }
            }
            else{
                rep(j, p[i].second) ans += x;
                cnt = 1;
            }
        }

        cout << ans << '\n';
    }
}