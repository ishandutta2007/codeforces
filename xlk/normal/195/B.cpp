#include <cstdio>
#include <cstring>
#include <iostream>
#include <cstdlib>
using namespace std;
int a[100100];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    if(~m&1)
    {
        a[1] = (m+1)/2;
        for(int i = 2; i <= m; i++)
        if(i&1)
            a[i] = a[i-1] - (i-1); 
        else
            a[i] = a[i-1] + (i-1);
    }
    else
    {
        a[1] = (m+1)/2;
        for(int i = 2; i <= m; i++)
        if(i&1)
            a[i] = a[i-1] + (i-1); 
        else
            a[i] = a[i-1] - (i-1);
    }
    for(int i = 1; i <= n; i++)
    printf("%d\n",a[(i%m)?(i%m):m]);
}