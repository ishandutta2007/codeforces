#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    if(n>=37)
    {
        printf("-1");
        return 0;
    }
    for(int i=0; i<n/2; i++)
    {
        printf("8");
    }
    if(n&1)
    {
        printf("4");
    }
    return 0;
}