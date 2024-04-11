#pragma GCC optimize("O3","unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>

using namespace std;
#define int long long
const int p=1e9+7;
const int maxn=2e5+5;
int fe1[maxn];int fe2[maxn];
void pl(int pos,int val,int we) {while(pos<maxn) {fe1[pos]+=(we*val);fe1[pos]%=p;fe2[pos]+=val;fe2[pos]%=p;pos|=(pos+1);}}
int get1(int pos) {int ans=0;while(pos>=0) {ans+=fe1[pos];ans%=p;pos&=(pos+1);--pos;} return ans;}
int get2(int pos) {int ans=0;while(pos>=0) {ans+=fe2[pos];ans%=p;pos&=(pos+1);--pos;} return ans;}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,q;cin>>n>>q;int a[n];for(int i=0;i<n;++i) cin>>a[i]; int b[n];for(int i=0;i<n;++i) cin>>b[i];
    int pr[n+1]={0};int w[n]={0};for(int i=0;i<n;++i) pr[i+1]=pr[i]+b[i]; for(int i=1;i<n;++i) w[i]=a[i]-a[i-1]; w[0]=0;
    int ans[2*q]={0};vector<pair<int,int> > que;for(int i=0;i<q;++i) {int l,r;cin>>l>>r;--l;que.push_back({l,r});}
    vector<pair<int,int> > d[n+1];for(int id=0;id<q;++id) {auto [l,r]=que[id];d[l].push_back({pr[l],2*id});d[r].push_back({pr[l],2*id+1});}
    int sum1=0;int sum2=0;vector<int> v;for(int i=0;i<=n;++i) v.push_back(pr[i]); sort(v.begin(),v.end());v.erase(unique(v.begin(),v.end()),v.end());
    for(int i=0;i<=n;++i)
    {
        pl(lower_bound(v.begin(),v.end(),pr[i])-v.begin(),w[i],pr[i]%p);
        sum1+=((pr[i]%p)*w[i]);sum2+=w[i];
        sum1%=p;sum2%=p;
        for(pair<int,int> h:d[i])
        {
            int x=h.first;int id=h.second;
            int o1=get1(lower_bound(v.begin(),v.end(),x)-v.begin());int o2=get2(lower_bound(v.begin(),v.end(),x)-v.begin());
            x%=p;
            ans[id]=(((o2*x-o1)%p)-(((sum2-o2)*x)%p)+(sum1-o1))%p;
        }
    }
    for(int id=0;id<q;++id) {cout<<((ans[2*id+1]-ans[2*id])%p+p)%p<<'\n';}
    return 0;
}
/*
4 4
1 2 3 4
-1 1 -1 1
1 2
1 4
2 3
3 4
*/