#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;
#define int long long
inline int read () {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

int p[1001000], top = 0;
bool np[1001000];

void genp () {
    int i, j;
    for (i = 2; i <= 1000000; i++) {
        if (!np[i]) p[++top] = i;
        for (j = 1; j <= top; j++) {
            if (i * p[j] > 1000000) break;
            np[i * p[j]] = true;
        }
    }
}

signed main () {
    genp(); 
    int T = read();
    while (T--) {
        int n = read(), k = read();
        int i, j;
        if (n % 2 == 0) {
            cout << n + k * 2 << endl;
            continue;
        }
        for (i = 2; i <= top; i++) if (n % p[i] == 0) {
            k--;
            n += p[i];
            break;
        }
        cout << n + k * 2 << endl;
    }
    return 0;
}