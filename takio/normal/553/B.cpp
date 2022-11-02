#include <stdio.h>
#include <map>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
#include <iostream>
#define LL long long
#define pii pair <int, int>
using namespace std ;

const int N = 60;

int n, a[N];
LL f[N];

int main () {
//    freopen ("in.txt", "r", stdin);
    f[0] = 1; f[1] = 1;
    for (int i = 2; i < N; i++) f[i] = f[i - 1] + f[i - 2];
    LL k;
    while (cin >> n >> k) {
        k--;
        LL now = n - 1, tmp;
        for (int i = 1; i <= n; ) {
            tmp = f[now];
            if (k < tmp) a[i] = i, i++, now--;
            else k -= tmp, a[i] = i + 1, a[i + 1] = i, i += 2, now -= 2;
        }
        for (int i = 1; i <= n; i++) cout << a[i] << ' '; cout << endl;
    }
}