//
// Created by yamunaku on 2020/12/30.
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
#define MOD 1000000007
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

struct dsu {
public:
    dsu() : _n(0) {}

    dsu(int n) : _n(n), parent_or_size(n, -1) {}

    int merge(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        int x = leader(a), y = leader(b);
        if (x == y) return x;
        if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y);
        parent_or_size[x] += parent_or_size[y];
        parent_or_size[y] = x;
        return x;
    }

    bool same(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        return leader(a) == leader(b);
    }

    int leader(int a) {
        assert(0 <= a && a < _n);
        if (parent_or_size[a] < 0) return a;
        return parent_or_size[a] = leader(parent_or_size[a]);
    }

    int size(int a) {
        assert(0 <= a && a < _n);
        return -parent_or_size[leader(a)];
    }

    std::vector<std::vector<int>> groups() {
        std::vector<int> leader_buf(_n), group_size(_n);
        for (int i = 0; i < _n; i++) {
            leader_buf[i] = leader(i);
            group_size[leader_buf[i]]++;
        }
        std::vector<std::vector<int>> result(_n);
        for (int i = 0; i < _n; i++) {
            result[i].reserve(group_size[i]);
        }
        for (int i = 0; i < _n; i++) {
            result[leader_buf[i]].push_back(i);
        }
        result.erase(
                std::remove_if(result.begin(), result.end(),
                               [&](const std::vector<int> &v) { return v.empty(); }),
                result.end());
        return result;
    }

private:
    int _n;
    // root node: -1 * component size
    // otherwise: parent
    std::vector<int> parent_or_size;
};

ll modpow(ll x, ll a) {
    ll ans = 1;
    while (a) {
        if (a & 1) ans = ans * x % MOD;
        a >>= 1;
        x = x * x % MOD;
    }
    return ans;
}

ll inv(ll x) {
    return modpow(x, MOD - 2);
}

vector<ll> fact, invfact;

void buildFact(int n) {
    fact = vector<ll>(n + 1, 1);
    invfact = vector<ll>(n + 1, 1);
    for (int i = 1; i <= n; i++) {
        fact[i] = fact[i - 1] * i % MOD;
        invfact[i] = inv(fact[i]);
    }
}

ll comb(ll n, ll k) {
    return fact[n] * invfact[n - k] % MOD * invfact[k] % MOD;
}

int main() {
    CFS;
    int n, m;
    cin >> n >> m;
    dsu uf(m);
    vi c(m, false);
    vi d(m, false);
    vector<pair<int, int>> p;
    vi ans2;
    rep(i, n) {
        int k;
        cin >> k;
        int x, y;
        if (k == 1) {
            cin >> x;
            x--;
            if(!c[uf.leader(x)]){
                ans2.push_back(i);
                c[uf.leader(x)] = true;
            }
        } else {
            cin >> x >> y;
            x--, y--;
            if (uf.same(x, y)) continue;
            if (!c[uf.leader(x)] || !c[uf.leader(y)]) {
                bool ok = c[uf.leader(x)] || c[uf.leader(y)];
                uf.merge(x, y);
                c[uf.leader(x)] = ok;
                ans2.push_back(i);
            }
        }
    }
    ll ans = 1;
    rep(i, m) {
        if (i != uf.leader(i)) continue;
        if (c[i]) {
            ans = ans * modpow(2, uf.size(i)) % MOD;
        } else {
            ans = ans * modpow(2, uf.size(i) - 1) % MOD;
        }
    }
    sort(all(ans2));
    cout << ans SP ans2.size() << endl;
    for (auto &x : ans2) {
        cout << x + 1 << " ";
    }
    cout << endl;
    return 0;
}