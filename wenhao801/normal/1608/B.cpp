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

int main () {
    int T = read();
    while (T--) {
        int n = read(), a = read(), b = read();
        if (abs(a - b) > 1) { puts("-1"); continue; }
        int p = (n - 1) / 2, q = (n & 1) ? (p - 1) : p;
        if (max(a, b) <= p && min(a, b) <= q) {
            if (a == b) {
                printf("%d ", n);
                for (int i = 1; i <= a; i++) printf("%d %d ", n - i * 2, n - i * 2 + 1);
                for (int i = n - a * 2 - 1; i >= 1; i--) printf("%d ", i);
                putchar('\n');
            }
            else if (a == b + 1) {
                vector <int> v; v.push_back(1);
                for (int i = 1; i <= b; i++) v.push_back(i * 2 + 1), v.push_back(i * 2);
                v.push_back((b + 1) * 2); int tmp = n - v.size();
                for (auto i: v) printf("%d ", i + tmp);
                for (int i = tmp; i >= 1; i--) printf("%d ", i);
                putchar('\n');
            }
            else {
                vector <int> v; v.push_back(n);
                for (int i = 1; i <= a; i++) v.push_back(n - i * 2), v.push_back(n - i * 2 + 1);
                v.push_back(n - (a + 1) * 2 + 1); int tmp = -(n - (a + 1) * 2 + 1) + 1;
                for (auto i: v) printf("%d ", i + tmp);
                for (int i = v.size() + 1; i <= n; i++) printf("%d ", i);
                putchar('\n');
            }
        }
        else puts("-1");
    }
    return 0;
}