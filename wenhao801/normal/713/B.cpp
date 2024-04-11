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

int n;
int query (int x1, int x2, int y1, int y2) {
    printf("? %d %d %d %d\n", x1, y1, x2, y2); fflush(stdout);
    int res; scanf("%d", &res); return res;
}
int _l1, _r1, _l2,_r2;
int query2 (int x1, int x2, int y1, int y2) {
    return query(x1, x2, y1, y2) - (x1 <= _l1 && _r1 <= x2 && y1 <= _l2 && _r2 <= y2);
}


int main () {
    scanf("%d", &n);
    int l, r, L1, R1, L2, R2;
    l = 1, r = n; while (l <= r) {
        int mid = (l + r) >> 1;
        if (query(1, mid, 1,n )) R1 = mid, r = mid -1;
        else l = mid + 1;
    }
    l = 1, r = R1; while (l <= r) {
        int mid = (l + r) >> 1;
        if (query(mid, R1, 1, n)) L1 = mid, l = mid + 1;
        else r = mid - 1;
    }
    l = 1, r = n; while (l <= r) {
        int mid = (l + r) >> 1; 
        if (query(L1, R1, 1, mid)) R2 = mid, r = mid -1 ;
        else l = mid + 1;
    }
    l = 1, r = R2; while (l <= r) {
        int mid = (l + r) >> 1;
        if (query(L1, R1, mid, R2)) L2 = mid, l = mid + 1;
        else r = mid -1;
    }
    _l1 = L1, _l2 = L2, _r1 = R1, _r2 = R2;

    l = 1, r = n; while (l <= r) {
        int mid = (l + r) >> 1;
        if (query2(1, mid, 1,n )) R1 = mid, r = mid -1;
        else l = mid + 1;
    }
    l = 1, r = R1; while (l <= r) {
        int mid = (l + r) >> 1;
        if (query2(mid, R1, 1, n)) L1 = mid, l = mid + 1;
        else r = mid - 1;
    }
    l = 1, r = n; while (l <= r) {
        int mid = (l + r) >> 1; 
        if (query2(L1, R1, 1, mid)) R2 = mid, r = mid -1 ;
        else l = mid + 1;
    }
    l = 1, r = R2; while (l <= r) {
        int mid = (l + r) >> 1;
        if (query2(L1, R1, mid, R2)) L2 = mid, l = mid + 1;
        else r = mid -1;
    }

    printf("! %d %d %d %d %d %d %d %d\n", _l1, _l2, _r1, _r2, L1, L2, R1, R2);
    return 0;
}