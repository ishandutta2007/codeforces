#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define rep2(i, x, n) for(ll i = x; i <= n; i++)
#define rep3(i, x, n) for(ll i = x; i >= n; i--)
#define elif else if
#define sp(x) fixed << setprecision(x)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
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
const double pi = acos(-1.0);
const double EPS = 1e-10;
template<typename T> bool chmax(T &x, const T &y) {return (x < y)? (x = y, true) : false;};
template<typename T> bool chmin(T &x, const T &y) {return (x > y)? (x = y, true) : false;};

int main(){
    int N;
    string S;
    cin >> N >> S;
    
    ll ans = 0;
    for(int i = 0; i < N;){
        if(S[i] == '0') {i++; continue;}
        int j = 0;
        while(i+j < N && S[i+j] == '1') j++;
        if(j > 2){
            ll k = j-2;
            rep2(l, 1, k){
                ans += l*(k+1-l);
            }
        }
        i += j;
    }

    vector<ll> p, q, r;

    int cnt = 0;
    vector<ll> idl(N+2, -1);
    for(int i = 0; i < N;){
        if(S[i] == '0') {i++; continue;}
        int j = 0;
        while(i+j < N && S[i+j] == '1') j++;
        rep2(k, 1, j){
            int L = idl[k+1];
            if(k < j) ans += k*(i-L);
            else p.eb(j), q.eb(i-L);
        }
        rep(k, j) idl[j-k] = i+k;
        i += j;
    }

    vector<ll> idr(N+1, N);
    cnt = 0;
    for(int i = N-1; i >= 0;){
        if(S[i] == '0') {i--; continue;}
        int j = 0;
        while(i-j >= 0 && S[i-j] == '1') j++;
        rep2(k, 1, j){
            int R = idr[k];
            if(k < j) ans += k*(R-i);
            else r.eb(R-i);
        }
        rep(k, j) idr[j-k] = i-k;
        i -= j;
    }

    reverse(all(r));
    rep(i, sz(p)) ans += p[i]*q[i]*r[i];

    cout << ans << endl;
}