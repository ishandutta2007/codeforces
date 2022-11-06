#include<stdio.h>
bool isP[1000001];
int main()
{
    int n, i, j;
    isP[1] = false;
    for(i=2; i*i<=1000000; i++)
    {
        if(isP[i] == false)
            for(j=i*2; j<=1000000; j+=i) isP[j] = true;
    }
    scanf("%d", &n);
    for(i=2; i<=n; i++)
    {
        if(isP[i] && isP[n-i])
        {
            printf("%d %d", i, n-i);
            return 0;
        }
    }
}