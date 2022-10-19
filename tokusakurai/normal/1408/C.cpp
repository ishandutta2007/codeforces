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
    int T;
    cin >> T;
    vector<double> ans;
    while(T--){
        int N; double L;
        cin >> N >> L;
        double p[N+2];
        p[0] = 0, p[N+1] = L;
        rep2(i, 1, N) cin >> p[i];
        int pl = 0, pr = N+1;
        double tl = 0, tr = 0, sl = 1, sr = 1;
        while(pr-pl > 1){
            double ntl = tl+(p[pl+1]-p[pl])/sl, ntr = tr+(p[pr]-p[pr-1])/sr;
            if(ntl < ntr) pl++, tl = ntl, sl += 1.0;
            else pr--, tr = ntr, sr += 1.0;
        }
        if(tl < tr){
            p[pl] += (tr-tl)*sl;
            ans.pb(tr+(p[pr]-p[pl])/(sl+sr));
        }
        else{
            p[pr] -= (tl-tr)*sr;
            ans.pb(tl+(p[pr]-p[pl])/(sl+sr));
        }
    }
    for(auto &e: ans) cout << sp(10) << e << endl;
}