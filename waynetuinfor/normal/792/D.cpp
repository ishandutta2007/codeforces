#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    long long n; cin >> n;
    int q; cin >> q;
    while (q--) {
        long long u; cin >> u;
        long long Max = (long long)log2(n + 1) - 1;
        long long dep = Max;
        long long osas = n + 1;
        while (true) {
            if (((osas) >> 1LL) > u) osas -= (1LL << dep), dep--;
            else if (((osas) >> 1LL) < u) osas += (1LL << dep), dep--;
            else break;
        }
        dep = Max - dep;
        string s; cin >> s;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == 'L') {
                if (dep == Max) continue;
                u -= (1LL << (Max - dep - 1)); ++dep;
            }
            if (s[i] == 'R') {
                if (dep == Max) continue;
                u += (1LL << (Max - dep - 1)); ++dep;
            }
            if (s[i] == 'U') {
                if (dep == 0) continue;
                if ((u / (1LL << (Max - dep)) % 4 == 1)) u += (1LL << (Max - dep));
                else u -= (1LL << (Max - dep));
                dep--;
            }
        }
        cout << u << '\n';
    }
    return 0;
}