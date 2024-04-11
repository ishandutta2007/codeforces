#include <bits/stdc++.h>

using namespace std;
#define int long long
const int p=1e9+7;
int po(int a,int b)
{
    if(b==0) return 1;
    if(b==1) return a;
    if(b%2==0)
    {
        int u=po(a,b/2);
        return (u*u)%p;
    }
    else
    {
        int u=po(a,b-1);
        return (a*u)%p;
    }
}
int inv(int x)
{
    return po(x,p-2);
}
int slv(vector <pair<int,int> > v,int d)
{
    int ans=0;
    int inv1[2*v.size()+5];
    for(int i=(-((int) v.size())-1);i<=(v.size()+1);++i)
    {
        if(i==0) continue;
        inv1[v.size()+i+1]=inv(i);
    }
    for(int i=0;i<v.size();++i)
    {
        int curr=1;
        for(int j=0;j<v.size();++j)
        {
            if(i==j) continue;
            curr*=(d-v[j].first);
            curr%=p;
            curr*=inv1[v[i].first-v[j].first+1+v.size()];
            curr%=p;
        }
        curr*=v[i].second;
        curr%=p;
        ans+=curr;
        ans%=p;
        ans+=p;
        ans%=p;
    }
    return ans;
}
const int maxn=3e3+5;
int dp[maxn][2*maxn+2];
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,d;
    cin>>n>>d;
    int n2=(2*n+1);
    int pr[n];
    vector <int> u[n];
    for(int i=0;i<(n-1);++i)
    {
        int x;
        cin>>x;
        x--;
        pr[i+1]=x;
        u[x].push_back(i+1);
    }
    for(int i=(n-1);i>=0;i--)
    {
        for(int j=1;j<=n2;++j)
        {
            dp[i][j]=1;
            for(auto h:u[i])
            {
                dp[i][j]*=dp[h][j];
                dp[i][j]%=p;
            }
        }
        for(int j=2;j<=n2;++j)
        {
            dp[i][j]+=dp[i][j-1];
            dp[i][j]%=p;
        }
    }
    vector <pair<int,int> > v;
    for(int i=1;i<=n2;++i)
    {
        v.push_back({i,dp[0][i]});
    }
    cout<<slv(v,d)<<endl;
    return 0;
}