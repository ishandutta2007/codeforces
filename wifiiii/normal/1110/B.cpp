
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

ll a[100005],b[100005];
int main()
{
    ll n,m,k;
    cin>>n>>m>>k;
    ii cin>>a[i];
    ii b[i]=a[i+1]-a[i];
    vector<ll> v;
    for(int i=1;i<n;++i) v.push_back(-b[i]);
    sort(all(v));
    ll ans=a[n]-a[1]+k;
    for(int i=0;i<k-1;++i) ans+=v[i];
    cout<<ans<<endl;
}