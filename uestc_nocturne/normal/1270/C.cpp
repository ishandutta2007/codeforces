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

int _, n, x;

int main() {
    LL big = 1;
    for (int i = 0; i < 60; ++i) big *= 2;
    scanf("%d", &_);
    while (_--) {
        scanf("%d", &n);
        LL s1 = 0;
        LL s2 = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &x);
            s1 += x;
            s2 ^= x;
        }
        //printf("%I64d %I64d\n", s1, s2);
        LL a = s2;
        LL b = (s1 + a);
        LL c = 0;
        puts("3");
        printf("%I64d %I64d %I64d\n", a, b, c);
        //printf("%I64d %I64d\n", s1 + a + b + c, s2 ^ a ^ b ^ c);
    }
    return 0;
}

/*
3
4
1 2 3 6
1
8
2
1 1
*/