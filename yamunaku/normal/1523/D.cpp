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

int main() {
    CFS;
    int n, m, p;
    cin >> n >> m >> p;
    vector<string> s(n);
    rep(i, n) cin >> s[i];
    std::random_device rnd;
    rep(i, n / 2) {
        swap(s[rnd() % n], s[rnd() % n]);
    }
    int score = 0;
    string ans(m, '0');
    rep(i, min(100, n)) {
        vi pos;
        rep(j, m) if (s[i][j] == '1') pos.push_back(j);
        p = pos.size();
        vi dp(1 << p);
        rep(j, n) {
            int b = 0;
            rep(k, p) {
                if (s[j][pos[k]] == '1')
                    b |= (1 << k);
            }
            dp[b]++;
        }
        int best = 0;
        rep(j, p) {
            rep(k, 1 << p) if (!(k & (1 << j))) dp[k] += dp[k | (1 << j)];
        }
        rep(j, 1 << p) {
            if (dp[j] >= (n + 1) / 2 && __builtin_popcount(j) > __builtin_popcount(best)) {
                best = j;
            }
        }
        if (__builtin_popcount(best) > score) {
            score = __builtin_popcount(best);
            string tmp(m, '0');
            rep(j, p) if (best & (1 << j)) tmp[pos[j]] = '1';
            ans = tmp;
        }
    }
    cout << ans << endl;
    return 0;
}