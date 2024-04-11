#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define fe(i,n) for(int i=1;i<=n;++i)
#define ff(i,n) for(int i=0;i<n;++i)
#define fs(i,s) for(int i=0;i<s.size();++i)
#define sz(x) ((int) x.size())
#define all(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define endl '\n'

map<ll,int> mp;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n,p,k;
    cin>>n>>p>>k;
    ll ans = 0;
    ii
    {
        ll tmp;
        cin>>tmp;
        ll tmp2 = tmp*tmp%p*tmp%p*tmp%p-k*tmp%p;
        tmp2 %= p;
        if(tmp2 < 0) tmp2 += p;
        ans += mp[tmp2];
        mp[tmp2]++;
    }
    cout << ans << endl;
}