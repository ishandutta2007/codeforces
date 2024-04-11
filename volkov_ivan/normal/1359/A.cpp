#include <bits/stdc++.h>
#define int long long 

using namespace std;

signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, m, k;
        cin >> n >> m >> k;
        int one = n / k;
        if (one >= m) {
            cout << m << endl;
            continue;
        }
        int rest = (m - one);
        k--;
        int maxx = (rest + k - 1) / k;
        cout << one - maxx << endl;
    }
    return 0;
}