#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 10, inf = 1e6 + 1;
int l[maxn], r[maxn], a[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    long long ans = 0;
    a[0] = 0; a[n + 1] = 0;
    stack<int> s; s.push(0);
    for (int i = 1; i <= n; ++i) {
        while (s.size() && a[s.top()] > a[i]) s.pop();
        l[i] = s.top();
        s.push(i);
    }
    s = stack<int>(); s.push(n + 1);
    for (int i = n; i > 0; --i) {
        while (s.size() && a[s.top()] >= a[i]) s.pop();
        r[i] = s.top();
        s.push(i);
    }
    for (int i = 1; i <= n; ++i) ans -= (long long)(r[i] - i) * (long long)(i - l[i]) * (long long)a[i];
    a[0] = inf; a[n + 1] = inf;
    s = stack<int>(); s.push(0);
    for (int i = 1; i <= n; ++i) {
        while (s.size() && a[s.top()] < a[i]) s.pop();
        l[i] = s.top();
        s.push(i);
    }
    s = stack<int>(); s.push(n + 1);
    for (int i = n; i > 0; --i) {
        while (s.size() && a[s.top()] <= a[i]) s.pop();
        r[i] = s.top();
        s.push(i);
    }
    for (int i = 1; i <= n; ++i) ans += (long long)(r[i] - i) * (long long)(i - l[i]) * (long long)a[i];
    cout << ans << endl;
    return 0;
}