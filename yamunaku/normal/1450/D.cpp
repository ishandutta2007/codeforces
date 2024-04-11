//
// Created by yamunaku on 2020/12/06.
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
    vi a(n);
    mti p(n);
    rep(i, n) {
        cin >> a[i];
        p[a[i] - 1].push_back(i);
    }
    vi ma(n, 0);
    set<int> st;
    st.insert(-1);
    st.insert(n);
    rep(i, n) {
        for (auto &x : p[i]) {
            auto itr = st.lower_bound(x);
            int r = (*itr);
            itr--;
            int l = (*itr);
            ma[i] = max(ma[i], r - l - 1);
        }
        for (auto &x : p[i]) {
            st.insert(x);
        }
    }
    priority_queue<pair<int, int>> q;
    rep(i, n) {
        q.emplace(-ma[i], i + 1);
    }
    int mi = n + 1;
    repl(i, 1, n + 1) {
        while (!q.empty()) {
            if (-q.top().first >= i) break;
            mi = min(mi, q.top().second);
            q.pop();
        }
        if (mi > n + 1 - i) {
            cout << 1;
        } else {
            cout << 0;
        }
    }
    cout << endl;
}

int main() {
    CFS;
    int t;
    cin >> t;
    rep(_, t) solve();
    return 0;
}