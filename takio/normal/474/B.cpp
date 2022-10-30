#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <iostream>
#include <ctime>
#define ll long long
#define ls rt << 1
#define rs rt << 1 | 1
#define lson ls, l, m
#define rson rs, m + 1, r

using namespace std;

int a[100100];

int main () {
    int n, t;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        scanf ("%d", &t);
        a[i] = a[i - 1] + t;
//        cout << a[i] << ' ';
    }
    int m;
    cin >> m;
    for (int i = 1; i <= m; i++) {
        scanf ("%d", &t);
        int f = 0, e = n + 1;
        while (f + 1 < e) {
            int m = (f + e) / 2;
            if (a[m] < t) f = m;
            else e = m;
        }
        cout << f + 1 << endl;
    }
}