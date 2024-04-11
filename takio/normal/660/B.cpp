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
#define piii pair <int, pii>
#define xx first
#define yy second
#define ls rt << 1
#define rs rt << 1 | 1
#define lson ls, l, m
#define rson rs, m + 1, r
#define psi pair <string, int>
using namespace std;

const int N = 100100;
int a[6][110];
int main () {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) a[1][i] = i * 2 - 1;
    for (int i = 1; i <= n; i++) a[4][i] = i * 2;
    for (int i = 1; i <= n; i++) a[2][i] = i * 2 - 1 + n * 2;
    for (int i = 1; i <= n; i++) a[3][i] = i * 2 + n * 2;
    for (int i = 1; i <= n; i++) {
        if (a[2][i] <= m) cout << a[2][i] << ' ';
        if (a[1][i] <= m) cout << a[1][i] << ' ';
        if (a[3][i] <= m) cout << a[3][i] << ' ';
        if (a[4][i] <= m) cout << a[4][i] << ' ';
    }
}