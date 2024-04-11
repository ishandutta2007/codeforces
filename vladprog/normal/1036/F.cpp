#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll ppow(ll x,ll y)
{
    ll res=1;
    while(y)
    {
        if(y&1)
            res=res*x;
        y>>=1;
        x=x*x;
    }
    return res;
}

int mu[]={0, 1, -1, -1, 0, -1, 1, -1, 0, 0, 1, -1, 0, -1, 1, 1, 0, -1, 0, -1, 0, 1, 1, -1, 0, 0, 1, 0, 0, -1, -1, -1, 0, 1, 1, 1, 0, -1, 1, 1, 0, -1, -1, -1, 0, 0, 1, -1, 0, 0, 0, 1, 0, -1, 0, 1, 0, 1, 1, -1};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll ans=n-1;
        for(int i=2;i<=59;i++)
        {
            if(mu[i]==0)
                continue;
            int r=pow(n,1.0/i);
            while(pow(r,i)>2e18||ppow(r,i)>n)
                r--;
            while(pow(r+1,i)<=2e18&&ppow(r+1,i)<=n)
                r++;
            ans+=(r-1)*mu[i];
        }
        cout<<ans<<"\n";
    }
}