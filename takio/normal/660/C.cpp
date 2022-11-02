#include <bits/stdc++.h>
//#include <cstdio>
//#include <cstdlib>
//#include <iostream>
//#include <algorithm>
//#include <cstring>
//#include <set>
//#include <ctime>
#define LL long long
#define pii pair <int, int>
#define piii pair <LL, pii>
#define xx first
#define yy second
#define ls rt << 1
#define rs rt << 1 | 1
#define lson ls, l, m
#define rson rs, m + 1, r
#define psi pair <string, int>
using namespace std;

const int N = 300100;
int a[N];

int main () {
//    freopen ("in.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        scanf ("%d", &a[i]);
    }
    int c = 0, res = 0, l = 0, r = 0;
    for (int i = 1, j = 1; i <= n; i++) {
        if (a[i] == 0) c++;
        while (c > m) {
            if (a[j] == 0) c--;
            j++;
        }
        if (i - j + 1 > res) res = i - j + 1, l = j, r = i;
    }
    cout << res << endl;
//    cout << l << ' ' << r << endl;
    for (int i = 1; i <= n; i++) {
        if (l <= i && i <= r) printf ("1 ");
        else printf ("%d ", a[i]);
    }
}