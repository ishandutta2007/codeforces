#include <bits/stdc++.h>
#define fs first
#define se second
#define y0 qwertyuiop
#define y1 asdfghjkl

/*
Author : Tropical_maid
Created : 2019/08/23, 00:09:07
*/

using namespace std;
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;

int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0);
    printf("?");
    for (int i = 1; i <= 100; ++i) printf(" %d", i);
    printf("\n");
    fflush(stdout);
    int x;
    scanf("%d", &x);
    x &= 127 << 7;
    printf("?");
    for (int i = 1; i <= 100; ++i) printf(" %d", i << 7);
    printf("\n");
    fflush(stdout);
    int y;
    scanf("%d", &y);
    y &= 127;
    printf("! %d\n", x ^ y);
    fflush(stdout);
    return 0;
}