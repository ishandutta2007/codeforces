#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

inline int read () {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

vector <int> out;
int main () {
    int T = read();
    while (T--) {
        int n = read(), cnt[66] = {};
        for (int j = 1; j <= n; j++) {
            int x = read();
            for (int i = 0; i < 30; i++) cnt[i] += x & 1, x >>= 1;
        }
        int ans = cnt[0]; for (int i = 1; i <= 30; i++) ans = __gcd(ans, cnt[i]);
        if (!ans) { for (int i = 1; i <= n; i++) cout << i << ' '; cout << endl; continue; }
        out.clear();
        for (int i = 1; i * i <= ans; i++) if (ans % i == 0) {
            out.push_back(i);
            if (i * i != ans) out.push_back(ans/ i);
        }sort(out.begin(), out.end());
        for (auto i: out) cout << i << ' '; cout << endl;
    }
    return 0;
}