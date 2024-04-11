#include <bits/stdc++.h>

using namespace std;
char v[100005];
long long fvc[30];
long long dp[30][30];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long n,d,i,j,t,mx=1;
    cin>>(v+1);
    n=strlen(v+1);
    for(i=1;i<=n;++i)
    {
        for(j='a'-'a';j<='z'-'a';++j)
            dp[j][v[i]-'a']+=fvc[j];
        ++fvc[v[i]-'a'];
        mx=max(mx,fvc[v[i]-'a']);
    }
    for(i='a'-'a';i<='z'-'a';++i)
        for(j='a'-'a';j<='z'-'a';++j)
            mx=max(mx,dp[i][j]);
    cout<<mx;
    return 0;
}