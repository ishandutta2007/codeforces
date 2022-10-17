#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>

using namespace std;

inline int read () {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}
int query (int pos) { printf("? %d\n", pos); fflush(stdout); int ret = read(); return ret; }
void submit (int ans) { printf("! %d\n", ans); fflush(stdout); }

int main () {
    int n = read();
    if (n == 1) { submit(1); return 0; }
    if (query(1) < query(2)) { submit(1); return 0; }
    if (query(n - 1) > query(n)) { submit(n); return 0; }
    int L = 1, R = n - 1;
    while (L < R) {
        if (R == L + 1) { submit(R); return 0; }
        int mid = (L + R) >> 1;
        if (query(mid) < query(mid + 1)) R = mid;
        else L = mid;
    }
    
    return 0;
}