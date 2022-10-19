#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
#define sp(x) fixed << setprecision(x)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
const int inf = (1<<30)-1;
const ll INF = (1LL<<60)-1;
const ld EPS = 1e-10;
template<typename T> bool chmax(T &x, const T &y) {return (x < y)? (x = y, true) : false;};
template<typename T> bool chmin(T &x, const T &y) {return (x > y)? (x = y, true) : false;};

int main(){
    int T;
    cin >> T;
    vector<int> ids[2001];
    rep(t, T){
        int N;
        cin >> N;
        int a[2*N];
        rep(i, 2*N) cin >> a[i];
        vector<pii> ans;
        rep2(i, 2, 2000){
            rep(j, 2*N) ids[a[j]%i].pb(j);
            rep(k, i){
                int l = (i-k)%i;
                if(k == l){
                    rep(m, sz(ids[k])/2) ans.pb(pii(ids[k][2*m], ids[k][2*m+1]));
                    ids[k].clear();
                }
                else{
                    rep(m, min(sz(ids[k]), sz(ids[l]))) ans.pb(pii(ids[k][m], ids[l][m]));
                    ids[k].clear(), ids[l].clear();
                }
            }
            if(sz(ans) >= N-1){
                rep(i, N-1) cout << ans[i].first+1 << ' ' << ans[i].second+1 << endl;
                break;
            }
            ans.clear();
        }
    }
}