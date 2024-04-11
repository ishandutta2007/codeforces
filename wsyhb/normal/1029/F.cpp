#include<bits/stdc++.h>
using namespace std;
vector<long long> div_a,div_b,div_c;
inline void init(long long n,vector<long long> &div)
{
    for(int i=1;1ll*i*i<=n;++i)
    {
        if(n%i==0)
            div.push_back(i);
    }
    for(int i=int(div.size())-1;i>=0;--i)
    {
        int x=div[i];
        if(1ll*x*x!=n)
            div.push_back(n/x);
    }
}
int main()
{
    long long a,b;
    scanf("%lld%lld",&a,&b);
    long long c=a+b;
    init(a,div_a);
    init(b,div_b);
    init(c,div_c);
    int pa=0,pb=0;
    long long ans=1e18;
    for(int i=0;i<int(div_c.size());++i)
    {
        long long x=div_c[i],y=c/x;
        if(x>y)
            break;
        while(pa<int(div_a.size())&&div_a[pa]<=x)
            ++pa;
        if(pa&&a/div_a[pa-1]<=y)
        {
            ans=min(ans,(x+y)<<1);
            continue;
        }
        while(pb<int(div_b.size())&&div_b[pb]<=x)
            ++pb;
        if(pb&&b/div_b[pb-1]<=y)
            ans=min(ans,(x+y)<<1);
    }
    printf("%lld\n",ans);
    return 0;
}