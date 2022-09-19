#include <bits/stdc++.h>

using namespace std;
#define int long long
int go(vector <int> a)
{
    int ans=0;
    for(int i=1;i<(a.size()-1);++i)
    {
        if((a[i]-a[i-1])*(a[i]-a[i+1])>0) {++ans;}
    }
    return ans;
}
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
        for(int i=0;i<n;++i) cin>>a[i];
        int ans=0;
        bool is[n];
        for(int i=0;i<n;++i) is[i]=false;
        for(int i=1;i<(n-1);++i)
        {
            if((a[i]-a[i-1])*(a[i]-a[i+1])>0) {++ans;is[i]=true;}
        }
        int res=max(0LL,ans-1);
        for(int i=1;i<(n-1);++i)
        {
            for(int j:{i-1,i+1})
            {
                int x=a[i];
                vector <int> v1,v2;
                for(int k=max(0LL,i-3);k<=min(n-1,i+3);++k)
                {
                    v1.push_back(a[k]);
                }
                a[i]=a[j];
                for(int k=max(0LL,i-3);k<=min(n-1,i+3);++k)
                {
                    v2.push_back(a[k]);
                }
                res=min(res,ans+go(v2)-go(v1));
                a[i]=x;
            }
        }
        cout<<res<<'\n';
    }
    return 0;
}