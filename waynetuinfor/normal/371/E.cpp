#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e5 + 10;
const long long inf = LLONG_MAX;
long long s[maxn], ss[maxn], sx[maxn];
int x[maxn];
map<int, int> pos;

int main() {
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", x + i), pos[x[i]] = i;
    sort(x + 1, x + 1 + n);
    for (int i = 1; i <= n; ++i) {
        s[i] = s[i - 1] + x[i];
        ss[i] = ss[i - 1] + s[i];
        sx[i] = sx[i - 1] + i * 1ll * x[i];
    }
    int k; scanf("%d", &k);
    long long ans = inf;
    int fr = -1;
    for (int a = 1; a + k - 1 <= n; ++a) {
        long long cur = -(a + k - 1) * 1ll * (s[a + k - 1] - s[a - 1]);
        cur += k * s[a + k - 1] - ss[a + k - 1] + ss[a - 1] + sx[a + k - 1] - sx[a - 1];
        if (cur < ans) ans = cur, fr = a;
    }
    vector<int> v;
    for (int i = fr; i <= fr + k - 1; ++i) v.push_back(pos[x[i]]);
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); ++i) printf("%d ", v[i]);
    puts("");
    return 0;
}