#include <bits/stdc++.h>

using namespace std;

const int N = 5e2 + 10;
const int MOD = 998244353;


int ans[N][N];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int r, c;
    cin >> r >> c;
    if (r == 1 && c == 1) {
        cout << 0;
        return 0;
    }

    if (r <= c) {
        for(int i = 1; i <= r; i++) {
            for(int j = 1; j <= c; j++) cout << i * (j + r) << " ";
            cout << '\n';
        }
    } else {
        for(int i = 1; i <= r; i++) {
            for(int j = 1; j <= c; j++) cout << j * (i + c) << " ";
            cout << '\n';
        }
    }
    
}