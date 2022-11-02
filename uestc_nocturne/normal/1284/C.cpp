/*
Author: elfness@UESTC
*/
#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;
typedef long long LL;

const int V = 250100;
int n, m;
int f[V];

int main() {
    while (~scanf("%d%d", &n, &m)) {
        f[0] = 1;
        for (int i = 1; i <= n; ++i) f[i] = (LL) f[i - 1] * i % m;
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            ans += (LL) (n - i + 1) * (n - i + 1) % m * f[i] % m * f[n - i] % m;
            ans %= m;
        }
        printf("%d\n", ans);
    }
    return 0;
}

/*
1 993244853
2 993244853
3 993244853
2019 993244853
2020 437122297

*/