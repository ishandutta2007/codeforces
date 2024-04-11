#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=200005;
int32_t main()
{
    int next[maxn][20];
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,q;
    cin>>n>>q;
    vector <pair<int,int> > a(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i].first>>a[i].second;
    }
    sort(a.begin(),a.end());
    vector <int> z(n);
    int curr=(-1e18);
    int t;
    int g;
    int h;
    for(int i=0;i<n;++i)
    {
        curr=max(curr,a[i].second);
        z[i]=curr;
        next[i][0]=curr;
        h=curr;
    }
    for(int i=(n-1);i>=0;i--)
    {
        h=z[i];
        for(int j=1;j<20;++j)
        {
            t=lower_bound(a.begin(),a.end(),(pair<int,int>) make_pair(h,1e18))-a.begin();
            t--;
            h=next[t][j-1];
            next[i][j]=h;
        }
    }
    /*for(int i=0;i<n;++i)
    {
        for(int j=0;j<20;++j)
        {
            cout<<next[i][j]<<" ";
        }
        cout<<endl;
    }*/
    for(int i=0;i<q;++i)
    {
    int x,y;
    cin>>x>>y;
    int ans=0;
    t=lower_bound(a.begin(),a.end(),(pair<int,int>) {x,1e18})-a.begin()-1;
    if(t<0)
    {
        cout<<(-1)<<endl;
        continue;
    }
    bool d=true;
    int u;
    bool g;
    while(d)
    {
        d=false;
        g=false;
        for(int j=0;j<20;++j)
        {
            if(next[t][j]>=y)
            {
                if(j!=0)
                {
                ans+=(1<<(j-1));
                t=lower_bound(a.begin(),a.end(),(pair<int,int>) {next[t][j-1],1e18})-a.begin()-1;
                d=true;
                g=true;
                }
                else
                {
                ++ans;
                g=true;
                }
                break;
            }
        }
        if(!g)
        {
            ans=(-1);
            break;
        }
    }
    cout<<ans<<endl;
    }
    return 0;
}