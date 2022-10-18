#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll

const int N=110,A=30;

int dp[N][A];

const int INF=1e15;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    string s;
    cin>>n>>k>>s;
    dp[0][0]=1;
    dp[0][1]=1;
    for(char c:s)
    {
        for(int len=N-1;len>=1;len--)
        {
            int prv=dp[len][c-'a'+2];
            int sum=dp[len-1][1];
            dp[len][c-'a'+2]=sum;
            dp[len][1]+=sum-prv;
            dp[len][c-'a'+2]=min(dp[len][c-'a'+2],INF);
            dp[len][1]=min(dp[len][1],INF);
        }
    }
    int ans=0;
    for(int len=n;len>=0;len--)
    {
        int cur=min(dp[len][1],k);
        ans+=cur*(n-len);
        k-=cur;
    }
    cout<<(k?-1:ans);
}