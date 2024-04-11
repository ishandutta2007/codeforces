#include <cstdio>
#include <vector>
#include <set>

using namespace std;

int main () {
    int n; scanf("%d", &n);
    vector<int> a(n+1), p(n+1);
    vector<long long> f(n+1, 0), ans(n+1, 0);
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        f[i] = f[i-1]+a[i];
    }
    for(int i = 1; i <= n; ++i) scanf("%d", &p[i]);

    set<int> s; long long maxS = 0;
    for(int i = 0; i <= n+1; ++i) s.insert(i);
    for(int i = n; i >= 1; --i) {
        ans[i] = maxS;
        int r = *(++s.find(p[i]));
        int l = *(--s.find(p[i]));
        s.erase(p[i]);
        maxS = max(maxS, f[r-1]-f[l]);
    }

    for(int i = 1; i <= n; ++i) printf("%I64d\n", ans[i]);
}