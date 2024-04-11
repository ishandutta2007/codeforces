#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <iostream>
#include <ctime>
#include <cmath>
#include <queue>
#define pii pair <int, int>
#define LL long long
#define ls rt << 1
#define rs rt << 1 | 1
#define lson ls, l, m
#define rson rs, m + 1, r
#define type double

using namespace std;

int main () {
    int n, k;
    cin >> n >> k;
    int f = 1, e = n;
    for (int i = 1; i < k; i++) {
        if (i & 1) {
            printf ("%d", f++);
            if (i != n) printf (" ");
        } else {
            printf ("%d", e--);
            if (i != n) printf (" ");
        }
    }
    if (k % 2 == 1) {
        for (int i = f; i <= e; i++) {
            printf ("%d", i);
            if (i != e) printf (" ");
        }
    } else {
        for (int i = e; i >= f; i--) {
            printf ("%d", i);
            if (i != f) printf (" ");
        }
    }
}