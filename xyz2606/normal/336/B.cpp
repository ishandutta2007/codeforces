#include<cstring>
#include<cstdio>
#include<cmath>
int m, r;
double ans, s2;
int main()
{
    scanf("%d%d", &m, &r);
    ans = 0;
    s2 = sqrt(2);
    for(int i = 1; i <= m; i++)
    {
        if(i > 1) ans += 2 + s2;
        ans += 2;
        if(i < m) ans += 2 + s2;
        if(i > 2) ans += (i - 2) * 2 * s2 + (double)(i - 2) * (i - 1);
        if(i < m - 1) ans += (m - i - 1) * 2 * s2 + (double)(m - i - 1) * (m - i);
    }
    printf("%.10f\n", ans / m / m * r);
    fclose(stdin);
    return 0;
}