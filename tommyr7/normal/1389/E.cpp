#include <bits/stdc++.h>
using namespace std;
int T,m,d,w;
int gcd(int x,int y)
{
    if (x==0) return y;
    if (y==0) return x;
    return gcd(y,x%y);
}
void solve()
{
    scanf("%d%d%d",&m,&d,&w);
    int tmp=gcd(d-1,w);
    w/=tmp;
    tmp=min(m,d);
    long long ans;
    if (tmp%w==0) ans=1LL*w*((1LL*(tmp/w)*(tmp/w-1))/2);
    else
    {
        ans=1LL*(tmp%w)*((1LL*(tmp/w)*(tmp/w+1))/2);
        ans+=1LL*(w-tmp%w)*((1LL*(tmp/w)*(tmp/w-1))/2);
    }
    printf("%lld\n",ans);
}
int main()
{
    scanf("%d",&T);
    while (T--) solve();
    return 0;
}