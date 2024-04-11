#include <bits/stdc++.h>
using namespace std;

int a[200];
int main() {
    int n, m, i, j, x;
    scanf("%d", &n);
    for(i = 0; i < 2; i++) {
        scanf("%d", &m);
        for(j = 0; j < m; j++) {
            scanf("%d", &x);
            a[x] = 1;
        }
    }
    for(i = 1; i <= n; i++)
        if(!a[i])
            break;
    if(i == n + 1) puts("I become the guy.");
    else puts("Oh, my keyboard!");
    return 0;
}