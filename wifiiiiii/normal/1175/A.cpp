
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=1;i<=n;++i)

int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,k;
        cin>>n>>k;
        ll ans = 0;
        while(n)
        {
            if(n%k==0) ++ans,n/=k;
            else
            {
                ans += n - n / k * k;
                n = n/k*k;
            }
        }
        cout<<ans<<endl;
    }
}