
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

const int maxn = 10005;
ll a[maxn],b[maxn];
ll ans=0;
map<ll,ll> mp;
int main()
{
    int n;
    cin>>n;
    ii cin>>a[i],mp[a[i]]++;
    ii cin>>b[i];
    vector<ll> v;
    for(auto p:mp) if(p.second >= 2) v.push_back(p.first);
    for(int i=1;i<=n;++i)
    {
        int ok = 0;
        for(ll p:v)
            if((a[i] | p) == p)
            {
                ok = 1;
                break;
            }
        if(ok) ans += b[i];
    }
    cout << ans << endl;
}