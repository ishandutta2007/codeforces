#include <bits/stdc++.h>

using namespace std;
#define int long long
void ext(vector <int> &v,vector <int> v2)
{
    for(int i=0;i<v2.size();++i)
    {
        v.push_back(v2[i]);
    }
}
vector <int> rasl(int n)
{
    vector <int> v;
    if(n==1) return v;
    for(int i=2;i*i<=n;++i)
    {
        if(n%i==0)
        {
            v=rasl(n/i);
            v.push_back(i);
            return v;
        }
    }
    v.push_back(n);
    return v;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,x,y;
    cin>>n>>x>>y;
    int a[n];
    for(int i=0;i<n;++i) cin>>a[i];
    vector <int> v;
    ext(v,rasl(a[0]+1));
    ext(v,rasl(a[0]));
    ext(v,rasl(a[0]-1));
    ext(v,rasl(a[n-1]+1));
    ext(v,rasl(a[n-1]));
    ext(v,rasl(a[n-1]-1));
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    int ans=1e18;
    for(auto p:v)
    {
        int b[n];
        int l=1e18;int r=0;
        for(int i=0;i<n;++i)
        {
            if(a[i]%p==0)
            {
                b[i]=0;
            }
            else if((a[i]+1)%p==0 || (a[i]-1)%p==0)
            {
                b[i]=y;
            }
            else
            {
                b[i]=1e18;
                l=min(l,i);r=max(r,i);
            }
        }
        if(l==1e18)
        {
            int sum=0;
            for(int i=0;i<n;++i)
            {
                sum+=b[i];
            }
            int pr[n+1];
            pr[0]=0;
            int ma1=0;
            int ans1=0;
            for(int i=0;i<n;++i)
            {
                pr[i+1]=pr[i]+(x-b[i]);
                ma1=max(ma1,pr[i+1]);
                ans1=min(ans1,pr[i+1]-ma1);
            }
            ans=min(ans,sum+ans1);
            continue;
        }
        int sum=(r-l+1)*x;
        for(int i=0;i<l;++i)
        {
            sum+=b[i];
        }
        for(int i=(r+1);i<n;++i)
        {
            sum+=b[i];
        }
        int ans1=0;
        int u1=0;
        for(int i=(l-1);i>=0;i--)
        {
            u1+=(x-b[i]);
            ans1=min(ans1,u1);
        }
        int ans2=0;
        int u2=0;
        for(int i=(r+1);i<n;++i)
        {
            u2+=(x-b[i]);
            ans2=min(ans2,u2);
        }
        ans=min(ans,sum+ans1+ans2);
    }
    cout<<ans;
    return 0;
}