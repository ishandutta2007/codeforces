#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iostream>
using namespace std;
typedef long long LL;
LL q[1000100],te;
int ct,i,j,l,r,n;
int main()
{
    while(~scanf("%d%d",&l,&r))
    {
        ct=0;q[ct++]=l-1;
        for(n=1;n<=10;n++)
        {
            for(i=0;i<(1<<n);i++)
            {
                LL te=0;
                for(j=0;j<n;j++)
                {
                    te*=10;
                    if(i&(1<<j))te+=4;
                    else te+=7;
                }
                if(te>=l)
                q[ct++]=te;
            }
        }
        sort(q,q+ct);
        LL ans=0;
        for(i=1;;i++)
        {
        //  printf("%d %d\n",i,q[i]);
            if(q[i]<=r)
            ans+=(q[i]-q[i-1])*q[i];
            else
            {
                ans+=q[i]*(r-q[i-1]);
                break;
            }
        }
        cout<<ans<<endl;
    }
}