
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define forii for(int i=1;i<=n;++i)
#define forji for(int j=1;j<=n;++j)
#define forjj for(int j=1;j<=m;++j)
#define forij for(int i=1;i<=m;++i)

int main()
{
    ll r;
    cin>>r;
    if(r==1) {cout<<"NO"<<endl;return 0;}
    for(ll x=1;r-x-x*x-1>0;++x)
    {
        if((r-x*x-x-1)%(2*x)==0) {cout<<x<<" "<<(r-x*x-x-1)/(2*x)<<endl;return 0;}
    }
    cout<<"NO"<<endl;
}