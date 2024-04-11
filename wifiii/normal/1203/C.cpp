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

ll a[400005];
ll gcd(ll a,ll b){return b==0?a:gcd(b,a%b);}
int main()
{
    int n;
    cin>>n;
    ii cin>>a[i];
    ll g=a[1];
    ii g=gcd(g,a[i]);
    int cnt=0;
    ll i=1;
    for(;i*i<g;++i) if(g%i==0) cnt+=2;
    if(i*i==g) cnt++;
    cout<<cnt<<endl;
}