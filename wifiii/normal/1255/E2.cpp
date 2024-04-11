#include<bits/stdc++.h>
 
typedef long long ll;
using namespace std;
random_device rng;
mt19937 rd(rng());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define endl '\n'

int a[1000005];
ll s[1000005];
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    ii cin>>a[i];
    ii s[i]=a[i]+s[i-1];
    ll tot=s[n];
    if(tot == 1) return cout << -1 << endl,0;
    ll ans=1e18;
    for(ll i=2;i*i<=tot;++i)
    {
        if(tot%i==0)
        {
            ll tmp=0;
            for(int j=1;j<=n;++j)
                tmp += min(i-s[j]%i,s[j]%i);
            ans=min(ans,tmp);
            while(tot%i==0) tot/=i;
        }
    }
    if(tot>1)
    {
        ll tmp=0;
        for(int j=1;j<=n;++j)
            tmp += min(tot-s[j]%tot,s[j]%tot);
        ans=min(ans,tmp);
    }
    cout<<ans<<endl;
}