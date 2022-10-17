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

const int mod = 1e9+7;
ll fpow(ll a,ll b)
{
    ll ret = 1;
    while(b)
    {
        if(b&1) ret=ret*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return ret;
}
int a[1005][1005];
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    memset(a,-1,sizeof(a));
    for(int i=1;i<=n;++i)
    {
        int tmp;
        cin>>tmp;
        for(int j=1;j<=tmp;++j)
        {
            if(a[i][j] == 0) return cout<<0<<endl,0;
            a[i][j]=1;
        }
        if(a[i][tmp+1] == 0) return cout<<0<<endl,0;
        a[i][tmp+1] = 0;
    }
    for(int i=1;i<=m;++i)
    {
        int tmp;
        cin>>tmp;
        for(int j=1;j<=tmp;++j)
        {
            if(a[j][i] == 0) return cout<<0<<endl,0;
            a[j][i]=1;
        }
        if(a[tmp+1][i] == 1) return cout<<0<<endl,0;
        a[tmp+1][i] = 0;
    }
    int cnt=0;
    ii jj if(a[i][j]==-1) cnt++;
    ll ans=fpow(2,cnt);
    cout<<ans<<endl;
}