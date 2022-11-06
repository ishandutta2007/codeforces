#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;

struct fenwick {
    int dat[maxn];
    void init() { memset(dat, 0, sizeof(dat)); }
    void add(int p, int v) { for (; p < maxn; p += p & -p) dat[p] += v; }
    int qry(int p, int v = 0) { for (; p; p -= p & -p) v += dat[p]; return v; }
} bit;

vector<int> solve(const vector<int> &v) {
    bit.init();
    vector<int> ret;
    for (int i = 0; i < v.size(); ++i) {
        int d = bit.qry(v[i] + 1);
        ret.push_back(v[i] - d);
        bit.add(v[i] + 1, 1);
    }
    return ret;
}

void unsolve(const vector<int> &v) {
    vector<int> ret(v.begin(), v.end());
    // vector<int> ret(v.size());
    for (int i = v.size() - 1; i > 0; --i) {
        // cout << i << endl;
        // int now = v[i] % (v.size() - i);
        ret[i - 1] += ret[i] / (v.size() - i);
        ret[i] %= (v.size() - i);
    }
    ret[0] %= (v.size());
    // cout << "b" << endl;
    // for (int i : ret) cout << i << ' '; cout << endl;
    bit.init();
    // cout << "g" << endl;
    bitset<maxn> vis;
    for (int i = 0; i < v.size(); ++i) {
        int d = 20, ans = v.size() + 1; 
        while (d--) if (ans - (1 << d) >= 0) {
            if (ans - (1 << d) - bit.qry(ans - (1 << d) + 1) >= ret[i]) ans -= (1 << d);
        }
        cout << ans << ' ';
        bit.add(ans + 1, 1);
        vis[ans] = true;
    }
    for (int i = 0; i < v.size(); ++i) if (!vis[i]) cout << i << ' ';
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];
    vector<int> ca = solve(a), cb = solve(b);
    // for (int i : ca) cout << i << ' '; cout << endl;
    // for (int i : cb) cout << i << ' '; cout << endl;
    vector<int> res(n);
    for (int i = 0; i < n; ++i) res[i] = (ca[i] + cb[i]);
    // for (int i = 0; i < n; ++i) cout << res[i] << ' '; cout << endl;
    unsolve(res);
    // res = unsolve(res);
    // for (int i : res) cout << i << ' '; cout << endl;
}