#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MAXN = 1e6 + 10;

int u, v, P;
int NICO = 6;
int MAKI = 7;

int mod;

ll pw(ll p, ll q) {
    ll ret = 1;
    for (; q; q >>= 1) {
        if (q & 1) ret = ret * p % mod;
        p = p * p % mod;
    }
    return ret;
}

ll inv(ll p) {
    return pw(p, mod - 2);
}

struct PP {
    int x, cnt;
};

bool operator < (const PP & a, const PP & b) {
    if (a.x == b.x) return a.cnt < b.cnt;
    else return a.x < b.x;
}

void gao(int x, vector<PP> &f) {
    vector<PII> P, Q;
    vector<PP> g, h;
    P.emplace_back(PII(x, 0));
    int LIM = mod / 1000;
    LIM = max(LIM, 10000);
    LIM = min(LIM, mod - 1);
    while (f.size() <= LIM) {
        // cout << f.size() << ' ' << P.size() << ' ' << LIM << endl;
        g.clear();
        for (auto &x : P) {
            for (int i = -NICO; i <= NICO; i++) {
                g.emplace_back((PP){((x.first + i) % mod + mod) % mod, x.second + abs(i)});
            }
        }
        sort(g.begin(), g.end(), [](const PP & a, const PP & b) {
            if (a.x == b.x) return a.cnt < b.cnt;
            else return a.x < b.x;
        });
        g.resize(unique(g.begin(), g.end(), [](const PP & a, const PP & b) { return a.x == b.x; }) - g.begin());
        P.clear();
        for (auto &x : g) {
            P.emplace_back(PII(inv(x.x), x.cnt + 1));
        }
        h.resize(g.size() + f.size());
        merge(f.begin(), f.end(), g.begin(), g.end(), h.begin());
        h.swap(f);
        f.resize(unique(f.begin(), f.end(), [](const PP & a, const PP & b) { return a.x == b.x; }) - f.begin());
    }
}

vector<PP> f, g, h;

int getf(int x) {
    auto maki = lower_bound(f.begin(), f.end(), (PP){x, -1});
    if (maki->x == x) return maki->cnt;
    else return -555;
}

int getg(int x) {
    auto maki = lower_bound(g.begin(), g.end(), (PP){x, -1});
    if (maki->x == x) return maki->cnt;
    else return -555;
}

void fuck(int u, int p, int v, int q) {
    int pp = p, qq = q;
    p = (p % mod + mod) % mod;
    q = (q % mod + mod) % mod;
    vector<int> ans;
    int o = getf(p);
    while (o) {
        int tmp;
        if (getf(tmp = ((p + 1) % mod)) == o - 1) ans.emplace_back(2);
        else if (getf(tmp = ((p + mod - 1) % mod)) == o - 1) ans.emplace_back(1);
        else if (getf(tmp = inv(p)) == o - 1) ans.emplace_back(3);
        p = tmp;
        o--;
    }
    reverse(ans.begin(), ans.end());
    if (pp < qq) {
        while (pp != qq) {
            ans.emplace_back(1);
            pp++;
        }
    }
    else {
        while (pp != qq) {
            ans.emplace_back(2);
            pp--;
        }
    }
    p = q;
    o = getg(p);
    while (o) {
        int tmp;
        if (getg(tmp = ((p + 1) % mod)) == o - 1) ans.emplace_back(1);
        else if (getg(tmp = ((p + mod - 1) % mod)) == o - 1) ans.emplace_back(2);
        else if (getg(tmp = inv(p)) == o - 1) ans.emplace_back(3);
        p = tmp;
        o--;
    }
    int m = (int)(ans.size());
    printf("%d\n", m);
    for (int i = 0; i < m; i++) {
        printf("%d%c", ans[i], " \n"[i + 1 == m]);
    }
    int y = u;
    for (auto &x : ans) {
        if (x == 1) y = (y + 1) % mod;
        else if (x == 2) y = (y + mod - 1) % mod;
        else y = inv(y);
    }
    // cerr << y << ' ' << v << endl;
}

void solve(int casi){
    cin >> u >> v >> P;
    mod = P;
    gao(u, f);
    gao(v, g);
    // cout << f.size() << ' ' << g.size() << endl;
    // for (auto &x : f) cout << x.x << ' ' << x.cnt << endl;
    h.reserve(g.size() * 3);
    for (auto &x : g) h.emplace_back((PP){x.x - P, x.cnt});
    for (auto &x : g) h.emplace_back(x);
    for (auto &x : g) h.emplace_back((PP){x.x + P, x.cnt});
    int ptr = g.size();
    for (auto &x : f) {
        int o = 200 - x.cnt;
        while (ptr < h.size() && h[ptr].x < x.x) ptr++;
        for (int i = 0; i <= o && ptr + i < h.size() && h[ptr + i].x - x.x <= o; i++) {
            if (h[ptr + i].x - x.x + h[ptr + i].cnt <= o) {
                fuck(u, x.x, v, h[ptr + i].x);
                return ;
            }
        }
        for (int i = 1; i <= o && ptr - i >= 0 && x.x - h[ptr - i].x <= o; i++) {
            if (x.x - h[ptr - i].x + h[ptr - i].cnt <= o) {
                fuck(u, x.x, v, h[ptr - i].x);
                return ;
            }
        }
    }
}

int main(){
    int T = 1;
    for (int i = 1; i <= T; i++)
        solve(i);
    return 0;
}