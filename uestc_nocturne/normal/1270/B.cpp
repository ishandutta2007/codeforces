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

const int V = 200100;

int _, n, a[V];
int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
        int l = -1, r = -1;
        for (int i = 1; i < n; ++i) {
            if (abs(a[i] - a[i + 1]) > 1) l = i, r = i + 1;
        }
        if (l == -1) puts("NO");
        else {
            puts("YES");
            printf("%d %d\n", l, r);
        }
    }
    return 0;
}

/*
3
5
1 2 3 4 5
4
2 0 1 9
2
2019 2020
*/