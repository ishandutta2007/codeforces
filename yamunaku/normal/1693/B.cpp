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

int n;
mti ch;
vl l, r;

pair<ll, int> dfs(int x) {
    pair<ll, int> ans(0, 0);
    for (int c : ch[x]) {
        auto p = dfs(c);
        ans.first += p.first;
        ans.second += p.second;
    }
    if (l[x] > ans.first) {
        ans.first = r[x];
        ans.second++;
    } else {
        ans.first = min(r[x], ans.first);
    }
    return ans;
}

void solve() {
    cin >> n;
    vi p(n, 0);
    ch = mti(n);
    repl(i, 1, n) {
        cin >> p[i], p[i]--;
        ch[p[i]].push_back(i);
    }
    l = vl(n), r = vl(n);
    rep(i, n) cin >> l[i] >> r[i];
    cout << dfs(0).second << endl;
}

int main() {
    CFS;
    int t;
    cin >> t;
    rep(i, t) solve();
    return 0;
}