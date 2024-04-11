#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define forii for(int i=1;i<=n;++i)
#define forji for(int j=1;j<=n;++j)
#define forjj for(int j=1;j<=m;++j)
#define forij for(int i=1;i<=m;++i)

ll gcd(int a,int b){return b==0?a:gcd(b,a%b);}
int main()
{
    ll n,m,k;
    cin>>n>>m>>k;
    if(k==1) {cout<<"NO"<<endl;return 0;}
    ll n2=n,m2=m;
    ll g=gcd(n,k);
    n/=g,k/=g;
    g=gcd(m,k);
    m/=g,k/=g;
    if(k>2) {cout<<"NO"<<endl;return 0;}
    if(k==1)
    {
        if(n*2<=n2) n*=2;
        else m*=2;
    }
    cout<<"YES"<<endl;
    cout<<0<<" "<<m<<endl;
    cout<<n<<" "<<0<<endl;
    cout<<0<<" "<<0<<endl;
}