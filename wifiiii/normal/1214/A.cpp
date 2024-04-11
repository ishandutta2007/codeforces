#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 2e5+5;

int main()
{
    ll n,d,e;
    vector<ll> v;
    cin>>n>>d>>e;
    e*=5;
    ll ans = 1e18;
    for(int i=0;i<=n;++i)
        if(n>=i*d) ans=min(ans,(n-i*d)-(n-i*d)/e*e);
        else break;
    cout << ans << endl;
}