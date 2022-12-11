#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, v1, v2;

    cin >> n >> v1 >> v2;

    for(int u1 = 0; u1 * v1 <= n; u1++) {
        if ((n - u1 * v1) % v2) continue;

        int u2 = (n - u1 * v1) / v2;
        int st = 1;
        for(int i = 0; i < u1; i++) {
            for(int j = 1; j <= v1; j++) cout << st + (j % v1) << " ";
            st += v1;
        }
        for(int i = 0; i < u2; i++) {
            for(int j = 1; j <= v2; j++) cout << st + (j % v2) << " ";
            st += v2;
        }
        return 0;
    }
    cout << "-1";
}