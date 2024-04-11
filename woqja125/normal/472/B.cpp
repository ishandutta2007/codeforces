#include<stdio.h>
#include<algorithm>
int f[2001];
int main()
{
    int n, k, i, j, s = 0;
    scanf("%d%d", &n, &k);
    for(i=1; i<=n; i++)scanf("%d", f+i);
    std::sort(f+1, f+1+n);
    for(i=n; i>=1; i-=k)
    {
        s += (f[i]-1)*2;
    }
    printf("%d", s);
    return 0;
}