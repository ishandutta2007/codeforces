#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;++i)
typedef long long ll;

int main()
{
    ll n;
    cin>>n;
    if(n&1) cout<<0<<endl;
    else
    {
        ll ans = 1<<(n/2);
        cout<<ans<<endl;
    }
}