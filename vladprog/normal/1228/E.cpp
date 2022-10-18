#include <bits/stdc++.h>

typedef long long ll;
#define int ll

using namespace std;

const int N=260,MOD=1e9+7;

int pwk[N*N],pwk1[N*N],fact[N],rfact[N],c[N];

int ppow(int x,int y)
{
    int res=1;
    while(y)
    {
        if(y&1)
            res=res*x%MOD;
        y>>=1;
        x=x*x%MOD;
    }
    return res;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,k;
    cin>>n>>k;
    pwk[0]=1;
    for(int i=1;i<=n*n;i++)
        pwk[i]=pwk[i-1]*k%MOD;
    pwk1[0]=1;
    for(int i=1;i<=n*n;i++)
        pwk1[i]=pwk1[i-1]*(k-1)%MOD;
    fact[0]=1;
    for(int i=1;i<=n;i++)
        fact[i]=fact[i-1]*i%MOD;
    rfact[n]=ppow(fact[n],MOD-2);
    for(int i=n-1;i>=0;i--)
        rfact[i]=rfact[i+1]*(i+1)%MOD;
    for(int i=0;i<=n;i++)
        c[i]=fact[n]*rfact[i]%MOD*rfact[n-i]%MOD;
    int ans=0;
    for(int x=0;x<=n;x++)
        for(int y=0;y<=n;y++)
        {
            int res=pwk[x*y]*pwk1[n*n-x*y]%MOD*c[x]%MOD*c[y]%MOD;
//            cout<<x<<" "<<y<<" -> "<<res<<"\n";
            if((x+y)%2)
                res=(MOD-res)%MOD;
            ans=(ans+res)%MOD;
        }
    cout<<ans;
}