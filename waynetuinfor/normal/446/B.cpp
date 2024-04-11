#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 5, maxk = 1e6 + 5;
const long long inf = 1e15;
long long r[maxk], c[maxk];
int a[maxn][maxn];

void calc(vector<int> v, long long *a, int n, int k, int p) {
    priority_queue<int> pq(v.begin(), v.end());
    for (int i = 1; i <= k; ++i) {
        int x = pq.top(); pq.pop();
        a[i] = a[i - 1] + x;
        pq.push(x - n * p);
    }
}

int main() {
    int n, m, k, p; scanf("%d%d%d%d", &n, &m, &k, &p);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) scanf("%d", &a[i][j]);
    }
    vector<int> s;
    for (int i = 0; i < n; ++i) {
        s.push_back(0);
        for (int j = 0; j < m; ++j) s.back() += a[i][j];
    }
    calc(s, r, m, k, p);
    s.clear();
    for (int j = 0; j < m; ++j) {
        s.push_back(0);
        for (int i = 0; i < n; ++i) s.back() += a[i][j];
    }
    calc(s, c, n, k, p);
    long long ans = -inf;
    for (int i = 0; i <= k; ++i) {
        long long z = r[i] + c[k - i];
        // z += p * k;
        z -= p * 1ll * i * (k - i);
        ans = max(ans, z);
    }
    printf("%lld\n", ans);
    return 0;
}