#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=2e5+100,K=300;

int dp[N],best[N];

int cnt(int k,int n)
{
    int res=0;
    while(n>1)
        n=(n+k-1)/k,
        res++;
    return res;
}

vector<pii> ans;

void solve(int n)
{
    if(n<=2)
        return;

    if(n>=K)
    {
        dp[n]=1e9;
        for(int k=2;k<=min(K-1,n-1);k++)
        {
            int cur=n-k-1+cnt(k,n)+dp[k];
            if(dp[n]>cur)
            {
                dp[n]=cur;
                best[n]=k;
            }
        }
    }

    int k=best[n];
    for(int i=k+1;i<=n-1;i++)
        ans.push_back({i,i+1});
    int val=n;
    while(val>1)
        ans.push_back({n,k}),
        val=(val+k-1)/k;
    solve(k);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    dp[1]=dp[2]=0;
    for(int n=3;n<K;n++)
    {
        dp[n]=1e9;
        for(int k=2;k<=n-1;k++)
        {
            int cur=n-k-1+cnt(k,n)+dp[k];
            if(dp[n]>cur)
            {
                dp[n]=cur;
                best[n]=k;
            }
        }
    }

    int t=N/K;
    cin>>t;
    while(t--)
    {
        int n=K;
        cin>>n;
        ans.clear();
        solve(n);
        cout<<ans.size()<<"\n";
        for(auto[i,j]:ans)
            cout<<i<<" "<<j<<"\n";
    }
}