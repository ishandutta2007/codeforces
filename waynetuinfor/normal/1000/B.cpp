#include <bits/stdc++.h>
using namespace std;
//
const int maxn = 1e5 + 5;
long long s1[maxn], s2[maxn];
vector<int> a;

long long solve(int p, int x) {
    if (p & 1) {
        long long ret = x - a[p - 1];
        if (p - 1 > 0) ret += (p - 2 % 2 == 0 ? s2[p - 2] : s1[p - 2]);
        ret += (p % 2 == 1 ? s2[a.size() - 1] - s2[p] : s1[a.size() - 1] - s1[p]);
        return ret;
    } else {
        long long ret = a[p] - x;
        ret += (p - 1 % 2 == 0 ? s2[p - 1] : s1[p - 1]);
        ret += (p % 2 == 0 ? s2[a.size() - 1] - s2[p] : s1[a.size() - 1] - s1[p]);
        return ret;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    a.push_back(0);
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        a.push_back(x);
    }
    a.push_back(m);
    for (int i = 0; i < a.size(); ++i) {
        if (i) s1[i] += s1[i - 1], s2[i] += s2[i - 1];
        if (i & 1) s1[i] += a[i] - a[i - 1];
        else if (i % 2 == 0 && i) s2[i] += a[i] - a[i - 1];
    }
    long long ans = s1[a.size() - 1];
    for (int i = 1; i < a.size(); ++i) {
        if (a[i] - a[i - 1] == 1) continue;
        ans = max(ans, solve(i, a[i - 1] + 1));
        ans = max(ans, solve(i, a[i] - 1));
    }
    cout << ans << endl;
}