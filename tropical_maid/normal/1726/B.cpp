#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        if (n % 2 == 1) {
            if (n <= m) {
                printf("Yes\n");
                for (int i = 1; i < n; ++i) printf("1 ");
                printf("%d\n", m - n + 1);
            }
            else {
                printf("No\n");
            }
        }
        else {
            if (n <= m && m % 2 == 0) {
                printf("Yes\n");
                for (int i = 1; i < n - 1; ++i) printf("1 ");
                printf("%d %d\n", (m - n) / 2 + 1, (m - n) / 2 + 1);
            }
            else {
                printf("No\n");
            }
        }
    }
    return 0;
}