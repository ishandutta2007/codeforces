#include<stdio.h>
#include<set>
int gcd(int a, int b){return b?gcd(b, a%b):a;}
int a[5001], g[5001], m;
int b[5001];
int f(int x)
{
    int re=0;
    for(int i=1; i<=m; i++)
    {
        while(x%b[i]==0)
        {
            re--;
            x/=b[i];
        }
    }
    for(int i=2; i*i<=x; i++)
    {
        if(x%i == 0)
        {
            x/=i;
            re++;
            i--;
        }
    }
    if(x!=1) re++;
    return re;
}
int main()
{
    int n, i, j, t;
    scanf("%d%d", &n, &m);
    for(i=1; i<=n; i++)scanf("%d", a+i);
    for(i=1; i<=m; i++)
    {
        scanf("%d", b+i);
    }
    int ans = 0;
    for(i=1; i<=n; i++)
    {
        ans += f(a[i]);
        g[i] = gcd(a[i], g[i-1]);
    }
    int G = 1;
    int c = 0;
    for(i=n; i>=1; i--)
    {
        int t = f(g[i]/G);
        if(t < 0)
        {
            ans -= t*i;
            G = g[i];
        }
    }
    printf("%d", ans);
    return 0;
}