#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


const int mod = 998244353;
const int maxn = 300005;
struct node
{
    int x,y;
}a[maxn];
int cmp1(node a,node b)
{
    return a.x<b.x;
}
int cmp2(node a,node b)
{
    return a.y<b.y;
}
int cmp3(node a,node b)
{
    return a.x<b.x || (a.x==b.x && a.y<b.y);
}
ll f[maxn];
int main()
{
    f[0] = 1;
    for(int i=1;i<maxn;++i) f[i]=f[i-1]*i%mod;
    int n;
    cin>>n;
    for(int i=1;i<=n;++i) cin>>a[i].x>>a[i].y;
    
    int lst;
    
    sort(a+1,a+1+n,cmp1);
    lst=1;
    ll tmp1=1;
    for(int i=1;i<=n;++i)
    {
        if(a[i].x != a[i+1].x)
        {
            tmp1 = tmp1 * f[i-lst+1] % mod;
            lst = i+1;
        }
    }
    
    sort(a+1,a+1+n,cmp2);
    lst=1;
    ll tmp2=1;
    for(int i=1;i<=n;++i)
    {
        if(a[i].y != a[i+1].y)
        {
            tmp2 = tmp2 * f[i-lst+1] % mod;
            lst = i+1;
        }
    }
    
    sort(a+1,a+1+n,cmp3);
    int ok = 1;
    for(int i=1;i<n;++i )
    {
        if(a[i].y > a[i+1].y) ok=0;
    }
    ll tmp3 = 0;
    if(ok)
    {
        tmp3 = 1;
        int lst=1;
        for(int i=1;i<=n;++i)
        {
            if(a[i].x==a[i+1].x && a[i].y == a[i+1].y) continue;
            else
            {
                if(i!=lst) tmp3 = tmp3 * f[i-lst+1] % mod;
                lst = i+1;
            }
        }
    }
    
    ll ans = f[n] - (tmp1 + tmp2 - tmp3);
    ans %= mod;
    if(ans<0) ans+=mod;
    cout<<ans<<endl;
}