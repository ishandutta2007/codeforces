#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 2e5 + 10;
int a[maxn];

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    vector<int> sq, nsq, t;
    for (int i = 0; i * i <= 2000000000; ++i) t.push_back(i * i);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        int s = (int)sqrt(a[i]);
        if (s * s == a[i]) sq.push_back(a[i]);
        else nsq.push_back(a[i]);
    }
    if (sq.size() >= nsq.size()) {
        sort(sq.begin(), sq.end()); reverse(sq.begin(), sq.end());
        int ans = 0;
        for (int i = 0; i < sq.size() - n / 2; ++i) {
            if (sq[i] == 0) ans += 2;
            else ++ans;
        }
        cout << ans << endl;
        return 0;
    }
    vector<int> tar;
    for (int i : nsq) {
        int p = lower_bound(t.begin(), t.end(), i) - t.begin();
        if (p == 0) tar.push_back(t[p - i]);
        else tar.push_back(min(t[p] - i, i - t[p - 1]));
    }
    sort(tar.begin(), tar.end());
    int ans = 0;
    for (int i = 0; i < nsq.size() - n / 2; ++i) ans += tar[i];
    cout << ans << endl;
}