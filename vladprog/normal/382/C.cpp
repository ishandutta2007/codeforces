#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    if(n==1)
        return printf("-1\n"),0;
    int a[n];
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    sort(a,a+n);
    int d=min(a[1]-a[0],a[n-1]-a[n-2]);
    int k=0,ind;
    for(int i=0;i<n-1;i++)
        if(a[i+1]-a[i]!=d)
            k++,ind=i;
    //printf("d=%d , k=%d , ind=%d , a[ind]=%d , a[ind+1]=%d\n",
    //       d,k,ind,a[ind],a[ind+1]);
    if(d==0&&k==0)
        printf("1\n%d\n",a[0]);
    else if(n==2)
        if((a[1]-a[0])%2)
            printf("2\n%d %d\n",a[0]-d,a[1]+d);
        else
            printf("3\n%d %d %d\n",a[0]-d,(a[0]+a[1])/2,a[1]+d);
    else if(k>1||(k==1&&((a[ind]+d*2)!=a[ind+1])))
        printf("0\n");
    else if(k==1)
        printf("1\n%d\n",a[ind]+d);
    else
        printf("2\n%d %d\n",a[0]-d,a[n-1]+d);
}