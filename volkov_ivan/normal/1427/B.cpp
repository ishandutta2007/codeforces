#include <bits/stdc++.h>
//#define int long long

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int maxi = (2 * n - 1);
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'W') {
            res++;
            if (i != 0 && s[i - 1] == 'W') res++;
        }
    }
    if (res == 0) {
        cout << max(0, 2 * k - 1) << "\n";
        return;
    }
    vector <int> lens;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'W') {
            int j = i + 1;
            while (j != n && s[j] == 'L') j++;
            if (j != n) {
                lens.push_back(j - i - 1);
            }
        }
    }
    sort(lens.begin(), lens.end());
    res += 2 * k;
    int rest = k;
    for (int elem : lens) {
        if (rest >= elem && elem != 0) {
            res++;
            rest -= elem;
        }
    }
    cout << min(res, maxi) << "\n";
}

signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) solve();
    return 0;
}