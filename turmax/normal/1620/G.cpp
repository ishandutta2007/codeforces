#pragma GCC optimize("O3","unroll-loops")
#include <bits/stdc++.h>

using namespace std;
#define int long long
const int p=998244353;
const int maxn=23;
int cnt[maxn][26];
int cnt1[26];
int val[1<<maxn];
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;++i) {string s;cin>>s;for(auto h:s) cnt[i][h-'a']++;}
    for(int mask=0;mask<(1<<n);++mask)
    {
        for(int j=0;j<26;++j) cnt1[j]=1e9;
        for(int j=0;j<n;++j)
        {
            if(mask & (1<<j))
            {
                for(int k=0;k<26;++k) cnt1[k]=min(cnt1[k],cnt[j][k]);
            }
        }
        int val1=1;
        for(auto h:cnt1) {val1*=(h+1);val1%=p;}
        val[mask]=val1;
        if(mask==0) val[mask]=0;
        if((__builtin_popcount(mask))%2==0) {val[mask]=(p-val[mask])%p;}
        //cout<<mask<<" mask "<<val[mask]<<" val[mask] "<<endl;
    }
    val[0]=0;
    int res=0;
    for(int i=0;i<n;++i)
    {
        for(int mask=0;mask<(1<<n);++mask)
        {
            if(!(mask & (1<<i)))
            {
                val[mask+(1<<i)]+=(val[mask]);
                val[mask+(1<<i)]%=p;
            }
        }
    }
    for(int mask=1;mask<(1<<n);++mask)
    {
        int ans=val[mask];
        ans%=p;ans+=p;ans%=p;
        int z=0;
        for(int j=0;j<n;++j)
        {
            if(mask & (1<<j))
            {
                z+=(j+1);
            }
        }
        res^=((ans*z*__builtin_popcount(mask)));
    }
    cout<<res;
    /*int res=0;
    for(int mask=0;mask<(1<<n);++mask)
    {
        cout<<mask<<" mask "<<val[mask]<<" val[mask] "<<endl;
        int ans=0;
        for(int mask1=mask;;mask1=(mask1-1) & mask)
        {
            if((__builtin_popcount(mask1)%2)==1)
            {
                ans+=val[mask1];ans%=p;
            }
            else
            {
                ans-=val[mask1];ans%=p;
            }
            if(mask1==0) break;
        }
        ans%=p;ans+=p;ans%=p;
        cout<<mask<<" mask "<<ans<<" ans "<<endl;
        int z=0;
        for(int j=0;j<n;++j)
        {
            if(mask & (1<<j))
            {
                z+=(j+1);
            }
        }
        res^=((ans*z*__builtin_popcount(mask)));
    }
    cout<<res;*/
    return 0;
}