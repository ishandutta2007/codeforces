#include <stdio.h>

int main()
{
    int s[1005], n, i, sum, h, x;
    double ans;
    scanf("%d %d %d", &h, &n, &x);
    for(i=sum=0; i<n; i++)
    {
        scanf("%d", &s[i]); sum+=s[i];
    }
    x--;
    if (sum<h) {printf("-1.000000"); return 0;}
    if (h==1) {printf("0.000000"); return 0;}
    if (s[x]==1) {printf("0.000000"); return 0;}
    if (sum-s[x]<h-1) {printf("1.000000"); return 0;}
    for(ans=1.000000, i=0; i<s[x]-1; i++)
        ans*=(double)(sum-h-i)/(double)(sum-i-1);
    ans=1.000000-ans;
    if (ans>1.000000) ans=1.000000;
    if (ans<0.000000) ans=0.000000;
    printf("%.10lf", ans);
}