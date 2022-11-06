#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
long long a[maxn];
int n, cnt[40];
vector<long long> rem;
bool v[maxn];

bool check(int);

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n; for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a, a + n);
    for (int p = 0; p < 40; ++p) {
        auto it = lower_bound(a, a + n, (1LL << p));
        if (*it != (1LL << p)) continue;
        auto itt = upper_bound(a, a + n, (1LL << p));
        cnt[p] = itt - it;
        for (int i = it - a; i < itt - a; ++i) v[i] = true;
    }
    for (int i = 0; i < n; ++i) if (!v[i]) rem.push_back(a[i]);
    int d = 1, ans = cnt[0] + 1;
    while (d <= cnt[0]) d <<= 1;
    while (d >>= 1) if (ans - d >= 0) if (check(ans - d)) ans -= d;
    if (!check(ans)) return cout << "-1\n", 0;
    for (int i = ans; ; ++i) {
        if (cnt[0] >= i) cout << i << ' ';
        else break;
    }
    return cout << '\n', 0;
}

bool check(int m) {
    vector<int> len, c;
    for (int i = 0; i < 40; ++i) c.push_back(cnt[i]);
    for (int i = 0; i < m; ++i) {
        if (!c[0]) return false;
        --c[0];
        int cur = 0;
        for (int j = 1; j < 40; ++j) {
            if (c[j]) ++cur, --c[j];
            else break;
        }
        len.push_back(cur);
    }
    if (len.size() < m) return false;
    priority_queue<long long, vector<long long>, less<long long>> pq(rem.begin(), rem.end());
    for (int i = 0; i < 40; ++i) {
        while (c[i]--) pq.push((1LL << i));
    }
    if (pq.size() > len.size()) return false;
    int ind = 0;
    while (pq.size() && ind < len.size()) {
        if (pq.top() > (1LL << (len[ind] + 1))) return false;
        pq.pop(); ++ind;
    }
    return true;
}