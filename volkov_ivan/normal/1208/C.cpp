#include <iostream>
#include <cstring>

using namespace std;

const int N = 1007, K = 23;
int ans[N][N];

bool check(int n) {
    for (int i = 0; i < n; i++) {
        int res1 = 0, res2 = 0;
        for (int j = 0; j < n; j++) {
            res1 ^= ans[i][j];
            res2 ^= ans[j][i];
        }
        if (res1 != 0 || res2 != 0) return 0;
    }
    return 1;
}

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    memset(ans, 0, sizeof(ans));
    int n;
    cin >> n;
    for (int t = 0; t < n * n / 8; t++) {
        int i = 2 * (t / (n / 4)), j = 4 * (t % (n / 4));
        int num = 8 * t;
        ans[i][j] = num;
        ans[i + 1][j] = num + 3;
        ans[i][j + 1] = num + 1;
        ans[i + 1][j + 1] = num + 2;
        j += 2;
        num += 4;
        ans[i][j] = num + 3;
        ans[i][j + 1] = num + 2;
        ans[i + 1][j] = num;
        ans[i + 1][j + 1] = num + 1;
    }
    if (!check(n)) cout << "BAD" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << ans[i][j] << ' ';
        }
        cout << "\n";
    }
    return 0;
}