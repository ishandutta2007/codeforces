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

ll aa[200005],bb[200005];
ll gcd(ll a,ll b){return b==0?a:gcd(b,a%b);}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int q;
    cin>>q;
    while(q--)
    {
        int n;
        cin>>n;
        ii cin>>aa[i],aa[i]/=100;
        sort(aa+1,aa+1+n);
        reverse(aa+1,aa+1+n);
        ii bb[i]=bb[i-1]+aa[i];
        ll x,a,y,b;
        cin>>x>>a>>y>>b;
        if(x<y) swap(x,y),swap(a,b);
        ll k;
        cin>>k;
        ll lo=1,hi=n+1;
        while(lo<hi)
        {
            ll mid=(lo+hi)>>1;
            ll a1 = mid/a, a2 = mid/b, a3 = mid/(a*b/gcd(a,b));
            a1 -= a3, a2 -= a3;
            if(1ll*bb[a3]*(x+y) + 1ll*(bb[a1+a3]-bb[a3])*x + 1ll*(bb[a1+a2+a3]-bb[a1+a3])*y < k) lo = mid+1;
            else hi = mid;
        }
        if(lo==n+1) cout<<-1<<endl;
        else cout<<lo<<endl;
    }
}