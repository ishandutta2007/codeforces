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
        for(int i=0;i<n;++i) {cin>>a[i];sum+=a[i];}
        if((sum%n)!=0)
        {
            cout<<(-1)<<endl;
            continue;
        }
        vector <vector<int> > res;
        for(int i=2;i<=n;++i)
        {
            int z=(i-a[i-1]%i);
            if(z==i) z=0;
            res.push_back({1,i,z});
            a[i-1]+=z;
            a[0]-=z;
            res.push_back({i,1,a[i-1]/i});
            a[0]+=a[i-1];
            a[i-1]=0;
        }
        int u=(sum/n);
        for(int i=2;i<=n;++i)
        {
            res.push_back({1,i,u});
        }
        cout<<res.size()<<endl;
        for(auto h:res)
        {
            cout<<h[0]<<' '<<h[1]<<' '<<h[2]<<endl;
        }
    }
    return 0;
}