#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=25e4+5;
int a[maxn];int t[4*maxn];int t2[4*maxn];
void build(int node,int tl,int tr)
{
    if((tr-tl)==1) {t[node]=tl;t2[node]=tl;return;}
    int tm=(tl+tr)/2;build(2*node+1,tl,tm);build(2*node+2,tm,tr);
    if(a[t[2*node+1]]>=a[t[2*node+2]]) t[node]=t[2*node+1]; else t[node]=t[2*node+2];
    if(a[t2[2*node+1]]<=a[t2[2*node+2]]) t2[node]=t2[2*node+1]; else t2[node]=t2[2*node+2];
}
pair<int,int> get(int node,int tl,int tr,int l,int r)
{
    if(tl>=l && tr<=r) {return {t[node],t2[node]};}
    if(tl>=r || tr<=l) return {-1,-1};
    int tm=(tl+tr)/2;
    pair<int,int> ans1=get(2*node+1,tl,tm,l,r);pair<int,int> ans2=get(2*node+2,tm,tr,l,r);
    if(ans1.first==(-1)) return ans2; if(ans2.first==(-1)) return ans1;
    pair<int,int> ans;
    if(a[ans1.first]>=a[ans2.first]) ans.first=ans1.first; else ans.first=ans2.first;
    if(a[ans1.second]<=a[ans2.second]) ans.second=ans1.second; else ans.second=ans2.second;
    /*cout<<ans1.first<<' '<<ans1.second<<endl;
    cout<<ans2.first<<' '<<ans2.second<<endl;
    cout<<tl<<' '<<tr<<' '<<ans.first<<' '<<ans.second<<" ans "<<endl;*/
    return ans;
}
int n;
int slv(int l,int r,int x,int y)
{
    if(r<l) return 0;
    if(r==l) return 1;
    pair<int,int> ans=get(0,0,n,l,r);
    //cout<<l<<' '<<r<<' '<<ans.first<<' '<<ans.second<<" tgrf "<<endl;
    if(a[ans.first]>max(x,y)) {return slv(l,ans.first,x,a[ans.first])+slv(ans.first+1,r,a[ans.first],y);}
    if(a[ans.second]<min(x,y)) {return slv(l,ans.second,x,a[ans.second])+slv(ans.second+1,r,a[ans.second],y);}
    return 1;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--)
    {
        cin>>n;for(int i=0;i<n;++i) cin>>a[i];
        build(0,0,n);cout<<slv(1,n-1,a[0],a[n-1])<<'\n';
    }
    return 0;
}