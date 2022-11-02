//
//  main.cpp
//  TaskD
//
//  Created by Vlad Podtelkin on 20.01.14.
//  Copyright (c) 2014 Podtelkin Vladislav. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <memory.h>

#define ZERO 10001
#define BASE 1000000007

using namespace std;

int f[1200][21500];
int b[500500], a[500500], ans, n;

int main(int argc, const char * argv[])
{
    //freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    b[0] = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        b[i] = b[i - 1] + a[i];
    }
    memset(f, 0, sizeof(f));
    f[0][ZERO] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= ZERO + b[i]; j++) {
            if (j < a[i])
                f[i][j] = 0;
            else
                f[i][j] = f[i - 1][j - a[i]];
            if (j + a[i] <= ZERO + b[i])
                f[i][j] += f[i - 1][j + a[i]];
            if (f[i][j] >= BASE)
                f[i][j] -= BASE;
        }
        ans += f[i][ZERO];
        if (ans >= BASE)
            ans -= BASE;
        f[i][ZERO]++;
        if (f[i][ZERO] >= BASE)
            f[i][ZERO] -= BASE;
    }
    printf("%d\n", ans);
    return 0;
}