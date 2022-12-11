#include <bits/stdc++.h>
//#define int long long

using namespace std;

const int N = 30;
char ans[N][N];

signed main() {
    fill(ans[0], ans[0] + N * N, '.');
    int n;
    cin >> n;
    if (n == 2) {
        cout << "-1" << endl;
        return 0;
    }
    n--;
    ans[0][0] = 'o';
    int cur_x = 1, cur_y = 0;
    while (n != 0) {
        if (cur_y == cur_x) {
            ans[cur_y][cur_x] = 'o';
            cur_y = 0;
            cur_x++;
            n--;
            continue;
        }
        if (n > 1) {
            ans[cur_y][cur_x] = ans[cur_x][cur_y] = 'o';
            n -= 2;
            cur_y++;
            continue;
        }
        ans[cur_x - 1][cur_x - 1] = '.';
        if (cur_y == cur_x - 1) {
            cur_x++;
            cur_y = 0;
        }
        ans[cur_x][cur_y] = ans[cur_y][cur_x] = 'o';
        cur_y++;
        n = 0;
    }
    if (cur_y == 0)
        cur_x--;
    cout << cur_x + 1 << "\n";
    for (int y = cur_x; y >= 0; y--) {
        for (int x = 0; x <= cur_x; x++) {
            cout << ans[x][y];
        }
        cout << "\n";
    }
}