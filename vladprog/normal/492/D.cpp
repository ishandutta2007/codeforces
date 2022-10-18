#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,x,y;
    scanf("%d%d%d",&n,&x,&y);
    for(int i=0;i<n;i++)
    {
        int a;
        scanf("%d",&a);
        int l=0,r=1e9+1;
        while(r-l>1)
        {
            long long m=(l+r)/2,k=m*y/x,s=m+k;
            if(s>=a)
                r=m;
            else
                l=m;
        }
        long long m1=r,k1=m1*y/x,s1=m1+k1;
        l=0,r=1e9+1;
        while(r-l>1)
        {
            long long m=(l+r)/2,k=m*x/y,s=m+k;
            if(s>=a)
                r=m;
            else
                l=m;
        }
        long long m2=r,k2=m2*x/y,s2=m2+k2;
        if(s1==s2)
            printf("Both\n");
        else if(s1<s2)
            printf("Vanya\n");
        else
            printf("Vova\n");
    }
}