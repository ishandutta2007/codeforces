#include <bits/stdc++.h>
using namespace std;

const int maxn = 100000 + 5;
typedef long long LL;
vector<int> vec;
int fa[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m, v; cin >> n >> m >> v;
    if ((LL)m > (LL)n - 1 + (LL)(n - 3) * (LL)(n - 2) / 2) return cout << "-1\n", 0;
    if (m < n - 1) return cout << "-1\n", 0;
    int a = v == 1 ? 2 : 1;
    for (int i = 1; i <= n; ++i) {
        if (i != a && i != v) vec.push_back(i);
    }
    cout << a << ' ' << v << '\n';
    cout << vec[0] << ' ' << v << '\n';
    fa[a] = v, fa[vec[0]] = v;
    m -= 2;
    for (int i = 0; i < vec.size() - 1; ++i) cout << vec[i] << ' ' << vec[i + 1] << '\n', --m, fa[vec[i + 1]] = vec[i];
    for (int i = vec.size() - 1; i > 0 && m; --i) {
        int x = fa[fa[vec[i]]];
        while (m && x) cout << vec[i] << ' ' << x << '\n', --m, x = fa[x];
    }
    return 0;
}