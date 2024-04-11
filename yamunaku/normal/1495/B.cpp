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

int main() {
    CFS;
    int n;
    cin >> n;
    vi p(n);
    rep(i, n) cin >> p[i];
    int now = 0;
    vi v;
    rep(i, n - 1) {
        if (p[i] < p[i + 1]) {
            if (now < 0) {
                v.push_back(now);
                now = 0;
            }
            now++;
        } else {
            if (now >= 0) {
                v.push_back(now);
                now = 0;
            }
            now--;
        }
    }
    v.push_back(now);
    int ma = 0;
    int cnt = 0;
    bool ok = false;
    for (auto &x : v) ma = max(ma, abs(x));
//    for(auto &x : v) cout << x << " ";
//    cout << endl;
    if (ma % 2) {
        cout << 0 << endl;
        return 0;
    }
    if (v[0] < 0 && abs(v[0]) == ma) cnt++;
    if (v.back() > 0 && abs(v.back()) == ma) cnt++;
    rep(i, (int) v.size() - 1) {
        if (v[i] >= 0 && v[i + 1] <= 0) {
            if (abs(v[i]) == ma || abs(v[i + 1]) == ma) {
                cnt++;
            }
            if (abs(v[i]) == ma && abs(v[i + 1]) == ma) {
                ok = true;
            }
        }
    }
    if (ok && cnt == 1) {
        cout << 1 << endl;
    } else {
        cout << 0 << endl;
    }
    return 0;
}