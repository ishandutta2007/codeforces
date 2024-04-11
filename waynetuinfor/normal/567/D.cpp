#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
int s[maxn], n, k, a, m;

bool check(int t) {
    // cout << "check t = " << t << endl;
    vector<int> pos; pos.push_back(0);
    for (int i = 1; i <= t; ++i) pos.push_back(s[i]);
    pos.push_back(n + 1);
    sort(pos.begin(), pos.end());
    int got = 0;
    for (size_t i = 1; i < pos.size(); ++i) {
        int len = pos[i] - 1 - pos[i - 1];
        // cout << "len = " << len << endl;
        got += (len + 1) / (a + 1);
    }
    // cout << "got = " << got << endl;
    return got < k;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> k >> a;
    cin >> m;
    for (int i = 1; i <= m; ++i) cin >> s[i];
    int d = 21, ans = m + 1;
    while (d--) if (ans - (1 << d) >= 0) if (check(ans - (1 << d))) ans -= (1 << d);
    cout << (ans == m + 1 ? -1 : ans) << endl;
    return 0;
}