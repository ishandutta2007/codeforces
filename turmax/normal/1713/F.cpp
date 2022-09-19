#pragma GCC optimize("O3","unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>

using namespace std;
int res[1<<19];
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;cin>>n;int a[n];for(int i=0;i<n;++i) cin>>a[i];
    int ma[n+1];for(int i=0;i<=n;++i) ma[i]=(-1); int h=0;int o=1;while(o<n) {o*=2;++h;}
    for(int mask=0;mask<n;++mask) {res[o-1-mask]=a[mask];}
    for(int mask=o-n-1;mask>=0;--mask)
    {
        int mask2=o-1-mask;
        for(int mask1=mask2;;mask1=(mask1-1) & mask2)
        {
            if(mask1==0) break;
            res[mask]^=res[mask+mask1];
        }
    }
    for(int i=0;i<h;++i)
    {
        for(int j=0;j<o;++j)
        {
            if(j & (1<<i))
            {
                res[j]^=res[j-(1<<i)];
            }
        }
    }
    for(int i=0;i<n;++i) cout<<res[n-i-1]<<' ';
    return 0;
}
/*
10
346484077 532933626 858787727 369947090 299437981 416813461 865836801 141384800 157794568 691345607
*/