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
    string S;
    cin >> S;
    ll x, y;
    cin >> x >> y;

    int N = sz(S);
    vector<ll> L(N+1, 0), R(N+1, 0), L1(N+1, 0), R1(N+1, 0); //[0,i),[i,N)
    rep(i, N){
        L[i+1] = L[i]+(S[i] == '0');
        L1[i+1] = L1[i]+(S[i] == '1');
    }
    rep3(i, N-1, 0){
        R[i] = R[i+1]+(S[i] == '0');
        R1[i] = R1[i+1]+(S[i] == '1');
    }

    ll base = 0;
    rep(i, N){
        if(S[i] == '1'){
            base += L[i]*x+R[i+1]*y;
        }
    }

    vector<int> ids;
    rep(i, N){
        if(S[i] == '?') ids.eb(i);
    }

    ll ans = INF;
    if(y < x){
        ll tmp = 0;
        each(e, ids){
            tmp += L1[e]*y+R1[e+1]*x;
        }
        chmin(ans, tmp);
        int K = sz(ids);
        rep(i, K){
            ll now = y*(i+1)*(K-i-1);
            int e = ids[i];
            tmp -= L1[e]*y+R1[e+1]*x;
            tmp += L[e]*x+R[e+1]*y;
            chmin(ans, tmp+now);
        }
    }
    else{
        ll tmp = 0;
        each(e, ids){
            tmp += L[e]*x+R[e+1]*y;
        }
        chmin(ans, tmp);
        int K = sz(ids);
        rep(i, K){
            ll now = x*(i+1)*(K-i-1);
            int e = ids[i];
            tmp -= L[e]*x+R[e+1]*y;
            tmp += L1[e]*y+R1[e+1]*x;
            chmin(ans, tmp+now);
        }
    }

    cout << base+ans << '\n';
}