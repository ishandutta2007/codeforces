#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;

int main()
{
    //freopen("in.txt","r",stdin);
    ll n,a=0;
    cin>>n;
    ll t=n;
    for(ll i=2;i*i<=n;i++)
    {
        if(t%i==0)
        {
            while(t%i==0)
            {
                t/=i;
            }
            if(t==1)
            {
                cout<<i;
                return 0;
            }
            else
            {
                cout<<1;
                return 0;
            }
        }
    }
    cout<<n;
    return 0;
}