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
        int a[n];
        int sum=0;
        vector <int> v0;
        for(int i=0;i<n;++i)
        {
            cin>>a[i];
            a[i]%=2;
            if(a[i]==0) v0.push_back(i);
            sum+=a[i];
        }
        if(abs(2*sum-n)>=2)
        {
            cout<<(-1)<<'\n';
            continue;
        }
        int ans=0;
        if((2*sum)==n)
        {
            int ans1=0;
            for(int j=0;j<v0.size();++j)
            {
                ans1+=abs(v0[j]-(2*j));
            }
            int ans2=0;
            for(int j=0;j<v0.size();++j)
            {
                ans2+=abs(v0[j]-(2*j+1));
            }
            ans=min(ans1,ans2);
        }
        else if(2*sum<n)
        {
            for(int j=0;j<v0.size();++j)
            {
                ans+=abs(v0[j]-(2*j));
            }
        }
        else
        {
            for(int j=0;j<v0.size();++j)
            {
                ans+=abs(v0[j]-(2*j+1));
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}