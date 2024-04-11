#include <bits/stdc++.h>
using namespace std;
unsigned long long x[100],y[100];
unsigned long long dst(unsigned long long x,unsigned long long y,unsigned long long x1,unsigned long long y1)
{
    if(x1<x)
        swap(x1,x);
    if(y1<y)
        swap(y1,y);
    return x1-x+y1-y;
}
int main()
{
    ios_base::sync_with_stdio(false);
    unsigned long long i,j=0,t,x0,y0,ax,ay,bx,by,xs,ys,n;
    int mx=0;
    cin>>x0>>y0>>ax>>ay>>bx>>by>>xs>>ys>>t;
    x[++j]=x0;
    y[j]=y0;
    while(x[j]*ax+bx<=20000000000000000ULL && y[j]*ay+by<=20000000000000000ULL)
    {
        x[j+1]=x[j]*ax+bx;
        y[j+1]=y[j++]*ay+by;
    }
    n=j;
    for(i=1;i<=n;++i)
    {
        long long tc=t-dst(xs,ys,x[i],y[i]);
        if(tc>=0)
        {
            int cnt=1;
            for(j=i-1;j>=1;--j)
            {
                tc-=dst(x[j],y[j],x[j+1],y[j+1]);
                if(tc>=0)
                    ++cnt;
                else
                    break;
            }
            mx=max(mx,cnt);
            cnt=1;
            tc=t-dst(xs,ys,x[i],y[i]);
            for(j=i;j<n;++j)
            {
                tc-=dst(x[j],y[j],x[j+1],y[j+1]);
                if(tc>=0)
                    ++cnt;
                else
                    break;
            }
            mx=max(mx,cnt);
        }
    }
    cout<<mx;
    return 0;
}