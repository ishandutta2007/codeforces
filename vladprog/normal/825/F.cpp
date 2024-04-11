#pragma GCC optimize("O3")
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll

const int N=8010,MOD=1e9+7,BASE=29;

int len[N],pw[N],hsh[N],dp[N];

int get(int l,int r)
{
    int ans=(hsh[r]-hsh[l-1]+MOD)*pw[N-l]%MOD;
//    cout<<l<<" "<<r<<" -> "<<ans<<"\n";
    return ans;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    len[0]=0;
    pw[0]=1;
    for(int i=1;i<N;i++)
        len[i]=len[i/10]+1,
        pw[i]=pw[i-1]*BASE%MOD;
    string s;
    cin>>s;
    int n=s.size();
    s='_'+s;
    hsh[0]=0;
    for(int i=1;i<=n;i++)
        hsh[i]=(hsh[i-1]+pw[i]*(s[i]-'a'+1))%MOD;
    dp[0]=0;
    for(int i=1;i<=n;i++)
    {
        dp[i]=i+1;
        for(int j=1;j<=i;j++)
        {
            int l=1,r=i/j;
            while(l<r)
            {
                int m=(l+r+1)/2;
                if(get(i-j*m+1,i-j)==get(i-j*m+1+j,i))
                    l=m;
                else
                    r=m-1;
            }
            int m=r;
            for(int k=1;k<=m;k++)
//                cout<<i<<" "<<j<<" "<<k<<" -> "<<dp[i-j*k]<<" "<<len[k]<<" -> "<<dp[i-j*k]+j+len[k]<<"\n",
                dp[i]=min(dp[i],dp[i-j*k]+j+len[k]);
        }
    }
    cout<<dp[n];
}