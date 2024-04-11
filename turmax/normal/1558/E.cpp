#pragma GCC optimize("O3","Ofast","unroll-loops")
#pragma GCC target("avx2")
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
        int n,m;
        cin>>n>>m;
        int a[n]={0};int b[n]={0};
        vector <int> g[n];
        for(int i=1;i<n;++i) {cin>>a[i];a[i]++;}
        for(int i=1;i<n;++i) cin>>b[i];
        for(int i=0;i<m;++i)
        {
            int x,y;
            cin>>x>>y;
            x--;y--;
            g[x].push_back(y);g[y].push_back(x);
        }
        bool ok[n]={0};
        ok[0]=true;
        int currsk=0;
        int ans[n][n];
        int ans1[n][n];
        for(int i=0;i<n;++i) for(int j=0;j<n;++j) ans[i][j]=1e18;
        int res=0;
        int val1[n]={0};int val2[n]={0};
        //for(int l=0;l<(n-1);++l)
        {
        for(int i=0;i<n;++i) for(auto j:g[i]) {ans[i][j]=a[i];ans1[i][j]=ans[i][j];}
        for(int cyc=0;cyc<max(2*n+5,2*m+5);++cyc)
        {
            for(int i=0;i<n;++i) {val1[i]=1e18;val2[i]=1e18;}
            for(int i=0;i<n;++i)
            {
                for(auto j:g[i])
                {
                    int val=max(a[i],ans[j][i]-b[i]);
                    if(val<val1[i])
                    {
                        val2[i]=val1[i];
                        val1[i]=val;
                    }
                    else if(val<val2[i])
                    {
                        val2[i]=val;
                    }
                }
            }
            for(int i=0;i<n;++i)
            {
                for(auto j:g[i])
                {
                     int val=max(a[i],ans[j][i]-b[i]);
                     if(val1[i]==val) ans1[i][j]=val2[i];
                     else ans1[i][j]=val1[i];
                }
            }
            for(int i=0;i<n;++i) for(auto j:g[i]) {assert(ans[i][j]>=a[i]);ans[i][j]=ans1[i][j];}
        }
        for(int l=0;l<(n-1);++l)
        {
        int mi=1e18;
        int f=(-1);
        for(int i=0;i<n;++i)
        {
            if(ok[i])
            {
            for(auto h:g[i])
            {
                 if(!ok[h])
                 {
                     if(ans[h][i]<mi)
                     {
                         mi=ans[h][i];
                         f=h;
                     }
                 }
            }
            }
        }
        res=max(res,mi-currsk);
        currsk+=b[f];
        ok[f]=true;
        b[f]=0;
        }
        }
        cout<<res<<'\n';
    }
    return 0;
}