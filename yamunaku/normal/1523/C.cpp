//
// Created by yamunaku on 2021/05/30.
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
    string ans;
    mti v(n);
    rep(i, n) {
        int x;
        cin >> x;
        if (x == 1) {
            if (ans.size() == 0) ans = "1";
            else ans += ".1";
        } else {
            string k = to_string(x - 1);
            per(j, (int) ans.size() - (int) k.size() + 1) {
                if (ans.substr(j, k.size()) == k) {
                    ans = ans.substr(0, j) + to_string(x);
                    break;
                }
            }
        }
        cout << ans << "\n";
    }
    cout << flush;
}

int main() {
    CFS;
    int t;
    cin >> t;
    rep(i, t) solve();
    return 0;
}