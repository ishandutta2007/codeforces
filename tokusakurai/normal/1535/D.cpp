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
    int K; cin >> K;
    int N = (1<<K)-1;

    string S; cin >> S;

    reverse(all(S));

    vector<int> c(2*N+1, 1);
    rep3(i, N-1, 0){
        c[i] = 0;
        if(S[i] != '0') c[i] += c[2*i+1];
        if(S[i] != '1') c[i] += c[2*i+2];
    }

    int Q; cin >> Q;

    while(Q--){
        int u; char x; cin >> u >> x; u = N-u;
        //cout << u << '\n';
        S[u] = x;
        
        while(u >= 0){
            c[u] = 0;
            if(S[u] != '0') c[u] += c[2*u+1];
            if(S[u] != '1') c[u] += c[2*u+2];
            if(u == 0) break;
            u = (u-1)/2;
        }

        cout << c[0] << '\n';
    }
}