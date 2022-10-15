#include<cstring>
#include<cstdio>
int n;
double y, sum;
int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%*lf%lf", &y);
        sum += y;
    }
    printf("%.3f\n", 5 + sum / n);
    fclose(stdin);
    return 0;
}