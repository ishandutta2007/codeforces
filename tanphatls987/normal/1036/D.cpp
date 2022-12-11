#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 10;

int n[2], a[2][N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0; i <= 1; i++) {
        cin >> n[i];
        for (int j = 1; j <= n[i]; j++) cin >> a[i][j];
    }
    int ans = 0;
    long long v1 = a[0][1], v2 = a[1][1];
    int i0 , i1;
    for (i0 = 1, i1 = 1; i0 <= n[0] && i1 <= n[1] ;){
        if (v1 == v2) {
            ans++;
            v1 = a[0][++i0];
            v2 = a[1][++i1];
            continue;
        }
        if (v1 < v2) v1 += a[0][++i0];
        else v2 += a[1][++i1];
    }
    if (i0 == n[0] + 1 && i1 == n[1] + 1) cout << ans;
    else cout << "-1";
}