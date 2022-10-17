#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
random_device rng;
mt19937 urng(rng());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i )
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define endl '\n'

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int cnt1[2] = {0};
        int cnt2[2] = {0};
        int n,m;
        cin>>n;
        for(int i=1;i<=n;++i)
        {
            int tmp;
            cin>>tmp;
            cnt1[tmp%2]++;
        }
        cin>>m;
        for(int i=1;i<=m;++i)
        {
            int tmp;
            cin>>tmp;
            cnt2[tmp%2]++;
        }
        ll ans = 0;
        ans += 1ll * cnt1[0] * cnt2[0];
        ans += 1ll * cnt2[1] * cnt1[1];
        cout<<ans<<endl;
    }
}