#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int n;
int pnim[N], mark[N];

int getst(int sum, int use) {
    if (sum * 2 % use) return -1;
    int tmp = sum * 2 / use + 1 - use;
    if (tmp % 2) return -1;
    return tmp / 2;
}
int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int use = 2; use * (use + 1) / 2 <= i; use++) {
            int L = getst(i, use);
            if (L == -1) continue;
            mark[pnim[L - 1] ^ pnim[L + use - 1]] = i;
        }
        
        while (mark[pnim[i]] == i) pnim[i]++;
        pnim[i] ^= pnim[i - 1];
    }
    int nim = pnim[n] ^ pnim[n - 1];
    if (nim == 0) {
        cout << "-1";
        return 0;
    }
    int ans = 1;
    while (1) {
        int L = getst(n, ++ans);
        if (L == -1) continue;
        if (pnim[L - 1] == pnim[L + ans - 1]) break;
    }
    cout << ans;
}