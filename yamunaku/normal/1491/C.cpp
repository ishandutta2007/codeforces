//
// Created by yamunaku on 2021/02/28.
//

#include <bits/stdc++.h>
//#include <atcoder/all>

using namespace std;
//using namespace atcoder;

#define rep(i, n) for(int i = 0; i < (n); i++)
#define repl(i, l, r) for(int i = (l); i < (r); i++)
#define per(i, n) for(int i = ((n)-1); i >= 0; i--)
#define perl(i, l, r) for(int i = ((r)-1); i >= (l); i--)
#define all(x) (x).begin(),(x).end()
#define MOD9 998244353
#define MOD1 1000000007
#define IINF 1000000000
#define LINF 1000000000000000000
#define SP <<" "<<
#define CYES cout<<"Yes"<<endl
#define CNO cout<<"No"<<endl
#define CFS cin.tie(0);ios::sync_with_stdio(false)
#define CST(x) cout<<fixed<<setprecision(x)

using ll = long long;
using ld = long double;
using vi = vector<int>;
using mti = vector<vector<int>>;
using vl = vector<ll>;
using mtl = vector<vector<ll>>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
template<typename T>
using heap = priority_queue<T, vector<T>, function<bool(const T, const T)>>;

void solve() {
    int n;
    cin >> n;
    vi a(n), b(n);
    rep(i, n) cin >> a[i], b[i] = a[i];
    ll ans = 0;
    rep(i, n) {
        ans += b[i] - 1;
        int k = 0;

        repl(j, i + 2, n) {
            if (j >= n) break;
            if (j <= i + a[i]) k++;
            int tmp = b[j];
            b[j] = max(b[j] - k, 1);
            k -= tmp - b[j];
        }
    }
    cout << ans << endl;
}

int main() {
    CFS;
    int t;
    cin >> t;
    rep(_, t) {
        solve();
    }
    return 0;
}