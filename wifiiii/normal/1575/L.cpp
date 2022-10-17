#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

struct node {
    set<pair<int,int>> s;
    void add(int x, int y) {
        auto it = s.lower_bound({x, y});
        if(it != s.begin() && prev(it)->second >= y) return;
        while(it != s.end() && it->second <= y) it = s.erase(it);
        s.insert({x, y});
    }
    int qry(int x) {
        auto it = s.lower_bound({x, 1e9});
        if(it == s.begin()) return -1e9;
        return (--it)->second;
    }
};

struct fenwick {
    vector<node> a;
    int n;
    fenwick(int n): n(n), a(n) {}
    void add(int x, int p, int q) {
        assert(0 <= x && x < n);
        for(int i = x + 1; i <= n; i += i & -i) {
            a[i - 1].add(p, q);
        }
    }
    int qry(int x, int p) {
        int ret = -1e9;
        for(int i = min(x + 1, n); i > 0; i -= i & -i) {
            ret = max(ret, a[i - 1].qry(p));
        }
        return ret;
    }
};

const int maxn = 200005;
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;;;;;
    vector<int> a(n + 1), b(n + 1);
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 0; i <= n; ++i) b[i] = maxn * 2 - (a[i] - i);
    fenwick qwq(3 * maxn + 1);
    int ans = 0;
    qwq.add(b[0], a[0], 0);
    for(int i = 1; i <= n; ++i) {
        int tmp = qwq.qry(b[i], a[i] - 1) + 1;
        ans = max(ans, tmp);
        qwq.add(b[i], a[i], tmp);
    }
    cout << ans << '\n';
}