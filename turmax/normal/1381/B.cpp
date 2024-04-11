#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
    int n;
    cin>>n;
    int a[2*n];
    int u[2*n];
    for(int i=0;i<(2*n);++i) {cin>>a[i];a[i]--;u[a[i]]=i;}
    int curr=(2*n);
    vector <int> v;
    while(curr)
    {
        int ma=(-1);
        int o=0;
        for(int i=0;i<curr;++i)
        {
             if(a[i]>ma)
             {
                 ma=a[i];
                 o=i;
             }
        }
        v.push_back(curr-o);
        curr=o;
    }
    int sz=4*n+4;
    bool dp[sz][v.size()+1];
    for(int i=0;i<(sz);++i)
    {
        for(int j=0;j<=v.size();++j)
        {
            dp[i][j]=false;
        }
    }
    dp[2*n+2][0]=true;
    for(int i=1;i<=v.size();++i)
    {
        for(int j=0;j<sz;++j)
        {
            bool h=false;
            int r=v[i-1];
            if((j-r)>=0 && dp[j-r][i-1])
            {
                h=true;
            }
            if((j+r)<sz && dp[j+r][i-1])
            {
                h=true;
            }
            dp[j][i]=h;
        }
    }
    if(dp[2*n+2][v.size()])
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
    }
    return 0;
}