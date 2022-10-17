#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
#define forii for(int i=1;i<=n;++i)
#define forji for(int j=1;j<=n;++j)
#define forij for(int i=1;i<=m;++i)
#define forjj for(int j=1;j<=m;++j)

int main()
{
    ll x,y,z;
    cin>>x>>y>>z;
    ll ans = (x+y)/z;
    if(x/z + y/z == ans)
    {
        cout<<ans<<" "<<0<<endl;
        return 0;
    }
    cout<<ans<<" "<<min(min(x%z,z-x%z),min(y%z,z-y%z))<<endl;
}