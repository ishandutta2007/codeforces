#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e5 + 10;

int l[maxn], r[maxn];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, a, b, t; cin >> n >> a >> b >> t;
    string s; cin >> s;
    l[0] = 1 + b * (s[0] == 'w');
    for (int i = 1; i < n; ++i) l[i] = l[i - 1] + a + 1 + b * (s[i] == 'w');
    r[0] = 0;
    for (int i = n - 1; i > 0; --i) r[i] = r[(i + 1) % n] + a + 1 + b * (s[i] == 'w');
    deque<int> dq;
    int ans = 0;
    for (int i = 1; i < n; ++i) dq.push_back(i);
    for (int i = 0; i < n; ++i) if (l[i] <= t) {
        while (dq.size() && (r[dq.front()] + l[i] + a * i > t || i >= dq.front())) dq.pop_front();
        int p = i + 1;
        if (dq.size()) p += n - dq.front();
        ans = max(ans, p);
    }
    for (int i = 0; i < n; ++i) r[i] += l[0];
    for (int i = 1; i < n; ++i) l[i] -= l[0]; l[0] = 0;
    while (dq.size()) dq.pop_front();
    for (int i = n - 1; i > 0; --i) dq.push_back(i);
    for (int i = n; i >= 1; --i) if (r[i % n] <= t) {
        while (dq.size() && (l[dq.front()] + r[i % n] + a * (n - i) > t || i <= dq.front())) dq.pop_front();
        int p = n - i + 1;
        if (dq.size()) p += dq.front();
        ans = max(ans, p);
    }
    cout << ans << endl;
    return 0;
}