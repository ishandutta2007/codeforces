#include <cstdio>
#include <stack>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <iostream>
#include <cmath>
#include <queue>
#define LL long long
using namespace std;

const int N = 200100, M = 2e6 + 100;

int num[M], f[M];

int main () {
    int n, a;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        scanf ("%d", &a);
        num[a] = 1;
    }
    for (int i = 1; i <= 2e6; i++) {
        if (num[i]) f[i] = i;
        else f[i] = f[i - 1];
    }
//    for (int i = 1; i <= 5; i++) cout << f[i] << endl;
    int res = 0;
    for (int i = 2; i <= 1e6; i++) if (num[i]) {
        for (int j = i * 2 - 1; j <= 1e6 + i; j += i) {
            if (j - f[j] < i) res = max (res, f[j] - j + i - 1);
        }
    }
    cout << res << endl;
}