//
// Created on 2022/06/16.
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
    vl a(n);
    rep(i, n) cin >> a[i];
    rep(i, n) {
        if (a[i] != 0) goto next2;
    }
    CYES;
    return;
    next2:;
    if (a[0] <= 0) {
        CNO;
        return;
    }
    a[0] += -1;
    perl(i, 1, n) {
        if (a[i] != 0) {
            a[i] += 1;
            goto next;
        }
    }
    CNO;
    return;
    next:;
    ll k = 0;
    rep(i, n){
        k += a[i];
        if (k < 0) {
            CNO;
            return;
        }
    }
    if (k == 0)
        CYES;
    else
        CNO;
}

int main() {
    CFS;
    int t;
    cin >> t;
    rep(i, t) solve();
    return 0;
}