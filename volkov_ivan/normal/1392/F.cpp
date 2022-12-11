#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    long long s = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s += x;
    }
    int gor = n * (n - 1) / 2;
    int rest = s - gor;
    int hole = rest / n;
    int lol = rest % n;
    for (int i = 0; i < n; i++) {
        int res = hole + i;
        if (i < lol) res++;
        cout << res << ' ';
    }
    return 0;
}