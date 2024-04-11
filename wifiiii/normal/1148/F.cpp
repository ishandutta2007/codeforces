
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,n) for(int i=1;i<=n;++i)

ll a[300005],b[300005];
int c[300005];
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;ll sum=0;
    cin>>n;
    rep(i,n) cin>>a[i]>>b[i],sum+=a[i];
    rep(i,n) c[i]=__builtin_ctzll(b[i]);
    if(sum<0)
    {
        sum=-sum;
        rep(i,n) a[i]=-a[i];
    }
    ll ans = 0;
    for(int i=62;i>=0;--i)
    {
        ll tmp0 = 0, tmp1 = 0;
        rep(j,n)
        {
            if(i==c[j])
            {
                if(__builtin_popcountll(b[j]&ans) & 1) tmp1 += a[j];
                else tmp0 += a[j];
            }
        }
        if(tmp0 > tmp1) ans |= 1ll<<i;
    }
    cout<<ans<<endl;
}