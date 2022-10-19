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
        int N, K; cin >> N >> K;

        string S; cin >> S;
        int l = 0, r = 0;

        while(l < N && S[l] == 'L') l++;
        while(r < N && S[N-1-r] == 'L') r++;

        if(l == N) {cout << max(0, 2*K-1) << '\n'; continue;}

        int ans = 0;
        vector<int> ds;

        rep(i, N){
            if(S[i] == 'W'){
                ans++;
                if(i > 0 && S[i-1] == 'W') ans++;
            }
        }

        for(int i = 0; i < N;){
            if(S[i] == 'W') {i++; continue;}

            int j = 0;
            while(i+j < N && S[i+j] == 'L') j++;

            if(i != 0 && i+j != N) ds.eb(j);
            i += j;
        }

        sort(all(ds));
        for(auto &e: ds){
            if(K >= e) ans += 2*e+1, K -= e;
        }
        ans += 2*K;
        cout << min(ans, 2*N-1) << '\n';
    }
}