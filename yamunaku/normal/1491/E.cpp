//
// Created by yamunaku on 2021/02/28.
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


vector<vector<pair<int, int>>> e;
vi rem;
vi f;


int main() {
    CFS;
    int n;
    cin >> n;
    vector<vector<pair<int, int>>> e(n);
    vi rem(n - 1, true);
    vi f(30);
    vi p(n);
    vi ue(n);
    f[0] = f[1] = 1;
    repl(i, 2, 30) f[i] = f[i - 1] + f[i - 2];
    int k = -1;
    rep(i, 30) {
        if (n == f[i]) k = i;
    }
    if (k == -1) {
        CNO;
        return 0;
    }
    rep(i, n - 1) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        e[u].emplace_back(v, i);
        e[v].emplace_back(u, i);
    }
    vi el;
    auto bfs = [&](int x) {
        queue<int> q;
        q.push(x);
        p[x] = x;
        while (!q.empty()) {
            int now = q.front();
            el.push_back(now);
            q.pop();
            for (auto &nx : e[now]) {
                if (nx.first == p[now]) continue;
                if (!rem[nx.second]) continue;
                p[nx.first] = now;
                ue[nx.first] = nx.second;
                q.push(nx.first);
            }
        }
    };
    struct sta {
        int x;
        int sz;
    };
    queue<sta> que;
    que.push({0, k});
    vi c(n, 0);
    while (!que.empty()) {
        sta s = que.front();
        que.pop();
//        cout << s.x SP s.sz << endl;
        if (s.sz <= 3) continue;
        el = vi();
        bfs(s.x);
        reverse(all(el));
        for (auto &x : el) c[x] = 1;
        el.pop_back();
        bool ok = false;
        for (auto &x : el) {
//            cout << "?" SP x SP c[x] << endl;
            if (c[x] == f[s.sz - 1]) {
                que.push({x, s.sz - 1});
                que.push({p[x], s.sz - 2});
                rem[ue[x]] = false;
                ok = true;
//                cout << "!" SP x SP p[x] << endl;
                break;
            } else if (c[x] == f[s.sz - 2]) {
//                cout << "!" SP x SP p[x] << endl;
                que.push({x, s.sz - 2});
                que.push({p[x], s.sz - 1});
                rem[ue[x]] = false;
                ok = true;
                break;
            }
            c[p[x]] += c[x];
        }
        if (!ok) {
            CNO;
            return 0;
        }
    }
    CYES;
    return 0;
}