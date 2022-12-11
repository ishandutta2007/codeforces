#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 1e5 + 7;

bool ok(int a, int b, int d, int n) {
    return (a + (b - 1) * (d + 1) + 1 <= n);
}

signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, d, m, s1 = 0, s2 = 0, maxi = 0;
    vector <int> mr, ls;
    cin >> n >> d >> m;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x > m) mr.push_back(x);
        else ls.push_back(x);
    }
    sort(mr.begin(), mr.end(), greater <int>());
    sort(ls.begin(), ls.end(), greater <int>());
    int a = 0, b = 0;
    while (b != (int) mr.size() && ok(a, b + 1, d, n)) {
        s2 += mr[b];
        b++;
    }
    maxi = s2;
    for (int i = 1; i <= (int) ls.size(); i++) {
        a++;
        s1 += ls[i - 1];
        while (b != 0 && !ok(a, b, d, n)) {
            s2 -= mr[b - 1];
            b--;
        }
        maxi = max(maxi, s1 + s2);
    }
    cout << maxi << endl;
    return 0;
}