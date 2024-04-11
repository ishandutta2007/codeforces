#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    int m=n*2-1;
    int a[m];
    int km=0,k0=0,kp=0;
    for(int i=0;i<m;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]<0)km++;
        if(a[i]==0)k0++;
        if(a[i]>0)kp++;
    }
    sort(a,a+m);
    if((!(n%2))&&(km%2))
        if((k0>0)||((kp>0)&&(-a[km-1]>a[km+k0])))
            km++;
        else
            km--;
    for(int i=0;i<km;i++)
        a[i]*=-1;
    int s=0;
    for(int i=0;i<m;i++)
        s+=a[i];//,printf("%d ",a[i]);
    printf("\n%d",s);
}