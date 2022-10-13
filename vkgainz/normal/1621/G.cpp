#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <cstring>
#include <numeric>

using namespace std;

long long MOD = 1e9 + 7;

struct seg_tree {
    vector<long long> seg;   
    int sz;
    void init(int n) {
        sz = 1;
        while (sz < n) sz *= 2;
        seg.clear();
        seg.resize(2 * sz);
    }
    void upd(int i, long long v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            seg[x] += v;
        } else {
            int m = (lx + rx) / 2;
            if (i < m) upd(i, v, 2 * x + 1, lx, m);
            else upd(i, v, 2 * x + 2, m, rx);
            seg[x] = seg[2 * x + 1] + seg[2 * x + 2];
        }
        seg[x] %= MOD;
    }
    void upd(int i, long long v) { upd(i, v, 0, 0, sz); }
    long long query(int l, int r, int x, int lx, int rx) {
        if (lx >= r || rx <= l) return 0LL;
        if (lx >= l && rx <= r) return seg[x];
        int m = (lx + rx) / 2;
        return query(l, r, 2 * x + 1, lx, m)
             + query(l, r, 2 * x + 2, m, rx) % MOD;
    }
    long long query(int l, int r) { return query(l, r, 0, 0, sz); }
};

void compress(vector<int> &v) {
    map<int, int> in;
    for (int x : v) in[x] = 1;
    int cnt = 0;
    for (auto &it : in) {
        in[it.first] = cnt++;
    }
    for (int &x : v) {
        x = in[x];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        vector<bool> cover(n);
        vector<int> use;
        vector<int> last(n);
        vector<int> nxt(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        compress(a);
        seg_tree in;
        seg_tree in2;
        in.init(n);
        in2.init(n);
        vector<int> stack;
        int lst;
        for (int i = n - 1; i >= 0; i--) {
            if (i == n - 1) {
                cover[i] = true;
                stack.push_back(i);
                lst = i;
                last[i] = i;
                nxt[i] = 0;
            } else {
                if (a[i] > a[lst]) {
                    last[i] = i;
                    nxt[i] = a[lst];
                    stack.push_back(i);
                    lst = i;
                    cover[i] = true;
                } else if (a[i] == a[lst]) {
                    last[i] = i;
                    cover[i] = true;
                    nxt[i] = a[i];
                } else {
                    int lo = 0, hi = stack.size() - 1;
                    for (int j = 0; j < 20; j++) {
                        int mid = (lo + hi) / 2;
                        if (a[stack[mid]] > a[i]) {
                            hi = mid;
                        } else {
                            lo = mid + 1;
                        }
                    }
                    last[i] = stack[lo];
                }
            }
        }
        vector<long long> l(n), r(n), s(n);
        set<pair<int, int>, greater<pair<int, int>>> toProcess;
        for (int i = 0; i < n; i++) {
            l[i] = 1 + in.query(0, a[i]) % MOD;
            in.upd(a[i], l[i]);
            toProcess.insert({a[i], i});
            //in2.upd(a[i], (l[i] * l[i]) % MOD);
            if (cover[i]) {
                auto it = toProcess.begin();
                vector<int> get;
                while (it != toProcess.end()) {
                    if (it->first >= nxt[i]) {
                        get.push_back(it->second);
                        toProcess.erase(it++);
                    } else {
                        break;
                    }
                }
                sort(get.begin(), get.end());
                for (int j = get.size() - 1; j >= 0; j--) {
                    if (j == get.size() - 1) {
                        s[get[j]] = 1;
                    } else {
                        s[get[j]] = in2.query(a[get[j]] + 1, n);
                    }
                    in2.upd(a[get[j]], s[get[j]]);
                }
                for (int j = 0; j < get.size(); j++) {
                    in2.upd(a[get[j]], -s[get[j]]);
                }
            }
        }
        in.init(n);
        for (int i = n - 1; i >= 0; i--) {
            r[i] = 1 + in.query(a[i] + 1, n) % MOD;
            in.upd(a[i], r[i]);
        }
        long long ans = 0LL;
        for (int i = 0; i < n; i++) {
            ans += l[i] * r[i] % MOD;
            ans -= l[i] * s[i] % MOD;
            ans %= MOD;
        }
        ans %= MOD;
        if (ans < 0) ans += MOD;
        cout << ans << "\n";
    }
}