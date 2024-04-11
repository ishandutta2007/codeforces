#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define fe(i,n) for(int i=1;i<=n;++i)
#define ff(i,n) for(int i=0;i<n;++i)
#define fs(i,s) for(int i=0;i<s.size();++i)
#define sz(x) ((int) x.size())
#define all(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define endl '\n'
const int mod = 1e9+7;

ll a[300005];
vector<ll> v;
int main()
{
    int n,k;
    cin>>n>>k;
    ii cin>>a[i];
    for(int i=1;i<n;++i) {v.push_back(a[i]-a[i+1]);}
    sort(all(v));
    ll ans=a[n]-a[1];
    k--;
    for(int i=0;i<k;++i) ans+=v[i];
    cout<<ans<<endl;
}