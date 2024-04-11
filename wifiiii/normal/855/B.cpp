#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i )
#define sz(x) ((int) x.size())
#define all(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define endl '\n'

ll l[100005],r[100005],a[100005];
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n,p,q,k;
    cin>>n>>p>>q>>k;
    for(int i=1;i<=n;++i) cin>>a[i];
    for(int i=0;i<=n+1;++i) l[i]=r[i]=-3e18;
    ll ans = -3e18;
    for(int i=1;i<=n;++i) l[i]=max(l[i-1],a[i]*p);
    for(int i=n;i>=1;--i) r[i]=max(r[i+1],a[i]*k);
    for(int i=1;i<=n;++i) ans = max(ans, q*a[i] + l[i] + r[i]);
    cout << ans << endl;
    
}