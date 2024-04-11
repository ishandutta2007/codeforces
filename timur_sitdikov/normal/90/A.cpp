#include <stdio.h>

int main()
{
    int a, b, c, ma, mb, mc, ans;
    scanf("%d %d %d", &a, &b, &c);
    ma=(a-1)/2*3; mb=(b-1)/2*3+1; mc=(c-1)/2*3+2; 
    if (a==0) ma=0; if (b==0) mb=0; if (c==0) mc=0;
    ans=(ma>mb? ma: mb);
    ans=(ans>mc? ans: mc);
    printf("%d", ans+30);
}