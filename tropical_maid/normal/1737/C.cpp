#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, R[4], C[4];
        cin >> n;
        for (int i = 0; i < 4; ++i) cin >> R[i] >> C[i];
        int cntA[2] = {}, cntB[4] = {}, cntC = 0;
        for (int i = 0; i < 3; ++i) {
            int a = (R[i] + C[i]) % 2;
            int b = R[i] % 2;
            ++cntA[a];
            ++cntB[a * 2 + b];
            if (R[i] == 1 || R[i] == n || C[i] == n || C[i] == 1) ++cntC;
        }
        bool pos = false;
        if (cntC == 3) {
            for (int i = 0; i < 3; ++i) for (int j = i + 1; j < 3; ++j) {
                if (C[i] == C[j] && C[j] == C[3]) pos = true;
                if (R[i] == R[j] && R[j] == R[3]) pos = true;
            }
        }
        else {
            int a = (R[3] + C[3]) % 2;
            int b = R[3] % 2;
            if (cntA[a] == 1) pos = cntB[a * 2 + b] == 1;
            else pos = true;
        }
        printf(pos ? "YES\n" : "NO\n");
    }
    return 0;
}