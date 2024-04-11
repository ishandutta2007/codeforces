#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int gcd(int a, int b) {return b == 0 ? a : gcd(b, a % b);}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        ll ans = 0;
        map<pair<int,int>,int> mp;
        for(int i=1;i<=n;++i)
        {
            int x,y,u,v;
            cin>>x>>y>>u>>v;
            int dx=u-x,dy=v-y;
            int g=abs(gcd(dx,dy));
            dx/=g,dy/=g;
            mp[{dx,dy}]++;
            ans+=mp[{-dx,-dy}];
        }
        cout<<ans<<endl;
    }
}