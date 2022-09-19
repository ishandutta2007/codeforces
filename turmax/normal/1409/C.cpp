#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,x,y;
        cin>>n>>y>>x;
        vector <int> v1;
        int ans=1e18;
        for(int i=1;i<=y;++i)
        {
            for(int d=0;d<=50;++d)
            {
                vector <int> v;
                set <int> o;
                for(int j=0;j<n;++j)
                {
                    v.push_back(i+d*j);
                    o.insert(i+d*j);
                }
                if(o.count(x) && o.count(y))
                {
                    int curr=(i+d*(n-1));
                    if(curr<ans)
                    {
                        v1=v;
                        ans=curr;
                    }
                }
            }
        }
        for(auto h:v1) cout<<h<<' ';
        cout<<endl;
    }
    return 0;
}