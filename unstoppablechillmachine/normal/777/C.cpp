#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;


#define itn int
#define fro for
#define f first
#define sec second

int n,m,i1,i2,dp1[1000001],max1,k,a1,a2;
vector <vector<itn> > a,dp;

int main()
{
    ios::sync_with_stdio(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin>>n>>m;
    a.resize(n+1);
    dp.resize(m+1);

    for (itn i=1;i<=n;i++)
    {
        a[i].resize(m+1);
        for (int j=1;j<=m;j++)
        {
            cin>>a[i][j];
        }
    }

    for (int j=1;j<=m;j++)
    {
        dp[j].resize(n+1);
        i2=1;
        while (i2<=n)
        {
            i1=i2;
            i2++;
            while (i2<=n && a[i2][j]>=a[i2-1][j]) i2++;
            for (int i=i1;i<i2;i++) dp[j][i]=i2-1;
        }
    }

    for (int i=1;i<=n;i++)
    {
        max1=0;
        for (int j=1;j<=m;j++) max1=max(max1,dp[j][i]);
        dp1[i]=max1;
    }

    cin>>k;
    for (int i=0;i<k;i++)
    {
        cin>>a1>>a2;
        if (dp1[a1]>=a2) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }


    return 0;
}