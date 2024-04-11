#include <bits/stdc++.h>

typedef long long ll;
#define int ll

using namespace std;

const int N=1010,MOD=1e9+7;

int a[N][N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int h,w;
    cin>>h>>w;
    #define make(i,j,x) if(a[i][j]==-x) cout<<0,exit(0); else a[i][j]=x
    for(int i=1;i<=h;i++)
    {
        int r;
        cin>>r;
        for(int j=1;j<=r;j++)
            make(i,j,1);
        make(i,r+1,-1);
    }
    for(int j=1;j<=w;j++)
    {
        int c;
        cin>>c;
        for(int i=1;i<=c;i++)
            make(i,j,1);
        make(c+1,j,-1);
    }
    int ans=1;
    for(int i=1;i<=h;i++)
        for(int j=1;j<=w;j++)
            if(!a[i][j])
                ans=ans*2%MOD;
    cout<<ans;
}