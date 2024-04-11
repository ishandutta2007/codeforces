#include <bits/stdc++.h>

using namespace std;
#define int long long
const int p=998244353;
int inv2=(p+1)/2;
const int maxn=5e5+5;
vector <int> a[maxn];
bool used[maxn];
int dp[maxn][2];
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
void dfs(int x)
{
    used[x]=true;
    int r=1;
    int sz=0;
    for(auto v:a[x])
    {
        if(!used[v])
        {
            dfs(v);
            dp[x][0]+=dp[v][1];
            dp[x][0]%=p;
            ++sz;
            r*=(1+dp[v][1]-dp[v][0]);
            r%=p;
        }
    }
    r*=po(inv2,sz);
    r%=p;
    dp[x][1]=dp[x][0]+(1-r);
    dp[x][1]%=p;
    //cout<<x<<" x "<<endl;
    //cout<<dp[x][0]<<' '<<dp[x][1]<<endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<(n-1);++i)
    {
        int x,y;
        cin>>x>>y;
        x--;y--;
        a[x].push_back(y);a[y].push_back(x);
    }
    dfs(0);
    cout<<((dp[0][1]*po(2,n))%p+p)%p;
    return 0;
}