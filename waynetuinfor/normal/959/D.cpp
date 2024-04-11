#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e6 + 5;
int a[maxn], dv[maxn];
bool v[maxn], u[maxn];

void sieve() {
    vector<int> pr;
    for (int i = 2; i < maxn; ++i) {
        if (!v[i]) pr.push_back(i), dv[i] = i;
        for (int j = 0; i * pr[j] < maxn; ++j) {
            v[i * pr[j]] = true;
            dv[i * pr[j]] = pr[j];
            if (i % pr[j] == 0) break;
        }
    }
}

int main() {
    sieve();
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", a + i);
    set<int> s;
    for (int i = 2; i <= 2000000; ++i) s.insert(i);
    bool z = false;
    for (int i = 0; i < n; ++i) {
        auto it = z ? s.begin() : s.lower_bound(a[i]);
        printf("%d ", *it);
        int t = *it;
        if (t > a[i]) z = true;
        while (t > 1) {
            int d = dv[t];
            if (!u[d]) {
                for (int j = d; j < maxn; j += d) s.erase(j);
                u[d] = true;
            }
            while (t % d == 0) t /= d;
        }
    }
    puts("");
    return 0;
}