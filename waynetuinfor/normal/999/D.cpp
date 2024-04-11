#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;
int a[maxn], n, m;
vector<int> c[maxn];

int cost(int x, int t) {
    int r = a[x] % m;
    int c = (t - r + m) % m;
    a[x] += c;
    return c;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]), c[a[i] % m].push_back(i);
    long long ans = 0;
    vector<int> cand;
    for (int z = 0; z < 2; ++z) {
        for (int i = 0; i < m; ++i) {
            while (c[i].size() > n / m) cand.push_back(c[i].back()), c[i].pop_back();
            while (c[i].size() < n / m && cand.size()) {
                ans += cost(cand.back(), i);
                c[i].push_back(cand.back());
                cand.pop_back();
            }
        }
    } 
    printf("%lld\n", ans);
    for (int i = 0; i < n; ++i) printf("%d ", a[i]);
    puts("");
    return 0;
}