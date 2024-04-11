#include <bits/stdc++.h>
using namespace std;

int n;

int main()
{
    scanf("%d",&n);
    if(n%2==1)
    {
        printf("-1");
        return 0;
    }
    for(int i=1;i<=n;i+=2)
    {
        printf("%d %d ",i+1,i);
    }
}