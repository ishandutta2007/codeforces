#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    for(int cyc=0;cyc<t;++cyc)
    {
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector <pair<int,int> > a;
    int ans=1e18;
    a.push_back({0,0});
    map <pair<int,int>,int> u;
    u[{0,0}]=0;
    pair <int,int> curr=make_pair(0,0);
    pair <int,int> z;
    for(int i=0;i<n;++i)
    {
        if(s[i]=='L')
        {
            curr.first--;
        }
        else if(s[i]=='R')
        {
            curr.first++;
        }
        else if(s[i]=='D')
        {
            curr.second--;
        }
        else
        {
            curr.second++;
        }
        if(u.count(curr))
        {
            if((i-u[curr]+1)<ans)
            {
                ans=(i-u[curr]+1);
                z={u[curr]+1,i+1};
            }
        }
        u[curr]=(i+1);
    }
    if(ans==1e18)
    {
        cout<<(-1)<<endl;
        continue;
    }
    cout<<z.first<<" "<<z.second<<endl;
    }
    return 0;
}