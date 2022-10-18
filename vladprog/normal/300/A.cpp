#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    int a[n],n1=0,n2=0,n3=0,k1=-1,k2=-1,k3=-1;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]<0)
            n1++;
        if(a[i]>0)
            n2++;
        if(a[i]==0)
            n3++;
        if(a[i]<0)
            if(k1==-1)
                k1=i;
            else if(k2==-1)
                k2=i;
            else if(k3==-1)
                k3=i;
    }
    if(n2==0)
    {
        n2+=2;
        n1-=2;
    }
    else
        k2=k3=-1;
    n3+=n1-1;
    n1=1;
    printf("%d %d\n%d ",n1,a[k1],n2);
    for(int i=0;i<n;i++)
        if(a[i]>0||i==k2||i==k3)
            printf("%d ",a[i]);
    printf("\n%d ",n3);
    for(int i=0;i<n;i++)
        if(a[i]==0||(a[i]<0&&i!=k1&&i!=k2&&i!=k3))
            printf("%d ",a[i]);
}