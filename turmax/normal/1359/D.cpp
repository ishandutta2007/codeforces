#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=1e5+5;
int pr[maxn+1];
int slv(vector <int> a,int x)
{
    if(a.empty())
    {
        return -1e18;
    }
    int n=a.size();
    pr[0]=0;
    int mi=0;
    int ans=(-1e18);
    for(int i=0;i<n;++i)
    {
        pr[i+1]=pr[i]+a[i];
        ans=max(ans,pr[i+1]-mi);
        mi=min(pr[i+1],mi);
    }
    return ans-x;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    vector <int> a(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    int ans=0;
    for(int x=31;x>=(-30);--x)
    {
        bool h=false;
        vector <int> v;
        for(int i=0;i<n;++i)
        {
            if(a[i]>=x)
            {
                if(h)
                {
                    ans=max(ans,slv(v,x-1));
                    v.clear();
                    h=false;
                }
            }
            else
            {
                h=true;
                v.push_back(a[i]);
            }
        }
        ans=max(ans,slv(v,x-1));
        v.clear();
        h=false;
    }
    cout<<ans;
    return 0;
}