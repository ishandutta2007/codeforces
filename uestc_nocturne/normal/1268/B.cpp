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

const int V = 300100;
int a[V];
LL ans;
int n;

int main() {
    while (~scanf("%d", &n)) {
        for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
        LL odd = 0;
        LL even = 0;
        for (int i = 1; i <= n; ++i) {
            if (i % 2 == 0) {
                odd += a[i] / 2;
                even += a[i] / 2 + a[i] % 2;
            } else {
                odd += a[i] / 2 + a[i] % 2;
                even += a[i] / 2;
            }
        }
        ans = min(odd, even);
        printf("%I64d\n", ans);
    }
    return 0;
}

/*
5
3 2 2 2 1
4
3 2 2 1
*/