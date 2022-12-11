#include<bits/stdc++.h>
using namespace std;
const int P=1e9+7;
inline void add(int &a,int b)
{
    a=a+b-(a+b>=P?P:0);
}
const int max_n=1e5+5;
int a[max_n];
const int max_a=1e6+5;
int dp[max_a];
vector<int> d[max_a];
int main()
{
    int n;
    scanf("%d",&n);
    int range=0;
    for(int i=1;i<=n;++i)
    {
        scanf("%d",a+i);
        range=max(range,a[i]);
    }
    for(int i=1;i<=range;++i)
        for(int j=i;j<=range;j+=i)
            d[j].push_back(i);
    dp[0]=1;
    for(int i=1;i<=n;++i)
    {
        for(int k=int(d[a[i]].size())-1;k>=0;--k)
        {
            int now=d[a[i]][k];
            add(dp[now],dp[now-1]);
        }
    }
    int ans=0;
    for(int i=1;i<=1e6;++i)
        add(ans,dp[i]);
    printf("%d\n",ans);
    return 0;
}