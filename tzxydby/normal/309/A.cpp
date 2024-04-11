#include<bits/stdc++.h>
const int N=10000009;
int a[N];
int main()
{
    int n,l,t;
	scanf("%d%d%d",&n,&l,&t);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        a[i+n]=a[i]+l;
    }
    int k=2*t/l,p=2*t%l;
    double ans=(double)k*n*(n-1);
    for(int i=0,j=0;i<n;i++)
    {
        while(j<2*n&&a[j]-a[i]<=p)
            j++;
        ans+=j-i-1;
    }
    printf("%.10f\n",ans/4);
    return 0;
}