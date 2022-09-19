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
        int n;
        cin>>n;
        set <int> v[n];
        vector <int> g[n];
        bool ok[n];
        for(int i=0;i<n;++i)
        {
            ok[i]=false;
            int c;
            cin>>c;
            set <int> z;
            for(int j=0;j<c;++j)
            {
                int x;
                cin>>x;
                x--;
                z.insert(x);
                g[x].push_back(i);
            }
            v[i]=z;
        }
        set <int> l;
        set <int> ok1;
        for(int i=0;i<n;++i)
        {
            if(!v[i].size()) ok1.insert(i);
        }
        int curr=0;
        int sum=0;
        int ans=1;
        while(true)
        {
            if(sum==n)
            {
                cout<<ans<<'\n';
                break;
            }
            if(ok1.empty())
            {
                cout<<(-1)<<'\n';
                break;
            }
            set <int>::iterator it=(ok1.end());it--;
            if((*it)<curr)
            {
                curr=0;
                ++ans;
                continue;
            }
            else
            {
                int pos=*ok1.lower_bound(curr);
                ++sum;
                curr=pos;
                ok1.erase(pos);
                ok[pos]=true;
                for(auto h:g[pos]) {v[h].erase(pos);if(!v[h].size()) ok1.insert(h);}
            }
        }
    }
    return 0;
}