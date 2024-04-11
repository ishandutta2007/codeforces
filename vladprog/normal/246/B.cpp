#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    int s=0;
    for(int i=1;i<=n;i++)
    {
        int a;
        scanf("%d",&a);
        s+=a;
    }
    if(s%n==0)
        printf("%d\n",n);
    else
        printf("%d\n",n-1);
}