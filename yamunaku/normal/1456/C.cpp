//
// Created by yamunaku on 2020/11/29.
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

int main() {
    CFS;
    ll n, k;
    cin >> n >> k;
    vl a(n);
    vl b, c;
    b.reserve(n);
    c.reserve(n);
    ll sum = 0;
    rep(i, n) {
        cin >> a[i];
        if (a[i] < 0) c.push_back(-a[i]);
        else {
            sum += a[i];
            b.push_back(a[i]);
        }
    }
    sort(all(b));
    sort(all(c));
    ll tmp = 0;
    rep(i, b.size()) {
        tmp += i * b[i];
    }
    ll sz = c.size();
    ll d = (sz + k) / (k + 1);
    ll ans = tmp + d * sum;
    vi x(n);
    rep(i, sz) {
        x[sz - 1 - i] = i / (k + 1);
        ans -= x[sz - 1 - i] * c[sz - 1 - i];
    }
    rep(i, sz - 1) {
        sum -= c[i];
        if (i < sz - 1) {
            if (x[i] != x[i + 1])
                continue;
        }
        if (sum < 0) break;
        ans += sum;
    }
    cout << ans << endl;
    return 0;
}