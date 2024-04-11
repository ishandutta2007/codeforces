#include<stdio.h>
#include <iostream>
#include <algorithm>
#define LL long long
using namespace std;

const int N = 200100;

struct data {
    int a, k;
} a[N * 2];

bool cmp (data a, data b) {
    return a.a < b.a;
}

int main () {
//    freopen ("in.txt", "r", stdin);
    int n, m;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        scanf ("%d", &a[i].a);
        a[i].k = 1;
    }
    cin >> m;
    for (int i = 1; i <= m; i++) {
        scanf ("%d", &a[i + n].a);
        a[i + n].k = 2;
    }
    sort (a + 1, a + 1 + n + m, cmp);
    int sum1 = n * 3, sum2 = m * 3, res1 = sum1, res2 = sum2, mx = sum1 - sum2;
    for (int i = 1; i <= n + m; i++) {
        if (a[i].k == 1) sum1 --;
        else sum2 --;
        while (a[i].a == a[i + 1].a) {
            i++;
            if (a[i].k == 1) sum1 --;
            else sum2 --;
        }
        if (sum1 - sum2 > mx || (sum1 - sum2 == mx && sum1 > res1)) mx = sum1 - sum2, res1 = sum1, res2 = sum2;
    }
    cout << res1 << ':' << res2;
}