
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
 
int gcd(int a,int b){return b==0?a:gcd(b,a%b);}
int a[200005];
int main()
{
    int n;
    cin>>n;
    ll sum=0;
    int mx=0;
    ii cin>>a[i],mx=max(mx,a[i]);
    ii sum+=mx-a[i];
    int g=0;
    ii g=gcd(g,mx-a[i]);
    cout<<sum/g<<" "<<g<<endl;
}