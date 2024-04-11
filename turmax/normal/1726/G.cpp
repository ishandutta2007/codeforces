#include <bits/stdc++.h>

using namespace std;
#define int long long
const int p=998244353;
const int maxn=5e5+5;
int fact[maxn];
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    fact[0]=1;for(int i=1;i<maxn;++i) {fact[i]=(fact[i-1]*i)%p;}
    int n;cin>>n;pair<int,int> a[n];for(int i=0;i<n;++i) cin>>a[i].first; for(int i=0;i<n;++i) cin>>a[i].second;
    sort(a,a+n);
    int pos=min_element(a,a+n)-a;int mi=a[pos].first;int pos2=max_element(a,a+n)-a;
    if(a[pos2].first==mi)
    {
        int ans=1;for(int i=1;i<=n;++i) {ans*=i;ans%=p;}
        cout<<ans;return 0;
    }
    if(a[pos].second==0)
    {
        cout<<0;return 0;
    }
    for(int i=0;i<n;++i)
    {
        if(i==pos) continue;
        if(a[i].first==a[pos].first)
        {
            cout<<0;return 0;
        }
    }
    int c=a[pos].first+n-1;
    map<int,vector<int> > h;map<pair<int,int>,int> u;
    for(int i=0;i<n;++i) h[a[i].first].push_back(a[i].second);
    int ans=1;int cnt=0;
    for(auto [key,val]:h)
    {
        int cnt2=cnt;
        cnt+=val.size();
        int cnt0=0,cnt1=0;
            for(auto h:val)
            {
                if(h==0) ++cnt0; else ++cnt1;
            }
        if(key==c)
        {
            for(int i=1;i<=cnt0;++i) {ans*=i;ans%=p;}
            for(int i=n-cnt1+1;i<=n;++i) {ans*=i;ans%=p;}
            continue;
        }
        int o=c-key;
        if(o<0) {cout<<0;return 0;}
        u.clear();int val0=o;int val1=n-val.size()-o;
        if(val0<val1 && val0+cnt0>=val1 && cnt1>0) {cout<<0;return 0;}
        for(auto h:val)
        {
            if(h==0) u[{0,val0}]++;
            else u[{1,val1}]++;
        }
        for(auto [key1,val1]:u)
        {
            if(key1.second<0) {cout<<0;return 0;}
            if(key1.second>cnt2) {cout<<0;return 0;}
            ans*=fact[val1];ans%=p;
        }
    }
    cout<<ans;
    return 0;
}