#include <bits/stdc++.h>
using namespace std;

const int maxn = 6000 + 10;
int p[maxn],  pa[maxn];
bool v[maxn];

int find(int now) { return now == pa[now] ? now : pa[now] = find(pa[now]); }
void merge(int a, int b) { a = find(a); b = find(b); pa[a] = b; }

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) pa[i] = i;
    for (int i = 1; i <= n; ++i) cin >> p[i];
    int m; cin >> m;
    int c = n - m, cnow = 0;
    for (int i = 1; i <= n; ++i) if (!v[i]) {
        int now = i; ++cnow;
        while (!v[now]) {
            v[now] = true;
            merge(now, p[now]);
            now = p[now];
        }
    }
    int ptr = 1;
    vector<pair<int, int>> ans;
    while (cnow < c) {
        int kmin = n + 1, cur = p[ptr];
        while (cur != ptr) {
            kmin = min(kmin, cur);
            cur = p[cur];
        }
        if (kmin == n + 1) {
            ++ptr;
            continue;
        }
        ans.emplace_back(ptr, kmin);
        swap(p[ptr], p[kmin]);
        ++cnow;
    }
    ptr = 2;
    while (cnow > c) {
        while (find(ptr) == find(1)) ++ptr;
        ans.emplace_back(1, ptr); 
        merge(ptr, 1);
        --cnow;
    }
    for (auto& i : ans) {
        int a = min(i.first, i.second), b = max(i.first, i.second);
        i = make_pair(a, b);
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (auto i : ans) cout << i.first << ' ' << i.second << ' ';
    return 0;
;}