//
// Created by yamunaku on 2020/11/17.
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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> ans;
    ans.reserve(n * m);
    vector<string> s(n);
    auto flip = [&](int i, int j) {
        if (s[i][j] == '0') s[i][j] = '1';
        else s[i][j] = '0';
    };
    rep(i, n) cin >> s[i];
    rep(i, n - 2) {
        rep(j, m - 1) {
            if (s[i][j] == '1') {
                ans.push_back({i, j, i + 1, j, i + 1, j + 1});
                flip(i, j);
                flip(i + 1, j);
                flip(i + 1, j + 1);
            }
        }
        if (s[i][m - 1] == '1') {
            ans.push_back({i, m - 1, i + 1, m - 1, i + 1, m - 2});
            flip(i, m-1);
            flip(i + 1, m - 1);
            flip(i + 1, m - 2);
        }
    }
    int k = n - 2;
    rep(j, m - 2) {
        if (s[k][j] == '0') {
            if (s[k + 1][j] == '0') {

            } else {
                ans.push_back({k + 1, j, k, j + 1, k + 1, j + 1});
                flip(k+1, j);
                flip(k, j + 1);
                flip(k + 1, j + 1);
            }
        } else {
            if (s[k + 1][j] == '0') {
                ans.push_back({k, j, k, j + 1, k + 1, j + 1});
                flip(k, j);
                flip(k, j + 1);
                flip(k + 1, j + 1);
            } else {
                ans.push_back({k, j, k + 1, j, k + 1, j + 1});
                flip(k,j);
                flip(k+1, j);
                flip(k+1, j + 1);
            }
        }
    }
    int l = m - 2;
    while (1) {
        vector<pair<int, int>> zero, one;
        rep(i, 2) {
            rep(j, 2) {
                if (s[k + i][l + j] == '0') zero.emplace_back(k + i, l + j);
                else one.emplace_back(k + i, l + j);
            }
        }
        if (zero.size() == 0) {
            vi tmp;
            rep(i, 3) {
                tmp.push_back(one[i].first);
                tmp.push_back(one[i].second);
                flip(one[i].first, one[i].second);
            }
            ans.push_back(tmp);
        } else if (zero.size() == 1) {
            vi tmp;
            rep(i, 3) {
                tmp.push_back(one[i].first);
                tmp.push_back(one[i].second);
                flip(one[i].first, one[i].second);
            }
            ans.push_back(tmp);
        } else if (zero.size() == 2 || zero.size() == 3) {
            vi tmp;
            rep(i, 2) {
                tmp.push_back(zero[i].first);
                tmp.push_back(zero[i].second);
                flip(zero[i].first, zero[i].second);
            }
            rep(i, 1) {
                tmp.push_back(one[i].first);
                tmp.push_back(one[i].second);
                flip(one[i].first, one[i].second);
            }
            ans.push_back(tmp);
        } else {
            break;
        }
    }
//    rep(i,n) cout << s[i] << endl;
    cout << ans.size() << endl;
    for (auto &v : ans) {
        rep(j, 6) cout << v[j] + 1 << " ";
        cout << endl;
    }
}

int main() {
    CFS;
    int t;
    cin >> t;
    rep(_, t) solve();
    return 0;
}