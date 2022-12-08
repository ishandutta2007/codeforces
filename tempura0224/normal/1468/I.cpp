//
// Created by yamunaku on 2020/12/25.
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
#define CYES cout<<"YES"<<endl
#define CNO cout<<"NO"<<endl
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

ll gcd(ll x, ll y) {
    if (y == 0) return x;
    while (x % y) {
        ll tmp = x % y;
        x = y;
        y = tmp;
    }
    return y;
}

pair<int, int> aaa(ll x, ll y) {
    ll g;
    if (y >= 0) g = gcd(x, y);
    else g = gcd(x, -y);
    return {x / g, y / g};
}

int main() {
    //CFS;
    int n;
    cin >> n;
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if(x1 == 0 && y1 == 0 || x2 == 0 && y2 == 0){
        CNO;
        return 0;
    }
    if (x1 < 0) x1 = -x1, y1 = -y1;
    if (x2 < 0) x2 = -x2, y2 = -y2;
    if (aaa(x1, y1) == aaa(x2, y2)) {
        CNO;
        return 0;
    }
    ll mi = 0, ma = x1 + x2;
    vector<pair<int, int>> ans;
    repl(i, mi + 1, ma + 1) {
        double a, b;
        ll l, r;
        if (x1 == 0) {
            a = (double) (y2 * i) / x2;
            b = (double) (y2 * i) / x2 + y1;
        } else if (x2 == 0) {
            a = (double) (y1 * i) / x1;
            b = (double) (y1 * i) / x1 + y2;
        } else {
            if (i <= x1) a = (double) (y1 * i) / x1;
            else a = (double) (y2 * (i - x1)) / x2 + y1;
            if (i <= x2) b = (double) (y2 * i) / x2;
            else b = (double) (y1 * (i - x2)) / x1 + y2;
        }
        if (a > b) swap(a, b);
        l = ceil(a), r = ceil(b);
        if (ans.size() + r - l > n + 10) {
            CNO;
            return 0;
        }
        repl(k, l, r) {
            if (i == x1 && k == y1) continue;
            if (i == x2 && k == y2) continue;
            if (i == x1 + x2 && k == y1 + y2) continue;
            ans.emplace_back(i, k);
        }
    }
    ans.emplace_back(0, 0);
    if (ans.size() != n) {
        CNO;
        return 0;
    }
    CYES;
    rep(i, n) {
        cout << ans[i].first SP ans[i].second << endl;
    }
    return 0;
}