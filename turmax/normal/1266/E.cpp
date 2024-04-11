#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    vector <int> a(n);
    vector <int> to(n);
    int ans=0;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        ans+=a[i];
        to[i]=0;
    }
    map <pair<int,int>,int> b;
    int m;
    cin>>m;
    int x,y,z;
    int o;
    for(int i=0;i<m;++i)
    {
        cin>>x>>y>>z;
        x--;z--;
        if(b.count({x,y})==0 || b[{x,y}]==(-1))
        {
            if(z!=(-1))
            {
            to[z]++;
            if(to[z]<=a[z])
            {
                ans--;
            }
            b[{x,y}]=z;
            }
        }
        else
        {
            o=b[{x,y}];
            if(o!=(-1))
            {
            to[o]--;
            if(to[o]<a[o])
            {
                ans++;
            }
            }
            b[{x,y}]=(-1);
            if(z!=(-1))
            {
                to[z]++;
                if(to[z]<=a[z])
                {
                    ans--;
                }
                b[{x,y}]=z;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}