#include <bits/stdc++.h>

using namespace std;

int n;
int p[1000100][10];
int g[1000100];
int f[1000100];

int main() {
    int i;

    for (i=1;i<=1000000;i++) {
        if (i<10) f[i] = g[i] = i;
        else {
            f[i] = f[i/10]*((i%10)?i%10:1);
            g[i] = g[f[i]];
        }
        p[i][g[i]]++;
    }
    for (i=1;i<=1000000;i++) {
        for (int j=0;j<10;j++) p[i][j] += p[i-1][j];
    }
    scanf("%d",&n);
    for (i=0;i<n;i++) {
        int a, b, c;
        scanf("%d%d%d",&a,&b,&c);
        printf("%d\n",p[b][c]-p[a-1][c]);
    }

    return 0;
}