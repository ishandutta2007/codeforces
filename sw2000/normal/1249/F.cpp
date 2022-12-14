#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e2+10;
const int inf=0x3f3f3f3f;
const ll mod=1e9+7;
const ll linf=0x3f3f3f3f3f3f3f3f;
const double pi=acos(-1);
int n,k,w[maxn],dp[maxn][maxn];
vector<int>v[maxn];

void del(int o,int f)
{
    int dl=-1;
    for(int i=0;i<v[o].size();i++)
    {
        if(v[o][i]==f)dl=i;
        else del(v[o][i],o);
    }
    if(dl!=-1)v[o].erase(v[o].begin()+dl);
}

void dfs(int o)
{
    if(v[o].size()==0)
        return;
    for(auto i:v[o])
    {
        dfs(i);
        dp[o][0]+=dp[i][k];
    }
    for(int i=k;i;i--)
    {
        int ma=0,sum=0;
        for(int j:v[o])
        {
            sum+=dp[j][max(k-i,i-1)];
            ma=max(ma,dp[j][i-1]-dp[j][k-i]);
        }
        dp[o][i]=max(dp[o][i+1],sum+ma);
    }
    dp[o][0]=max(dp[o][0],dp[o][1]);
}

int main()
{
    //freopen("in.txt","r",stdin);
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>dp[i][0];
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    del(1,0);
    dfs(1);
    cout<<dp[1][0];
//    for(int i=1;i<=n;i++)
//    {
//        for(int j=0;j<=k;j++)
//        {
//            cout<<dp[i][j]<<' ';
//        }
//        cout<<endl;
//    }
    return 0;
}