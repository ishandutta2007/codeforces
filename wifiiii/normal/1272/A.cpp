
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
random_device rng;
mt19937 mrand(rng());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define endl '\n'

int main()
{
    int q;
    cin>>q;
    while(q--)
    {
        ll ans=1e18;
        ll a,b,c;
        cin>>a>>b>>c;
        for(ll aa=a-1;aa<=a+1;++aa)
            for(ll bb=b-1;bb<=b+1;++bb)
                for(ll cc=c-1;cc<=c+1;++cc)
                    ans=min(ans,abs(aa-bb)+abs(aa-cc)+abs(bb-cc));
        cout<<ans<<endl;
    }
}