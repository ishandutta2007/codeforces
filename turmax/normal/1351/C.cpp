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
        string s;
        cin>>s;
        set <pair<pair<int,int>,pair<int,int> > > u;
        int ans=0;
        pair <int,int> curr=make_pair(0,0);
        int n=s.size();
        for(int i=0;i<n;++i)
        {
            pair <int,int> nex=curr;
            if(s[i]=='S')
            {
                nex.first--;
            }
            if(s[i]=='N')
            {
                nex.first++;
            }
            if(s[i]=='W')
            {
                nex.second--;
            }
            if(s[i]=='E')
            {
                nex.second++;
            }
            if(u.count({curr,nex}) || u.count({nex,curr}))
            {
                ++ans;
            }
            else
            {
                ans+=5;
            }
            u.insert({curr,nex});
            curr=nex;
        }
        cout<<ans<<endl;
    }
    return 0;
}