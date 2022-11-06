#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
int a[maxn], b[maxn], p[maxn], id[maxn], l[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m, k; cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) cin >> a[i];
    int ind = 0, cnt = 0; 
    while (ind < n) {
        for (int i = 0; i < k && ind < n; ++i, ++ind) b[a[ind]] = cnt, id[a[ind]] = i;
        ++cnt;
    }
    for (int i = 1; i < n; ++i) {
        p[a[i]] = a[i - 1];
    }
    for (int i = 0; i < n - 1; ++i) l[a[i]] = a[i + 1];
    long long ans = 0;
    while (m--) {
        int x; cin >> x;
        if (b[x] == 0 && id[x] == 0) { ++ans; continue; }
        ans += b[x] + 1;
        int tmp = p[x], ss = l[x], fuck = p[tmp]; 
        p[x] = p[p[x]]; l[x] = tmp;
        p[tmp] = x; l[tmp] = ss;
        p[ss] = tmp; l[fuck] = x;
        swap(b[x], b[tmp]); swap(id[x], id[tmp]);
    }
    cout << ans << endl;
    return 0;
}