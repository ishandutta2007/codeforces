#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define alll(x) x+1,x+1+n
#define asd cout<<"ok"<<endl;
#define endl '\n'

ll a[100005];
int main()
{
    for(int i=1;i<=100000;++i) a[i]=1ll*i*(i-1)/2;
    int t;
    cin>>t;
    while(t--)
    {
        ll n,k;
        cin>>n>>k;
        ll x=lower_bound(a+1,a+1+100000,k)-a-1;
        ll y=k-a[x]-1;
        string ans(n,'a');
        ans[n-y-1]=ans[n-x-1]='b';
        cout<<ans<<endl;
    }
}