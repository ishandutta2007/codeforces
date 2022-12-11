#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    pair <int, int> l[m];
    int p[m];
    int summ = 0;
    for (int i = 0; i < m; i++) {
        cin >> l[i].first;
        summ += l[i].first;
        l[i].second = i;
    }
    if (summ < n || m > n) {
        cout << -1 << endl;
        return 0;
    }
    int cur = 0, rght = 0;
    for (int i = 0; i < m; i++) {
        //int lft = max(cur + 1, n - summ + 1);
        int rest = summ - l[i].first, free = n - rght;
        int lft = cur + 1;
        if (rest < free) {
            lft = max(lft, n - summ + 1);
        }
        if (lft + l[i].first - 1 > n) {
            cout << -1 << endl;
            return 0;
        }
        summ -= l[i].first;
        p[l[i].second] = lft;
        cur = lft;
        rght = max(rght, lft + l[i].first - 1);
    }
    for (int i = 0; i < m; i++) cout << p[i] << ' ';
    cout << endl;
    return 0;
}