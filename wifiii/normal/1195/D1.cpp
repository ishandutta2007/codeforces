#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define fe(i,n) for(int i=1;i<=n;++i)
#define ff(i,n) for(int i=0;i<n;++i)
#define sz(x) ((int) x.size())
#define all(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define endl '\n'

string a[100005];
const int mod = 998244353;
int main()
{
    int n;
    cin>>n;
    ii cin>>a[i];
    ll ans=0;
    ii
    {
        ll tmp=0;
        for(int j=0;j<a[i].size();++j)
        {
            tmp=tmp*10+a[i][j]-'0';
            tmp=tmp*10+a[i][j]-'0';
            tmp%=mod;
        }
        ans=(ans+tmp)%mod;
    }
    cout<<ans*n%mod<<endl;
}