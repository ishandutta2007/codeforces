#include <bits/stdc++.h>

using namespace std;
#define int long long
vector <int> rasl(int x)
{
    vector <int> v;
    if(x==1) return v;
    for(int i=2;i*i<=x;++i)
    {
        if(x%i==0)
        {
            v=rasl(x/i);
            v.push_back(i);
            return v;
        }
    }
    v.push_back(x);
    return v;
}
int f(int x,int y)
{
    while(x%y==0)
    {
        x/=y;
    }
    return x;
}
int mul(int x,int y)
{
    if(x>=(2e18/y)) return 2e18;
    else return x*y;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    while(n--)
    {
        int x,y;
        cin>>x>>y;
        vector <int> v=rasl(y);
        map <int,int> m;
        vector <int> keys;
        for(auto h:v)
        {
            if(m.count(h)) m[h]*=h;
            else
            {
                m[h]=h;
                keys.push_back(h);
            }
        }
        int ans=0;
        for(auto h:keys)
        {
            int o=m[h];
            ans=max(ans,mul(f(x,h),(o/h)));
        }
        ans=min(ans,x);
        cout<<ans<<endl;
    }
    return 0;
}