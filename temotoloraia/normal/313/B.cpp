#include <bits/stdc++.h>
using namespace std;
int i,j,n,m,l,r,a[100001],dp[100001],b[100001];
string s;
main()
{
    cin>>s;
    n=s.size();
    for (i=0;i<s.size();i++)
    if (s[i]=='.')
    a[i+1]=1;
    for (i=1;i<n;i++)
    if (a[i]==a[i+1])
    b[i]=1;
    for (i=1;i<=n;i++)
    dp[i]=dp[i-1]+b[i];
    cin>>m;
    while (m--)
    {
        cin>>l>>r;
        cout<<dp[r-1]-dp[l-1]<<endl;
    }
}