#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, b, g;
    cin >> b >> g >> n;
    vector <int> cl[n + 1];
    int cnt = 0;
    for (int i = 0; i <= min(n, b); i++) {
        int cur_g = n - i;
        if (cur_g > g) continue;
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}