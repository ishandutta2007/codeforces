#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const LL P = 1e9 + 7;
const LL INF = 1e18;
const int N = 2e5 + 5;
mt19937 rng(time(0));

int n, k, a[N], b[N], s[N];

bool check(int x) {
    cerr << x << endl;
    s[0] = 0;
    rep(i, 1, n) b[i] = a[i] >= x ? 1 : -1, s[i] = s[i - 1] + b[i];
    deque<int> Q;
    Q.push_back(0);
    rep(i, 1, n) {
        if (s[i] < s[Q.back()])
            Q.push_back(i);
        int idx = Q.front();
        while (!Q.empty() && Q.front() <= i - k)
            idx = Q.front(), Q.pop_front();
        Q.push_front(idx);
        if (idx <= i - k && s[i] - s[idx] > 0)
            return true;
    }
    return false;
}

int main() {
    scanf("%d%d", &n, &k);
    rep(i, 1, n) scanf("%d", a + i);
    int l = 1, r = n, ans;
    while (l <= r) {
        int mid = l + r >> 1;
        if (check(mid))
            l = mid + 1, ans = mid;
        else
            r = mid - 1;
    }
    printf("%d\n", ans);
    return 0;
}