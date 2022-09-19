#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=3e5+7;
int u[maxn];
int cnt[maxn];
int is[maxn];
vector <int> rasl(int x)
{
    vector <int> v;
    if(x==1)
    {
        return v;
    }
    for(int i=2;i*i<=x;++i)
    {
        if(x%i==0)
        {
            v=rasl(x/i);
            v.push_back(i);
            return v;
        }
    }
    v.push_back(x);
    return v;
}
int h(vector <int> v)
{
    int sz=v.size();
    int ans=0;
    for(int mask=0;mask<(1<<sz);++mask)
    {
        int u=1;
        int o=1;
        for(int j=0;j<sz;++j)
        {
            if(mask & (1<<j))
            {
                u*=v[j];
                o*=(-1);
            }
        }
        ans+=(cnt[u]*o);
    }
    return ans;
}
vector <int> go(vector <int> v)
{
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    return v;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    int g=0;
    int a[n];
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        u[a[i]]++;
        g=__gcd(a[i],g);
    }
    if(g!=1)
    {
        cout<<(-1);
        return 0;
    }
    for(int i=1;i<maxn;++i)
    {
        for(int j=1;(i*j)<maxn;++j)
        {
            cnt[i]+=u[i*j];
        }
    }
    for(int i=1;i<maxn;++i)
    {
        vector <int> v=go(rasl(i));
        is[i]=h(v);
    }
    int ans=1e18;
    for(int i=0;i<n;++i)
    {
        vector <int> z=go(rasl(a[i]));
        int sz=z.size();
        bool can[(1<<sz)];
        for(int mask=0;mask<(1<<sz);++mask)
        {
            int curr=1;
            for(int j=0;j<sz;++j)
            {
                if(mask & (1<<j))
                {
                    curr*=z[j];
                }
            }
            can[mask]=is[curr];
        }
        int sl[(1<<sz)];
        sl[0]=1;
        for(int i=1;i<(1<<sz);++i)
        {
            sl[i]=1e18;
            for(int j=i;j>0;j=((j-1) & i))
            {
                if(can[j])
                {
                    sl[i]=min(sl[i],sl[i^j]+1);
                }
            }
            //cout<<i<<" "<<sl[i]<<endl;
        }
        ans=min(ans,sl[(1<<sz)-1]);
        //cout<<" next_loop "<<endl;
    }
    cout<<ans;
    return 0;
}