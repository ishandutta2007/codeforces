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
    int q;
    cin>>q;
    while(q--)
    {
        ll n;
        cin>>n;
        if(__builtin_popcountll(n+1) == 1)
        {
            ll md=1;
            for(ll i=2;i*i<=n;++i) {
                if(n%i==0) md=max(md,n/i);
            }
            cout<<md<<endl;
        }
        else
        {
            ll ans = 0;
            for(int i=63-__builtin_clzll(n);i>=0;--i)
            {
                if(!((1<<i) & n)) ans |= 1<<i;
            }
            cout<<(ans^n)<<endl;
        }
    }
}