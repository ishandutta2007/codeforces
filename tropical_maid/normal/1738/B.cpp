#include <bits/stdc++.h>

using namespace std;

long long A[100005];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        for (int i = n - k + 1; i <= n; ++i) cin >> A[i];
        for (int i = n; i > n - k + 1; --i) {
            A[i] -= A[i - 1];
        }
        bool pos = A[n - k + 1] <= A[n - k + 2] * (n - k + 1);
        for (int i = n - k + 3; i <= n; ++i) {
            if (A[i - 1] > A[i]) pos = false;
        }
        if (k == 1) pos = true;
        printf(pos ? "Yes\n" : "No\n");
    }
    return 0;
}