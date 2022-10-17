//
// Created by yamunaku on 2021/03/10.
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
    vector<double> x, y;
    rep(i, 2 * n) {
        int a, b;
        cin >> a >> b;
        if (a == 0) x.push_back(abs(b));
        else y.push_back(abs(a));
    }
    sort(all(x));
    sort(all(y));
    double ans = 0;
    rep(i, n) {
        ans += sqrt(x[i] * x[i] + y[i] * y[i]);
    }
    cout << ans << endl;
}

int main() {
    CFS;
    CST(10);
    int t;
    cin >> t;
    rep(_, t) solve();
    return 0;
}