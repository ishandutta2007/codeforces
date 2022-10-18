#pragma GCC optimize("O3")
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=1e6+100,MOD=1234567891;

string s[N];
vector<int> dp1[N],dp2[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>s[i],
        s[i]="_"+s[i]+"_";
    for(int i=0;i<=n+1;i++)
        dp1[i].resize(m+2),
        dp2[i].resize(m+2);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(i==1&&j==1)
                dp1[i][j]=1;
            else if(s[i][j]=='.')
                dp1[i][j]=(dp1[i-1][j]+dp1[i][j-1])%MOD;
    for(int i=n;i>=1;i--)
        for(int j=m;j>=1;j--)
            if(i==n&&j==m)
                dp2[i][j]=1;
            else if(s[i][j]=='.')
                dp2[i][j]=(dp2[i+1][j]+dp2[i][j+1])%MOD;
    int cnt=dp1[n][m];
    if(!cnt)
        cout<<0,exit(0);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(!(i==1&&j==1)&&!(i==n&&j==m)&&dp1[i][j]*dp2[i][j]%MOD==cnt)
                cout<<1,exit(0);
    cout<<2;
}