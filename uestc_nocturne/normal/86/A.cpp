#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef __int64 LL;
const LL P=1000000007;
LL rev(LL x)
{
    int t=0;
    LL tt=x;
    LL te=1;
    while(tt>0)
    {
        te*=10;
        t++;
        tt/=10;
    }
    return te-1-x;
}
LL l,r;
int main()
{
    while(~scanf("%I64d%I64d",&l,&r))
    {
        LL ans;
        LL tt=r;
        int t=0;
        LL te=1;
        while(tt>0)
        {
            t++;
            tt/=10;
            te*=10;
        }
        te/=10;
        LL id;
        if(l>=5*te)id=l;
        else if(r<5*te)id=r;
        else id=5*te;
        ans=rev(id)*id;
        cout<<ans<<endl;
    }
}