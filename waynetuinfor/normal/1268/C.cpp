#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; scanf("%d", &n);
    vector<int> p(n), pos(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &p[i]);
        p[i]--;
        pos[p[i]] = i;
    }
    priority_queue<int, vector<int>, less<int>> lq;
    priority_queue<int, vector<int>, greater<int>> rq;
    long long lsum = 0, rsum = 0;
    int sz = 0;

    auto Push = [&](int v) {
        if (!lq.empty() && v < lq.top()) lq.push(v), lsum += v;
        else rq.push(v), rsum += v;
        sz++;
        while (lq.size() > (sz + 1) / 2) {
            rq.push(lq.top());
            lsum -= lq.top();
            rsum += lq.top();
            lq.pop();
        }
        while (rq.size() > sz / 2) {
            lq.push(rq.top());
            lsum += rq.top();
            rsum -= rq.top();
            rq.pop();
        }
    };

    vector<int> fw(n + 1);

    auto Modify = [&](int p, int v) {
        for (int i = p + 1; i <= n; i += i & -i) fw[i] += v;
    };

    auto Query = [&](int p) {
        int res = 0;
        for (int i = p + 1; i > 0; i -= i & -i) res += fw[i];
        return res;
    };

    long long inv = 0;
    for (int i = 0; i < n; ++i) {
        Push(pos[i]);
        assert(!lq.empty());
        inv += Query(n - 1) - Query(pos[i]);
        int med = lq.top();
        long long ans = 1LL * med * lq.size() - lsum + rsum - 1LL * med * rq.size();
        if (lq.size() > 1) {
            int lsz = lq.size() - 1;
            ans -= 1LL * lsz * (lsz + 1) / 2;
        }
        if (!rq.empty()) {
            int rsz = rq.size();
            ans -= 1LL * rsz * (rsz + 1) / 2;
        }
        Modify(pos[i], 1);
        printf("%lld ", ans + inv);
    }
    puts("");
    return 0;
}