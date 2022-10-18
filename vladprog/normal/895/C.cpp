#pragma optimize("O3")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll S=70,P=19,P2=1ll<<P,M=1e9+7,N=1e5,
prime[P]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67};
ll k[S+1],cnt[2][P2],pow2[N];

int main()
{
    ll n;
    scanf("%I64d",&n);
    pow2[0]=1;
    for(int i=1;i<n;i++)
        pow2[i]=(pow2[i-1]*2)%M;
    for(ll i=0;i<n;i++)
    {
        ll t;
        scanf("%I64d",&t);
        k[t]++;
    }
    cnt[0][0]=1;
    for(ll i=1;i<=S;i++)
    {
        if(!k[i]) continue;
        ll t=i,r=0;
        for(ll j=0,p2=1;j<P;j++,p2<<=1)
            while(t%prime[j]==0)
                r^=p2,t/=prime[j];
        memset(cnt[1],0,sizeof(cnt[1]));
        for(ll j=0;j<P2;j++)
            cnt[1][j]=((cnt[0][j]+cnt[0][j^r])*pow2[k[i]-1])%M;
        memcpy(cnt[0],cnt[1],sizeof(cnt[0]));
    }
    printf("%I64d",(cnt[0][0]+M-1)%M);
}