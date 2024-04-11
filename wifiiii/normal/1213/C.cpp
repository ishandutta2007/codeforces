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

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n,m;
        cin>>n>>m;
        if(m*10 >= n)
        {
            ll ans = 0;
            for(ll i=0;i<=n;i+=m) ans+=i%10;
            cout<<ans<<endl;
        }
        else
        {
            ll ans = 0;
            ll tmp = 0;
            for(ll i=1,j=0;i<=31;++i,j+=m) tmp+=j%10;
            ans += n/(30*m)*tmp;
            for(ll i=n/(30*m)*(30*m)+m;i<=n;i+=m) ans+=i%10;
            cout<<ans<<endl;
        }
    }
}