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

char s[30][30], t[30][30];
int n, m, _, Q, x;
int main() {
    while (~scanf("%d%d", &n, &m)) {
        for (int i = 0; i < n; ++i)
            scanf("%s", s[i]);
        for (int i = 0; i < m; ++i)
            scanf("%s", &t[i]);
        scanf("%d", &Q);
        while (Q--) {
            scanf("%d", &x);
            x--;
            x %= (n * m);
            printf("%s%s\n", s[x % n], t[x % m]);
        }
    }
    return 0;
}

/*

*/