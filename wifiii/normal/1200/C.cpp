#include<bits/stdc++.h>

typedef long long ll;
using namespace std;
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define fs(i,s) for(int i=0;i<s.size();++i)
#define sz(x) ((int) x.size())
#define all(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define endl '\n'


ll gcd(ll a,ll b){return b==0?a:gcd(b,a%b);}
int main()
{
    ll n,m,q;
    cin>>n>>m>>q;
    ll g=gcd(n,m);
    ll n2=n/g,m2=m/g;
    while(q--)
    {
        ll sx,sy,ex,ey;
        cin>>sx>>sy>>ex>>ey;
        ll bx,by;
        if(sx==1) bx=(sy-1)/n2;
        else bx=(sy-1)/m2;
        if(ex==1) by=(ey-1)/n2;
        else by=(ey-1)/m2;
        if(bx==by) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}