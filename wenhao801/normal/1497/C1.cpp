#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

inline int read() {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = (ret * 10) + c - '0', c = getchar();
    return ret * t;
}

#define pii pair<int ,int>
pair < pii, int>  get (int n) {
    if (n == 4) { return make_pair(make_pair(1, 1), 2); }
    if (n & 1) return make_pair(make_pair(n >> 1, n >> 1), 1);
    pair <pii, int> qwq = get(n >> 1);
    qwq.first.first *= 2, qwq.first.second *= 2, qwq.second *= 2;
    return qwq;
}

int main () {
    int T = read();
    while (T--) {
        int n = read(), k = read();
        pair <pii, int> asdf = get(n);
        cout << asdf.first.first << ' ' << asdf.first.second << ' ' << asdf.second << endl;
    }
    return 0;
}