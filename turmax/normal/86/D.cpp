#pragma GCC optimize("O3","Ofast","unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>

using namespace std;
#define y1 higjeok
typedef long long ll;
const int maxa=1e6+5;
static int cnt[maxa];
ll ans=0;
const int sq=700;
bool cmp(pair<int,int> u,pair<int,int> v)
{
    int x1=u.first/sq;int y1=v.first/sq;
    if(x1<y1) return true;
    if(x1>y1) return false;
    if(x1 & 1) return u.second<v.second;
    return v.second<u.second;
}
int dist(pair<int,int> u,pair<int,int> v) {return abs(u.first-v.first)+abs(u.second-v.second);}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,q;cin>>n>>q;int a[n];for(int i=0;i<n;++i) cin>>a[i];vector<pair<int,int> > que1(q);for(int i=0;i<q;++i) {cin>>que1[i].first>>que1[i].second;que1[i].first--;}
    vector<pair<int,int> > que=que1;sort(que1.begin(),que1.end(),cmp);
    for(int l=1;l<q-3;++l) {if(dist(que1[l-1],que1[l])+dist(que1[l+1],que1[l+2])>dist(que1[l-1],que1[l+1])+dist(que1[l],que1[l+2])) swap(que1[l],que1[l+1]);}
    int curl=0;int curr=0;vector<pair<pair<int,int>,ll> > res;
    for(auto h:que1)
    {
        int l=h.first;int r=h.second;
        while(curl>l) {int x=a[curl-1];ans+=(2*cnt[x]+1)*1LL*x;++cnt[x];--curl;}
        while(curr<r) {int x=a[curr];ans+=(2*cnt[x]+1)*1LL*x;++cnt[x];++curr;}
        while(curl<l) {int x=a[curl];ans-=(2*cnt[x]-1)*1LL*x;--cnt[x];++curl;}
        while(curr>r) {int x=a[curr-1];ans-=(2*cnt[x]-1)*1LL*x;--cnt[x];--curr;}
        res.push_back({{l,r},ans});
    }
    sort(res.begin(),res.end());
    for(auto h:que) cout<<(*lower_bound(res.begin(),res.end(),make_pair(h,0LL))).second<<'\n';
    return 0;
}