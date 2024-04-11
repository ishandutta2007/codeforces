#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    map<int, int> cnt;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        cnt[a[i]]++;
        if (a[i] != b[i]) {
            cnt[b[i]]++;
        }
    }
    map<int, int> was;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        if (cnt[a[i]] >= (n + 1) / 2 && !was[a[i]]) {
            v.push_back(a[i]);
            was[a[i]] = 1;
        }
        if (cnt[b[i]] >= (n + 1) / 2 && !was[b[i]]) {
            v.push_back(b[i]);
            was[b[i]] = 1;
        }
    }
    const int inf = 2e9;
    int ans = inf;
    for (int c : v) {
        vector<int> l;
        for (int i = 0; i < n; i++) {
            if (a[i] == c) {
                l.push_back(0);
            } else {
                if (b[i] == c) {
                    l.push_back(1);
                }
            }
        }
        sort(l.begin(), l.end());
        int tmp = 0;
        for (int j = 0; j < (n + 1) / 2; j++) {
            tmp += l[j];
        }
        ans = min(ans, tmp);
    }
    if (ans == inf) {
        cout << -1 << '\n';
    } else {
        cout << ans << '\n';
    }
    return 0;
}