#include<bits/stdc++.h>

using namespace std;

int main()
{
    int q;
    scanf("%d",&q);
    for(int i=1;i<=q;i++)
    {
        long long n;
        scanf("%I64d",&n);
        if(n==1)
        {
            printf("0\n");
            continue;
        }
        long long l=0,r=2*n;
        while(r-l>1)
        {
            long long k=(l+r)/2,nm=k/2,m=k-nm,p=n-m,vnm=p*(p-1)/2;
            if(nm<=vnm)
                l=k;
            else
                r=k;
        }
        printf("%I64d\n",l);
    }
}