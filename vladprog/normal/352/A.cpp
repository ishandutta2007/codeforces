#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    int k0=0,k5=0;
    for(int i=0;i<n;i++)
    {
        int a;
        scanf("%d",&a);
        if(a==0)
            k0++;
        else
            k5++;
    }
    k5/=9;
    if(k0==0)
        printf("-1"),exit(0);
    if(k5==0)
        printf("0"),exit(0);
    for(int i=0;i<k5;i++)
        printf("555555555");
    for(int i=0;i<k0;i++)
        printf("0");
}