#include <bits/stdc++.h>

using namespace std;
#define int long long
#define pt pair<int,int>
#define x first
#define y second
const int p=1e9+7; ///!!!
const int maxn=1e6+5;
bool cmp(vector<int> v1,vector<int> v2)
{
    return ((vector<int>) {v1[0],v1[3],-v1[1],-v1[2]})<((vector<int>){v2[0],v2[3],-v2[1],-v2[2]});
}
int t[4*maxn];bool flag[4*maxn];
void push(int node,int tl,int tr)
{
    if(!flag[node]) return;
    int tm=(tl+tr)/2;
    flag[2*node+1]=true;flag[2*node+2]=true;flag[node]=false;t[2*node+1]=0;t[2*node+2]=0;
    return;
}
void f(int node,int tl,int tr,int l,int r)
{
    if(tl>=l && tr<=r) {flag[node]=true;t[node]=0;return;}
    if(tl>=r || tr<=l) return;
    push(node,tl,tr);
    int tm=(tl+tr)/2;
    f(2*node+1,tl,tm,l,r);f(2*node+2,tm,tr,l,r);
    t[node]=(t[2*node+1]+t[2*node+2])%p;
}
void to(int node,int tl,int tr,int pos,int val)
{
    if(tl>pos || tr<=pos) return;
    if((tr-tl)==1) {flag[node]=false;t[node]=val%p;return;}
    push(node,tl,tr);
    int tm=(tl+tr)/2;
    to(2*node+1,tl,tm,pos,val);to(2*node+2,tm,tr,pos,val);
    t[node]=(t[2*node+1]+t[2*node+2])%p;
}
int get(int node,int tl,int tr,int l,int r)
{
    if(tl>=l && tr<=r) return t[node]%p;
    if(tl>=r || tr<=l) return 0;
    push(node,tl,tr);
    int tm=(tl+tr)/2;
    return (get(2*node+1,tl,tm,l,r)+get(2*node+2,tm,tr,l,r))%p;
}
int t2[4*maxn];int delay2[4*maxn];
void push2(int node,int tl,int tr)
{
    int tm=(tl+tr)/2;
    int x=delay2[node];delay2[node]=0;
    delay2[2*node+1]+=x;delay2[2*node+2]+=x;
    t2[2*node+1]+=(tm-tl)*x;t2[2*node+2]+=(tr-tm)*x;
    t2[node]=t2[2*node+1]+t2[2*node+2];
}
void to2(int node,int tl,int tr,int l,int r,int val)
{
    if(tl>=l && tr<=r) {delay2[node]+=val;t2[node]+=(tr-tl)*val;return;}
    if(tl>=r || tr<=l) return;
    push2(node,tl,tr);
    int tm=(tl+tr)/2;
    to2(2*node+1,tl,tm,l,r,val);to2(2*node+2,tm,tr,l,r,val);
    t2[node]=t2[2*node+1]+t2[2*node+2];
}
int get2(int node,int tl,int tr,int l,int r)
{
    if(tl>=l && tr<=r) return t2[node];
    if(tl>=r || tr<=l) return 0;
    push2(node,tl,tr);
    int tm=(tl+tr)/2;
    return get2(2*node+1,tl,tm,l,r)+get2(2*node+2,tm,tr,l,r);
}
void pl1(int l,int r)
{
    //cout<<" to+ "<<l<<' '<<r+1<<endl;
    to2(0,0,maxn,l,r+1,1);
}
int lo(int hi)
{
    //cout<<" lo "<<hi<<endl;
    //cout<<get2(0,0,maxn,0,maxn)<<" get2 "<<endl;
    int low=0;int up=hi;
    while(up-low>1)
    {
        int mid=(low+up)/2;
        if(get2(0,0,maxn,mid,hi)==0) up=mid;
        else low=mid;
    }
    //cout<<low<<" low "<<endl;
    return low;
}
void pl(int l,int r)
{
    int h=lo(r+1);pl1(l,r);
    //cout<<l<<' '<<r<<' '<<h<<endl;
    if(!get2(0,0,maxn,r+1,r+2)) {int sum=get(0,0,maxn,h+1,r+2)%p;to(0,0,maxn,r+1,sum);} f(0,0,maxn,l,r+1);
}
void mi1(int l,int r)
{
    //cout<<" to- "<<l<<' '<<r+1<<endl;
    to2(0,0,maxn,l,r+1,-1);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m,k;cin>>n>>m>>k;
    pair<pt,pt> a[k];vector<vector<int> > v;
    for(int i=0;i<k;++i) {cin>>a[i].first.x>>a[i].first.y>>a[i].second.x>>a[i].second.y;v.push_back({a[i].first.x,a[i].first.y,a[i].second.y,0});v.push_back({a[i].second.x+1,a[i].first.y,a[i].second.y,1});}
    v.push_back({n+1,1,m-1,0});v.push_back({0,2,m,0});v.push_back({1,2,m,1});
    stable_sort(v.begin(),v.end(),cmp);
    to(0,0,maxn,1,1);
    for(auto h:v)
    {
        int x=h[0];int yl=h[1];int yr=h[2];int typ=h[3];
        if(typ==0)
        {
            pl(yl,yr);
        }
        else if(typ==1)
        {
            mi1(yl,yr);
        }
        else {assert(false);}
    }
    cout<<(get(0,0,maxn,0,m+1)%p+p)%p;
    return 0;
}
/*
5 5 3
2 5 2 5
2 2 2 2
2 1 2 1
*/