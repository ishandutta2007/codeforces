#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;
typedef pair<int, int> ii;
int n, a[N];
int m;
int p[N];
vector<ii> qu[N];
struct {
    int b[N];
    void add(int x, int v) {
        while (x < N) {
            b[x] += v;
            x += x & -x;
        }
    }
    int find(int k) {
        int ans = 0;
        for(int i = 20; i >= 0; i--) {
            int pos = ans + (1 << i);
            if (pos >= N) continue;
            if (b[pos] < k) k -= b[pos], ans = pos;
        }
        return ans + 1;
    }
}mBit;

int ans[N];
void solve() {
    for(int i = 1; i <= n; i++) {
        mBit.add(p[i], 1);
        for(auto j : qu[i]) {
            ans[j.second] = a[mBit.find(j.first)];
        }
    }
    for(int i = 1; i <= m; i++) cout << ans[i] << '\n';
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++) p[i] = i;
    sort(p + 1, p + n + 1, [&](int x, int y) {
        if (a[x] == a[y]) return x < y;
        return a[x] > a[y];
    });
    cin >> m;

    for(int i = 1; i <= m; i++) {
        int k, pos;
        cin >> k >> pos;
        qu[k].push_back(ii(pos, i));
    }
    solve();
}