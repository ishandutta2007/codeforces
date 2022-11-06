#include <bits/stdc++.h>
using namespace std;

const int maxc = 15000000 + 1;
const int maxn = 3e5 + 5;
int dv[maxc], a[maxn], cnt[maxc];
vector<int> pr;

void sieve() {
    for (int i = 2; i < maxc; ++i) {
        if (!dv[i]) pr.push_back(i), dv[i] = i;
        for (int j = 0; i * pr[j] < maxc; ++j) {
            dv[i * pr[j]] = pr[j];
            if (i % pr[j] == 0) break;
        }
    } 
}

int main() {
    sieve();
    int n; scanf("%d", &n);
    int g = 0;
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]), g = __gcd(g, a[i]);
    for (int i = 0; i < n; ++i) a[i] /= g;
    int one = 0;
    for (int i = 0; i < n; ++i) {
        int x = a[i];
        if (x == 1) ++one;
        while (x > 1) {
            int d = dv[x];
            while (x % d == 0) x /= d;
            ++cnt[d];
        }
    }
    if (one == n) {
        puts("-1");
        return 0;
    }
    int ans = 0;
    for (int i = 0; i < pr.size(); ++i) ans = max(ans, cnt[pr[i]]);
    printf("%d\n", n - ans);
    return 0;
}