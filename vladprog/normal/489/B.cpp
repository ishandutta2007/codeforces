#include <bits/stdc++.h>

using namespace std;

const int N=200;

int a[N],b[N],dp[N][N];

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    int m;
    cin>>m;
    for(int i=0;i<m;i++)
        cin>>b[i];
    sort(a,a+n);
    sort(b,b+m);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            if(i-1>=0&&j-1>=0)
                dp[i][j]=max(dp[i][j],dp[i-1][j-1]);
            if(abs(a[i]-b[j])<=1)
                dp[i][j]++;
            if(i-1>=0)
                dp[i][j]=max(dp[i][j],dp[i-1][j]);
            if(j-1>=0)
                dp[i][j]=max(dp[i][j],dp[i][j-1]);
        }
    cout<<dp[n-1][m-1];
}