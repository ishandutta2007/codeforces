#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
int s[maxn], a[maxn], b[maxn];

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", s + i);
    vector<int> o(n); iota(o.begin(), o.end(), 0);
    sort(o.begin(), o.end(), [&](const int &i, const int &j) { return s[i] < s[j]; });
    int z = (n % 3 == 0 ? n / 3 : n / 3 + 1);
    // printf("z = %d\n", z);
    for (int i = z, j = 0; i < n; j += (i % 2), ++i) {
        // printf("i = %d, j = %d\n", i, j);
        if (i & 1) a[o[i]] = j, b[o[i]] = s[o[i]] - a[o[i]];
        else b[o[i]] = j, a[o[i]] = s[o[i]] - b[o[i]];
    }
    for (int i = 0; i < z; ++i) a[o[i]] = s[o[i]], b[o[i]] = 0;
    puts("YES");
    for (int i = 0; i < n; ++i) printf("%d ", a[i]); puts("");
    for (int i = 0; i < n; ++i) printf("%d ", b[i]); puts("");
    return 0;
}