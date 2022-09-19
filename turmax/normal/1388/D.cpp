#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=2e5+5;
int r[maxn];
int a[maxn];
int b[maxn];
int go(int i)
{
    if(r[i]!=(-1)) return r[i];
    if(b[i]==(-1)) {r[i]=0;return 0;}
    r[i]=go(b[i])+1;
    return r[i];
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    for(int i=0;i<maxn;++i) r[i]=(-1);
    int n;
    cin>>n;
    for(int i=0;i<n;++i) cin>>a[i];
    for(int i=0;i<n;++i) {cin>>b[i];b[i]--;}
    for(int i=0;i<n;++i)
    {
        go(i);
    }
    vector <pair<int,int> > z;
    for(int i=0;i<n;++i)
    {
        z.push_back({-r[i],i});
    }
    sort(z.begin(),z.end());
    vector <int> res1;
    vector <int> res2;
    int ans=0;
    for(int i=0;i<z.size();++i)
    {
        int x=z[i].second;
        if(a[x]>=0)
        {
            res1.push_back(x);
            ans+=a[x];
            if(b[x]!=(-1))
            {
                a[b[x]]+=a[x];
            }
        }
        else
        {
            res2.push_back(x);
            ans+=a[x];
        }
    }
    cout<<ans<<endl;
    for(auto v:res1)
    {
        cout<<v+1<<' ';
    }
    reverse(res2.begin(),res2.end());
    for(auto v:res2)
    {
        cout<<v+1<<' ';
    }
    return 0;
}