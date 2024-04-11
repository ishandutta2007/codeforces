#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
 
int a,b,p,cnt;
LL x,tmp,r,P,ans;
 
inline LL Pow(LL a,int b)
{
    LL ans=1;
    for(;b;b>>=1,a=a*a%p)if(b&1)ans=ans*a%p;
    return ans;
}
 
signed main()
{
    scanf("%d%d%d%lld",&a,&b,&p,&x);
    P=(LL)p*(p-1);
    for(int i=1;i<p;i++)
    {
        tmp=Pow(a,i);
        tmp=b*Pow(tmp,p-2)%p;
        r=((LL)p*i+(LL)(p-1)*(p-1)%P*tmp)%P;
        ans+=x/P+(x%P>=r);
    }
    cout<<ans<<endl;
    return 0;
}