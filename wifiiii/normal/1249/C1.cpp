#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
random_device rng;
mt19937 urng(rng());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i )
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define endl '\n'

ll a[205],ans;
void solve(ll n, ll p, int last)
{
    if(n==1) {if(last) ans=min(ans,p+1);return;}
    int pos = lower_bound(a,a+39,n)-a;
    if(pos > last) return;
    if(pos < last) ans = min(ans, a[pos]+p);
    if(a[pos] == n) return;
    --pos;
    solve(n-a[pos], p+a[pos], pos);
}
int main()
{
    a[0] = 1;
    for(int i=1;i<=39;++i) a[i]=a[i-1]*3;
    int q;
    cin>>q;
    while(q--) {
        ans=2e18;
        ll n;
        cin>>n;
        solve(n,0,40);
        cout<<ans<<endl;
    }
}