#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;
typedef pair<int,int> pii;
#define x first
#define y second

const int n=10,k=6;

int h[n+1][n+1];
ld ans[n+1][n+1];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>h[i][j];
    vector<pair<int,int>> path;
    for(int i=1;i<=n;i++)
        if(i%2==1)
            for(int j=1;j<=n;j++)
                path.push_back({i,j});
        else
            for(int j=n;j>=1;j--)
                path.push_back({i,j});
    for(int i=1;i<path.size();i++)
    {
        ld cur=0;
        int no=0;
        for(int j=1;j<=k;j++)
            if(i-j>=0)
                cur+=min(ans[path[i-j].x][path[i-j].y],ans[path[i-j].x-h[path[i-j].x][path[i-j].y]][path[i-j].y]);
            else
                no++;
        ans[path[i].x][path[i].y]=(6+cur)/(6-no);
    }
    cout<<fixed<<setprecision(10)<<ans[n][1];
}