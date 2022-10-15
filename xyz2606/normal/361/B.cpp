#include<cstring>
#include<cstdio>
int n, k;
int main()
{
    scanf("%d%d", &n, &k);
    if(n == k) printf("-1\n");
    else
    {
        if(n == 1) printf("1\n");
        else
        {
            for(int i = 1; i <= n - k; i++) printf("%d ", i % (n - k) + 1);
            for(int i = n - k + 1; i <= n; i++) printf("%d%c", i, i == n?'\n':' ');
        }
    }
    fclose(stdin);
    return 0;
}