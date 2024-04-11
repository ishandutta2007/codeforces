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

int main()
{
    ll n,p;
    cin>>n>>p;
    for(int i=1;i<=60;++i)
    {
        ll x = n-i*p;
        if(x<=0) continue;
        if(x>=i && __builtin_popcountll(x) <= i) return cout<<i<<endl,0;
    }
    cout<<-1<<endl;
}