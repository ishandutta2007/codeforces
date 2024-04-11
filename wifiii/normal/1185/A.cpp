#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
#define forii for(int i=1;i<=n;++i)
#define forji for(int j=1;j<=n;++j)
#define forij for(int i=1;i<=m;++i)
#define forjj for(int j=1;j<=m;++j)

vector<ll> v;
int main()
{
    for(int i=1;i<=3;++i)
    {
        ll t;
        cin>>t;
        v.push_back(t);
    }
    sort(v.begin(),v.end());
    ll d;
    cin>>d;
    ll ans = max(d-(v[1]-v[0]), 0ll) + max(d-(v[2]-v[1]), 0ll);
    cout<<ans<<endl;
}