#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int a[100000];
int b[100000];

int main() {
    int n,x;
    scanf("%d%d", &n, &x);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for(int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }
    sort(a,a+n);
    sort(b,b+n);
    int ret = 0;
    int bI = 0;
    for(int i = n-1; i > -1; i--)   {
        while(bI < n && a[i] + b[bI] < x)   {
            bI++;
        }
        if(bI == n)
            break;
        bI++;
        ret++;
    }
    printf("%d %d\n", 1, ret);
    return 0;
}