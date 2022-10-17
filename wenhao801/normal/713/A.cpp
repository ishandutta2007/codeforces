#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

inline int read () {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

int buc[1 << 20];

int main () {
    int q = read();
    while (q--) {
        char s[2]; cin >> s;
        if (s[0] != '?') {
            long long x; cin >> x; int id = 0;
            for (int i = 0; i < 18; i++) id += (x & 1) << i, x /= 10;
            if (s[0] == '+') ++buc[id]; else --buc[id];
        }
        else {
            
            long long x; cin >> x; int id = 0;
            for (int i = 0; i < 18; i++) id += (x & 1) << i, x /= 10;
            cout << buc[id] << endl;
        }
    }
    return 0;
}