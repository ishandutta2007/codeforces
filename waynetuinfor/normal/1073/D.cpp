#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;

int main() {
    int n; long long t;
    scanf("%d%lld", &n, &t);
    vector<int> a(n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    long long ans = 0;
    while (a.size()) {
        long long s = accumulate(a.begin(), a.end(), 0ll);
        ans += (t / s) * a.size();
        t %= s;
        for (int i = 0; i < (int)a.size(); ++i) {
            if (t >= a[i]) {
                ans++;
                t -= a[i];
            }
        }
        vector<int> b;
        for (int i = 0; i < (int)a.size(); ++i) {
            if (t >= a[i]) b.push_back(a[i]);
        }
        a = b;
    } 
    printf("%lld\n", ans);
    return 0;
}