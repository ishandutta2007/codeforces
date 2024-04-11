#include <bits/stdc++.h>

using namespace std;
#define int long long
bool comp(pair <pair<int,int>,int> a,pair<pair<int,int>,int> b)
{
    return a.first.second<b.first.second;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
    int n,k;
    cin>>n>>k;
    pair <pair<int,int>,int> a[n];
    for(int i=0;i<n;++i)
    {
        cin>>a[i].first.first>>a[i].first.second;
        a[i].second=i;
    }
    sort(a,a+n,comp);
    int dp[n+1][k+1];
    bool is[n+1][k+1];
    for(int i=0;i<=k;++i)
    {
        dp[0][i]=(-1e18);
    }
    for(int i=0;i<=n;++i)
    {
        dp[i][0]=0;
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=k;++j)
        {
            dp[i][j]=(-1e18);
            if((dp[i-1][j-1]+(a[i-1].first.first-a[i-1].first.second*(k-j)))>dp[i][j])
            {
                dp[i][j]=(dp[i-1][j-1]+(a[i-1].first.first-a[i-1].first.second*(k-j)));
                is[i][j]=true;
            }
            if((dp[i-1][j])>dp[i][j])
            {
                dp[i][j]=dp[i-1][j];
                is[i][j]=false;
            }
            //cout<<i<<" "<<j<<" "<<dp[i][j]<<" "<<"dp[i][j]"<<endl;
        }
    }
    //cout<<dp[n][k]<<" dp[n][k] "<<endl;
    pair <int,int> curr=make_pair(n,k);
    vector <int> z;
    while(true)
    {
        if(curr.second==0)
        {
            break;
        }
        if(is[curr.first][curr.second])
        {
            //cout<<curr.first<<endl;
            //cout<<a[curr.first].second<<endl;
            curr.first--;curr.second--;
            z.push_back(a[curr.first].second);
        }
        else
        {
            curr.first--;
        }
    }
    bool used[n];
    for(int i=0;i<n;++i)
    {
        used[i]=false;
    }
    for(int i=0;i<z.size();++i)
    {
        //cout<<z[i]<<" z[i] "<<endl;
        used[z[i]]=true;
    }
    reverse(z.begin(),z.end());
    cout<<2*n-k<<endl;
    for(int i=0;i<z.size()-1;++i)
    {
        cout<<z[i]+1<<" ";
    }
    for(int i=0;i<n;++i)
    {
        if(!used[i])
        {
            cout<<(i+1)<<" ";
            cout<<(-i-1)<<" ";
        }
    }
    cout<<z[z.size()-1]+1<<" ";
    cout<<endl;
    }
    return 0;
}