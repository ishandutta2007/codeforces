//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,mmx,popcnt")

#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>
#include<ctype.h>

#define N 100005

typedef int64_t ll;

int n;
ll idx;
int x[N], y[N];

int
main(){
    scanf("%d%lld", &n, &idx);
    idx %= 2*n;
    int X, Y;
    scanf("%d%d", &X, &Y);
    for(int i = 0; i < n; i++)
        scanf("%d%d", x + i, y + i);
    int pos = 0;
    while(idx){
        X = 2 * x[pos] - X;
        Y = 2 * y[pos] - Y;
        --idx;
        ++pos;
        pos -= pos == n ? n : 0;
    }
    printf("%d %d\n", X, Y);
	return 0;
}