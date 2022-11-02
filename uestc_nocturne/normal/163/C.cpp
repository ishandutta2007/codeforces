#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<cmath>
#include<vector>
#include<string>
using namespace std;
typedef long long LL;
const int V=200100;
double a[V],ret[V];
int i,l,r,n,L,v1,v2;
int main()
{
    while(~scanf("%d%d%d%d",&n,&L,&v1,&v2))
    {
        double t=1.0*L/(1.0*v1+v2);
        double le=t*v2;
        for(i=0;i<n;i++)
        {
            scanf("%lf",&a[i]);
            a[i+n]=a[i]+2.0*L;
        }
        a[2*n]=4.0*L+a[0];
        for(i=0;i<=n;i++)ret[i]=0.0;
        l=0;r=0;
        while(a[r+1]-a[l]<le)r++;
        int flag=0;
       // printf("%.4f\n",le);
        while(1)
        {
            if(l==n&&flag==0)break;
        //    printf("%d %d %d %.0f %.0f %.0f\n",l,r,flag,a[l],a[l+1],a[r+1]);
            if(flag==0)
            {
                if(l==r)
                {
                    ret[0]+=a[l+1]-a[l]-le;
                    l++;r++;
                    flag=1;
                }
                else if(a[l+1]+le<a[r+1])
                {
                    ret[r-l]+=a[l+1]-a[l];
                    l++;
                }
                else
                {
                    ret[r-l]+=a[r+1]-a[l]-le;
                    l++;r++;flag=1;
                }
            }
            else
            {
                if(a[r+1]-le>a[l])
                {
                    ret[r-l+1]+=a[l]-a[r]+le;
                    flag=0;
                }
                else
                {
                    ret[r-l+1]+=a[r+1]-a[r];
                    r++;
                }
            }
        }
        for(i=0;i<=n;i++)printf("%.12f\n",ret[i]/(2.0*L));puts("");
    }
}