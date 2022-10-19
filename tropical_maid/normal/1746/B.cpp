#include <bits/stdc++.h>

using namespace std;

int A[100005];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> A[i];
        }
        int x = 0, y = n + 1;
        for (int ans = 0; ; ++ans) {
            ++x, --y;
            while (x < y && A[x] == 0) ++x;
            while (x < y && A[y] == 1) --y;
            if (x >= y) {
                printf("%d\n", ans);
                break;
            }
        }
    }
    return 0;
}