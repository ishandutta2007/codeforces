#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cassert>

using namespace std;

inline int read() {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

using ll = long long;
ll cur[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
string s = "codeforces";

int main() {
    ll k; cin >> k;
    ll prod = 1; int it = 0;
    while (prod < k) {
        prod /= cur[it], ++cur[it], prod *= cur[it];
        ++it; if (it == 10) it = 0;
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 1; j <= cur[i]; j++) putchar(s[i]);
    }
    return 0;
}