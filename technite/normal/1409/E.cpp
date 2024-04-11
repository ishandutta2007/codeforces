#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        vector<int> x(n),y(n);
        for(int i=0;i<n;i++) cin>>x[i];
        for(int i=0;i<n;i++) cin>>y[i];
        sort(x.begin(),x.end());
        vector<long long> dp(n,0);
        for(int i=0;i<n;i++)
        {
            int end=x[i]+k;
            int index=upper_bound(x.begin(),x.end(),end)-x.begin();
            dp[i]=index-i;
        }
        vector<long long> mx(n,0);
        mx[n-1]=dp[n-1];
        for(int i=n-2;i>=0;i--)
        {
            mx[i]=max(mx[i+1],dp[i]);
        }
        //for(int i=0;i<n;i++) cout<<mx[i]<<" ";
        //    cout<<endl;
        long long ans=0;
        for(int i=0;i<n;i++)
        {
            long long temp=dp[i];
            int end=x[i]+k;
            int index=upper_bound(x.begin(),x.end(),end)-x.begin();
            if(index<n)
                temp+=mx[index];
            ans=max(ans,temp);
        }
        cout<<ans<<'\n';
    }
}