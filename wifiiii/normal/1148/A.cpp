
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=1;i<=n;++i)

int main()
{
    ll a,b,c;
    cin>>a>>b>>c;
    ll ans = c*2;
    ll tmp = min(a,b);
    a-=tmp,b-=tmp;
    ans+=2*tmp;
    if(a||b) ans++;
    cout<<ans<<endl;
}