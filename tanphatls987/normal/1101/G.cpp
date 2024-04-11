#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;

int n, a[N];
bitset<N> b[30];
int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) a[i] ^= a[i - 1];
    //for(int i = 1; i <= n; i++) cout << a[i] << " ";
    //cout << '\n';
    if (a[n] == 0) {
        cout << "-1";
        return 0;
    }
    for(int lv = 0; lv < 30; lv++) {
        for(int i = 1; i <= n; i++) b[lv][i] = (a[i] >> lv) & 1;
    }
    int ans = 0;
    for(int col = n; col >= 1; col--) {
        int row = ans;
        while (row < 30 && b[row][col] == 0) row++;
        if (row == 30) continue;
        swap(b[row], b[ans]);
        for(int i = ans + 1; i < 30; i++) if (b[i][col]) 
            b[i] ^= b[ans];
        ans++;
    }
    cout << ans;
}