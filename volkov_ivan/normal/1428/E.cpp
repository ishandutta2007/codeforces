#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 1e5 + 7, INF = 1e12 + 100;
signed a[N];

int calc0(signed len, signed cnt) {
    if (cnt >= len) return len;
    int x = len / cnt;
    int cntmore = len - x * cnt;
    return x * x * (cnt - cntmore) + (x + 1) * (x + 1) * cntmore;
}

int calc(int len, int cnt) {
    return calc0(len, cnt) - calc0(len, cnt + 1);
}

pair <int, int> split(int n, int lst, int expected = INF) {
    pair <int, int> res = {0, 0};
    for (int i = 0; i < n; i++) {
        signed lft = 0, rght = a[i] + 1, mid;
        while (rght - lft > 1) {
            mid = (lft + rght) / 2;
            if (calc(a[i], mid) >= lst) lft = mid;
            else rght = mid;
        }
        res.first += lft;
        if (res.first > expected) return res;
        res.second += calc0(a[i], lft + 1);
    }
    return res;
}


signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
    int lft = 0, rght = INF, mid;
    sort(a, a + n);
    reverse(a, a + n);
    while (rght - lft > 1) {
        mid = (lft + rght) / 2;
        auto x = split(n, mid, k - n);
        //cout << mid << ' ' << x.first << ' ' << x.second << endl;
        if (x.first <= k - n) rght = mid;
        else lft = mid;
    }
    auto x = split(n, rght);
    cout << x.second - (k - n - x.first) * lft << endl;
    return 0;
}