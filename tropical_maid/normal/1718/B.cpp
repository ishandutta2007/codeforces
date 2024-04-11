#include <bits/stdc++.h>

using namespace std;

const int M = 1e9 + 1;
int k, m;
int F[50];
int C[101];
int A[50];

bool check() {
    bool res = true;
    bool zero = false;
    for (int i = 0; i < m; ++i) {
        if (A[i] > 1) res = false;
        else if (A[i] == 0) zero = true;
        else if (zero) res = false;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    F[0] = F[1] = 1;
    for (m = 2; ; ++m) {
        F[m] = F[m - 1] + F[m - 2];
        if (F[m] >= M) break;
    }
    int T;
    cin >> T;
    while (T--) {
        cin >> k;
        for (int i = 1; i <= k; ++i) cin >> C[i];
        for (int i = 0; i < m; ++i) A[i] = 0;
        int mx = 0;
        for (int i = 1; i <= k; ++i) {
            int x = C[i];
            for (int j = m - 1; j >= 0; --j) {
                if (x >= F[j]) x -= F[j], ++A[j], mx = max(mx, j), --j;
            }
        }
        if (A[1] > 1 || (k == 1 && C[1] == 1)) --A[1], ++A[0];
        bool ans = check();
        if (!ans && A[0] == 0) {
            int last;
            for (last = 0; last < mx && A[last] == 0; last += 2) ++A[last];
            --last;
            if (--A[last] >= 0) {
                bool pos = false;
                for (int i = 1; i <= k; ++i) {
                    int x = C[i];
                    int last2;
                    for (int j = m - 1; j >= 0; --j) {
                        if (x >= F[j]) x -= F[j], last2 = j, --j;
                    }
                    if (last2 == last) pos = true;
                }
                if (pos && check()) ans = true;
            }
        }
        printf(ans ? "YES\n" : "NO\n");
    }
}