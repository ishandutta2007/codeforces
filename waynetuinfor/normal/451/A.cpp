#include <bits/stdc++.h>
using namespace std;

string ans[2] = { "Akshat", "Malvika" };

int main() {
    int n, m; cin >> n >> m;
    int win = 1;
    while (n * m) {
        n--, m--;
        win ^= 1;
    }
    cout << ans[win] << endl;
    return 0;
}