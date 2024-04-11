#pragma GCC target("popcnt")
#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=100;
vector<int> a[maxn];
vector<int> pref[maxn];
int b[maxn];
vector<int> h;
int n,b1,p,m;
int sz;
int ans=0;
int comp(int mask)
{
    int cur=1;int cur1=1;
    for(int i=0;i<h.size();++i)
    {
         cur1*=h[i];
    }
    int ans0=cur1;
    for(int i=0;i<sz;++i)
    {
        b[i]=(cur1-cur1/cur);
        ans0+=(cur1/cur)*pref[i].back();
        if(i<h.size() && !(mask & (1LL<<i)))
        {
            cur*=h[i];
        }
    }
    int o=m*__builtin_popcountll(mask);
    int low=(-1);int up=4e18+1e9;
    while(up-low>1)
    {
        int mid=(low+up)/2;int cnt=0;
        for(int i=0;i<sz;++i) {if(b[i]!=0) {cnt+=(a[i].end()-upper_bound(a[i].begin(),a[i].end(),mid/b[i]));}}
        if(mid==69) cout<<cnt<<" cnt "<<endl;
        if(p*cnt+o>b1) {low=mid;}
        else {up=mid;}
    }
    int mid=up;int cnt=0;int ans=0;
    for(int i=0;i<sz;++i) {
        if(b[i]==0) continue;
        int pos1=upper_bound(a[i].begin(),a[i].end(),mid/b[i])-a[i].begin();
        cnt+=(a[i].size()-pos1);
        ans+=(pref[i].back()-pref[i][pos1])*b[i];
    }
    int h=(b1-o-p*cnt)/p;
    ans+=(h*up);
    return ans0+ans;
}
void go(int pos,int mask,int curma)
{
    if(m*__builtin_popcountll(mask)>b1) return;
    if(pos==h.size())
    {
        ans=max(ans,comp(mask));
        return;
    }
    if(h[pos]<curma)
    {
        go(pos+1,mask,curma);
    }
    else
    {
        go(pos+1,mask,curma+1);
        mask+=(1LL<<pos);
        go(pos+1,mask,h[pos]);
    }
}
int pos=0;
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    {
        cin>>n>>b1>>p>>m;
        vector<int> v;
        for(int i=0;i<n;++i)
        {
            char s;int x;cin>>s>>x;
            if(s=='*' && x==1) continue;
            if(s=='+') {v.push_back(x);}
            else {a[pos]=v;++pos;h.push_back(x);v.clear();}
        }
        a[pos]=v;++pos;sz=pos;
        int ans0=0;
        for(int i=0;i<sz;++i) {sort(a[i].begin(),a[i].end());pref[i].resize(a[i].size()+1);pref[i][0]=0;for(int j=0;j<a[i].size();++j) pref[i][j+1]=pref[i][j]+a[i][j];}
        int cur=1;int cur1=1;
        go(0,0,-1);
        cout<<ans;
    }
    return 0;
}