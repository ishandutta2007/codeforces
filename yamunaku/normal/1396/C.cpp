//
// Created by yamunaku on 2020/08/27.
//

#include <bits/stdc++.h>

using namespace std;

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

// min(r1*(a+1), r2) + r1 tele
// r1*a + r3

    int n;
    ll r1, r2, r3;
    ll d;
    cin >> n >> r1 >> r2 >> r3 >> d;
    vl a(n);
    rep(i, n) cin >> a[i];

    ll c1 = 0, c2 = LINF, c3 = LINF;
    rep(i, n - 1) {
        ll t1, t2, t3;
        ll cost1 = r1 * a[i] + r3;
        ll cost2 = min(r1 * (a[i] + 1), r2) + r1;
        ll cost3 = min(cost1, cost2);
        t1 = min(c1 + cost1, c2 + cost3);
        t2 = c1 + cost2 + 2 * d;
        t3 = min(c3 + cost3, c1 + cost2 + d * (n - 1 - i));
        if (t2 > LINF) t2 = LINF;
        if (t3 > LINF) t3 = LINF;
        c1 = t1, c2 = t2, c3 = t3;
    }
    ll cost1 = r1 * a[n - 1] + r3;
    ll cost2 = min(r1 * (a[n - 1] + 1), r2) + r1;
    ll cost3 = min(cost1, cost2);
    ll ans = min(c1 + cost1, c2 + cost3);
    ans = min(ans, c3 + min(cost1, cost2 + 2 * d));
    cout << ans + d * (n - 1) << endl;
    return 0;
}