#include<cstring>
#include<cstdio>
int n, a[111111], result, an, ans[111111];
int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    for(int i = 30; i >= 0; i--)
    {
        result = (1 << i) - 1;
        for(int j = 1; j <= n; j++) if(a[j] & (1 << i)) result &= a[j];
        if(result == 0)
        {
            an = 0;
            for(int j = 1; j <= n; j++) if(a[j] & (1<<i)) ans[++an] = a[j];
            printf("%d\n", an);
            for(int j = 1; j <= an; j++) printf("%d%c", ans[j], j==an?'\n':' ');
            return 0;
        }
    }
    fclose(stdin);
    return 0;
}