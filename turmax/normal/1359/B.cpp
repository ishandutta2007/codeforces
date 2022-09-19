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
    int n,m,u,v;
    cin>>n>>m>>u>>v;
    int ans=0;
    for(int i=0;i<n;++i)
    {
        string s;
        cin>>s;
        s+='*';
        vector <pair<int,int> > z;
        bool h=false;
        int l=(-1);
        for(int j=0;j<=m;++j)
        {
            if(s[j]=='.')
            {
                if(!h)
                {
                    l=j;
                    h=true;
                }
            }
            else
            {
                if(h)
                {
                    z.push_back({l,j});
                    h=false;
                }
            }
        }
        //cout<<z.size()<<" sz "<<endl;
        int ans1=0;
        for(int j=0;j<z.size();++j)
        {
            int x=z[j].second-z[j].first;
            if(x%2==0)
            {
                ans1+=min(u*x,v*(x/2));
            }
            else
            {
                ans1+=min(u*x,v*(x/2)+u);
            }
        }
        ans+=ans1;
    }
    cout<<ans<<endl;
    }
    return 0;
}