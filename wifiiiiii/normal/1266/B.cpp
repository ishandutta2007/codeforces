
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
    int t;
    cin>>t;
    while(t--)
    {
        ll x;
        cin>>x;
        int ok=0;
        for(int i=1;i<=6;++i) {
            ll lo=1,hi=x;
            while(lo<hi)
            {
                ll mid=(lo+hi)>>1;
                if((mid-1)*14+21-i < x) lo=mid+1;
                else hi=mid;
            }
            if((lo-1)*14+21-i == x) ok=1;
        }
        if(ok) cout<<"YES\n";
        else cout<<"NO\n";
    }
}