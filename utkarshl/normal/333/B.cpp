#include"stdio.h"
int main() {
    int N,M;
    scanf("%d%d",&N,&M);
    bool xs[N], ys[N];
    for(int i=0;i<N;i++)
        xs[i] = ys[i] = 1;
    while(M--) {
        int x, y;
        scanf("%d%d", &x, &y);
        xs[--x]=0, ys[--y]=0;
    }
    int cnt=0;
    for(int x=1;x<N-1;x++)
        cnt+=xs[x]+(int)ys[x];
    if(N%2 and xs[N/2] and ys[N/2])cnt--;
    printf("%d\n", cnt);
}