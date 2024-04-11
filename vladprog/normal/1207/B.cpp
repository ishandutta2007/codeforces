#pragma GCC optimize("O3")
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=60;

int a[N][N],b[N][N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>a[i][j];
    vector<pii> ans;
    for(int i=1;i<n;i++)
        for(int j=1;j<m;j++)
            if(a[i][j]&&a[i+1][j]&&a[i][j+1]&&a[i+1][j+1])
                ans.push_back({i,j}),
                b[i][j]=b[i+1][j]=b[i][j+1]=b[i+1][j+1]=1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(a[i][j]!=b[i][j])
                cout<<-1,exit(0);
    cout<<ans.size()<<"\n";
    for(auto p:ans)
        cout<<p.x<<" "<<p.y<<"\n";
}