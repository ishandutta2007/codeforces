#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define forii for(int i=1;i<=n;++i)
#define forji for(int j=1;j<=n;++j)
#define forjj for(int j=1;j<=m;++j)
#define forij for(int i=1;i<=m;++i)

ll a[100005];
int main()
{
    ll n,m,k;
    cin>>n>>m>>k;
    forij cin>>a[i];
    ll p=0;
    ll ans=0;
    for(ll i=1;i<=m;)
    {
        ll tmp = (a[i]-p-1)/k, j=i+1;
        while(j<=m && (a[j]-p-1)/k==tmp) ++j;
        p+=j-i;
        ++ans,i=j;
    }
    cout<<ans<<endl;
}