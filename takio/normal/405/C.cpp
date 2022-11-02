#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstring>

using namespace std;

int a[1010][1010];

int rec1[1010], rec2[1010];

int main () {
//    freopen ("in.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);
    }
    int res = 0;
    for (int i = 1; i <= n; i++){
        res ^= a[i][i];
    }
    int q;
    cin >> q;
    for (int i = 1; i <= q; i++){
        int t;
        scanf ("%d" ,&t);
        if (t != 3){
            scanf ("%d" ,&t);
            res ^= 1;
        }
        else printf("%d", res);
    }
}