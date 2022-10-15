#include<cstring>
#include<cstdio>
int n, k;
int main()
{
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) printf("%d%c", i == j?k:0, j == n?'\n':' ');
}