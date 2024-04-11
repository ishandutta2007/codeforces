#include <bits/stdc++.h>
using namespace std;
int n,x,tmp=0;
int main()
{
    scanf("%d",&n);
    while (n--)
    {
        scanf("%d",&x);
        if (x%2==0) printf("%d\n",x/2);
        else if (tmp<0)
        {
            ++tmp;
            printf("%d\n",(x+1)/2);
        } else
        {
            --tmp;
            printf("%d\n",(x-1)/2);
        }
    }
    return 0;
}