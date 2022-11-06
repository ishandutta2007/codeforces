#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;
int n, a[maxn];

int check(int d) {
    vector<int> vv;
    bool ok = false;
    for (int i = 0; i < n - 1; ++i) {
        if (d >= a[i] && d <= a[i + 1]) {
            for (int j = 0; j <= i; ++j) vv.push_back(a[j]);
            vv.push_back(d);
            for (int j = i + 1; j < n; ++j) vv.push_back(a[j]);
            ok = true;
            break;
        }
    }
    if (!ok) {
        if (d > a[n - 1]) {
            for (int i = 0; i < n; ++i) vv.push_back(a[i]);
            vv.push_back(d);
        } else {
            vv.push_back(d);
            for (int i = 0; i < n; ++i) vv.push_back(a[i]);
        }
    }
    reverse(vv.begin(), vv.end());
    long long s = 0, t = 0;
    int m = n + 1, pp = 0;
    for (int i = 0; i < (int)vv.size(); ++i) s += vv[i];
    if (s > m * 1ll * (m - 1)) return 1;
    vector<int> qu;
    int left = 1;
    for (int i = (int)vv.size() - 1; i >= 0; --i) {
        s -= vv[i];
        if (vv[i] == d) left = 0;
        qu.push_back(vv[i]);
        t += vv[i];
        while (qu.size() && qu.back() > i) {
            t -= qu.back();
            qu.pop_back();
            ++pp;
        }
        if (s > i * 1ll * (i - 1) + t + pp * 1ll * i) {
            if (left) return 1;
            else return -1;
        }
    } 
    return 0;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    sort(a, a + n);
    long long sum = accumulate(a, a + n, 0ll);
    int f = sum % 2;
    if (check(f) != 0) for (int d = 20; d >= 0; --d) {
        int nxt = f + 2 * (1 << d);
        if (nxt > n) continue;
        int res = check(nxt);
        if (res == 0) {
            f = nxt;
            break;
        }
        if (res == -1) f = nxt;
    }
    int l = f, r = f;
    if (check(f) != 0) {
        puts("-1");
        return 0;
    }
    for (int d = 20; d >= 0; --d) {
        if (r + 2 * (1 << d) <= n && check(r + 2 * (1 << d)) == 0) r += 2 * (1 << d);
        if (l - 2 * (1 << d) >= 0 && check(l - 2 * (1 << d)) == 0) l -= 2 * (1 << d);
    }
    for (int i = l; i <= r; i += 2) printf("%d ", i); puts("");
    return 0;
}