#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
int p[maxn], a[maxn], b[maxn];
bool v[maxn];

struct cmp {
    bool operator()(int a, int b) {
        return p[a] > p[b];
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    priority_queue<int, vector<int>, cmp> pq[3];
    for (int i = 0; i < n; ++i) cin >> p[i];
    for (int i = 0; i < n; ++i) cin >> a[i], pq[a[i] - 1].push(i);
    for (int i = 0; i < n; ++i) cin >> b[i], pq[b[i] - 1].push(i);
    int m; cin >> m;
    while (m--) {
        for (int i = 0; i < 3; ++i) while (pq[i].size() && v[pq[i].top()]) pq[i].pop();
        int c; cin >> c; --c;
        if (pq[c].size() == 0) cout << "-1 ";
        else cout << p[pq[c].top()] << ' ', v[pq[c].top()] = true, pq[c].pop();
    }
    return 0;
}