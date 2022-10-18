#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200005;

int n, a[MAXN];
long long d[MAXN];
set<long long> s;

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        d[i] = d[i-1] + a[i];
    }

    long long ans = 0;

    int l = 0;
    s.insert(d[0]);
    
    for(int r = 1; r <= n; ++r) {
        while (s.count(d[r])) {
            s.erase(d[l]);
            ++l;
        }

        s.insert(d[r]);

        ans += r-l;
    }

    printf("%lld\n", ans);

    return 0;
}