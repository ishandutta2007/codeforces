#pragma GCC optimize("Ofast","unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=3e4+5;
int mod;
int fib[maxn];bool cnt[maxn];
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;cin>>n>>mod;
    int a[n];fib[1]=1;fib[2]=1;for(int i=3;i<=n;++i) {fib[i]=(fib[i-1]+fib[i-2])%mod;}vector <int> v;
    for(int i=0;i<n;++i) {cin>>a[i];v.push_back(a[i]);}
    sort(v.begin(),v.end());v.erase(unique(v.begin(),v.end()),v.end());
    for(auto &h:a) h=lower_bound(v.begin(),v.end(),h)-v.begin();
    int b[v.size()];for(int i=0;i<v.size();++i) b[i]=v[i];
    int q;cin>>q;
    //vector <vector<int> > que;int ans[q]={0};
    for(int id=0;id<q;++id)
    {
        int l,r;cin>>l>>r;
        l--;
        //que.push_back({l,r,id});
        int ans=0;
        for(int j=l;j<r;++j) if(!cnt[a[j]]) {cnt[a[j]]=true;}
        int cur=0;
        for(int i=0;i<n;++i)
        {
            if(cnt[i]) {++cur;ans+=fib[cur]*b[i];}
        }
        for(int j=l;j<r;++j) cnt[a[j]]=false;
        cout<<ans%mod<<'\n';
    }
    //sort(que.begin(),que.end(),cmp);
    return 0;
}