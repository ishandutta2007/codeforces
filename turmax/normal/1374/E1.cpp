#include <bits/stdc++.h>

using namespace std;
#define int long long
vector <int> a[2][2];
int l[2][2];
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;++i)
    {
        int t,x,y;
        cin>>t>>x>>y;
        a[x][y].push_back(t);
    }
    for(int i=0;i<2;++i)
    {
        for(int j=0;j<2;++j)
        {
            sort(a[i][j].begin(),a[i][j].end());
        }
    }
    int ans=0;
    for(int i=0;i<k;++i)
    {
        int u1=1e18,u2=1e18;
        if(l[0][1]>=a[0][1].size() || l[1][0]>=a[1][0].size())
        {
            u1=1e18;
        }
        else
        {
            u1=a[0][1][l[0][1]]+a[1][0][l[1][0]];
        }
        if(l[1][1]>=a[1][1].size())
        {
            u2=1e18;
        }
        else
        {
            u2=a[1][1][l[1][1]];
        }
        //cout<<u1<<" "<<u2<<endl;
        if(u1==1e18 && u2==1e18)
        {
            cout<<(-1);
            return 0;
        }
        if(u1<=u2)
        {
            l[0][1]++;l[1][0]++;
            ans+=u1;
        }
        else
        {
            l[1][1]++;
            ans+=u2;
        }
    }
    cout<<ans;
    return 0;
}