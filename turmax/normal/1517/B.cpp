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
        int a[n][m];
        bool used[n][m];
        vector <int> res[n];
        set <pair<int,pair<int,int> > > t;
        for(int i=0;i<n;++i) for(int j=0;j<m;++j) {cin>>a[i][j];used[i][j]=0;t.insert({a[i][j],{i,j}});}
        for(int i=0;i<m;++i)
        {
            pair<int,int> o=(*t.begin()).second;
            used[o.first][o.second]=true;
            res[o.first].push_back(a[o.first][o.second]);
            t.erase(t.begin());
            for(int j=0;j<n;++j)
            {
                if(j==o.first)
                {
                    continue;
                }
                else
                {
                    int l=(-1);
                    int ma=0;
                    for(int k=0;k<m;++k)
                    {
                        if(!used[j][k])
                        {
                            if(a[j][k]>=ma)
                            {
                                ma=a[j][k];
                                l=k;
                            }
                        }
                    }
                    used[j][l]=1;
                    res[j].push_back(ma);
                    t.erase({a[j][l],{j,l}});
                }
            }
        }
        for(int i=0;i<n;++i) {for(auto h:res[i]) cout<<h<<' '; cout<<endl;}
    }
    return 0;
}