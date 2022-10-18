#include<bits/stdc++.h>
using namespace std;
int a[6];
int main()
{
    for(int i=1;i<=4;i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a+1,a+5);
    printf("%d %d %d\n",a[4]-a[1],a[4]-a[2],a[4]-a[3]);
    return 0;
}