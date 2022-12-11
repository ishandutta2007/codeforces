#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 2e5 + 7;
int a[N];
int pref1[N], pref2[N];
int n;

int get_pref(int len) {
    if (len == 0) return 0;
    int l = 0, r = n + 1, mid;
    while (r - l > 1) {
        mid = (l + r) / 2;
        if (pref1[mid - 1] < len) l = mid;
        else r = mid;
    }
    int rest = len - pref1[l - 1];
    return pref2[l - 1] + rest * (rest + 1) / 2;
}

int get(int l, int r) {
    if (l <= 0) l += pref1[n];
    //cout << l << ' ' << r << endl;
    if (l <= r) return get_pref(r) - get_pref(l - 1);
    return pref2[n] - (get_pref(l - 1) - get_pref(r));
}

signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    int x;
    cin >> n >> x;
    for (int i = 1; i <= n; i++) cin >> a[i];
    pref1[0] = pref2[0] = 0;
    int maxi = 0;
    for (int i = 1; i <= n; i++) {
        pref2[i] = pref2[i - 1] + (a[i] * (a[i] + 1)) / 2;
        pref1[i] = pref1[i - 1] + a[i];
    }
    for (int i = 1; i <= n; i++) {
        maxi = max(maxi, get(pref1[i] - x + 1, pref1[i]));
        //cout << "!! " << i << ' ' << maxi << endl;
    }
    cout << maxi << endl;
}