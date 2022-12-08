#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[55][55],b[55][55];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            cin>>a[i][j];
    vector<pair<int,int>> ans;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
        {
            if(i<n && j<m && a[i][j]==1 && a[i][j+1] && a[i+1][j] && a[i+1][j+1])
            {
                ans.push_back({i,j});
                b[i][j]=1,b[i][j+1]=1,b[i+1][j]=1,b[i+1][j+1]=1;
            }
        }
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            if(a[i][j]!=b[i][j]) return cout<<-1<<endl,0;
    cout<<ans.size()<<endl;
    for(auto p:ans) cout<<p.first<<" "<<p.second<<endl;
}