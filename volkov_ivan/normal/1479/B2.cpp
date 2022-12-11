#include <bits/stdc++.h>
//#define int long long

using namespace std;

signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int a[n + 1];
    a[0] = 0;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    int dp = 0;
    set <int> ends;
    ends.insert(0);
    for (int i = 1; i <= n; i++) {
        bool we = (a[i] == a[i - 1]);
        bool other = (ends.find(a[i]) != ends.end());
        if (!we && !other) {
            dp++;
            ends.insert(a[i - 1]);
        }
        if (we && !other) {

        }
        if (other && !we) {
            ends.clear();
            ends.insert(a[i - 1]);
        }
        if (other && we) {

        }
    }
    cout << dp << endl;
    return 0;
}