#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=2e5+5;
int t[4*maxn];
int cnt[maxn];
void to(int node,int tl,int tr,int l,int r,int val)
{
    if(tl>=l && tr<=r)
    {
        t[node]+=val;
        return;
    }
    if(tl>=r || tr<=l) return;
    int tm=(tl+tr)/2;
    to(2*node+1,tl,tm,l,r,val);to(2*node+2,tm,tr,l,r,val);
}
int get(int node,int tl,int tr,int pos)
{
    if(tl>pos || tr<=pos) return 0;
    int ans=t[node];if((tr-tl)==1) return ans;
    int tm=(tl+tr)/2;
    ans+=get(2*node+1,tl,tm,pos)+get(2*node+2,tm,tr,pos);
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
        vector <int> mom;
        for(int i=0;i<n;++i) {cin>>a[i];mom.push_back(a[i]);}
        sort(mom.begin(),mom.end());mom.erase(unique(mom.begin(),mom.end()),mom.end());
        for(auto &h:a) h=lower_bound(mom.begin(),mom.end(),h)-mom.begin();
        int res=0;
        for(int i=0;i<n;++i)
        {
            int o=get(0,0,maxn,a[i]);
            res+=min(o,i-o-cnt[a[i]]);
            to(0,0,maxn,a[i]+1,maxn,1);
            cnt[a[i]]++;
        }
        for(int i=0;i<n;++i)
        {
            to(0,0,maxn,a[i]+1,maxn,-1);
            cnt[a[i]]--;
        }
        cout<<res<<'\n';
    }
    return 0;
}