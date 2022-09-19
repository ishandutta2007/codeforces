#include <bits/stdc++.h>

using namespace std;
#define int long long
bool cmp(pair <int,int> u,pair<int,int> v)
{
    return (u.first+u.second)<(v.first+v.second);
}
const int maxn=4e3+5;
int delay[4*maxn];
int s[4*maxn];
void build(int node)
{
    delay[node]=0;
    s[node]=0;
    if((node+1)<(4*maxn))
    build(node+1);
}
/*void push(int node,int tl,int tr)
{
    int tm=(tl+tr)/2;
    delay[2*node+1]+=delay[node];
    s[2*node+1]+=(tm-tl)*delay[node];
    delay[2*node+2]+=delay[node];
    s[2*node+2]+=(tr-tm)*delay[node];
    delay[node]=0;
}*/
void to(int node,int tl,int tr,int l,int r)
{
    if(tl>=l && tr<=r)
    {
        /*cout<<l<<" l "<<r<<" r "<<endl;
        cout<<tl<<" tl "<<tr<<" tr "<<endl;
        cout<<node<<" node "<<endl;*/
        delay[node]++;
        s[node]+=(tr-tl);
        return;
    }
    if(tl>=r || tr<=l)
    {
        return;
    }
    int tm=(tl+tr)/2;
    to(2*node+1,tl,tm,l,r);to(2*node+2,tm,tr,l,r);
    s[node]=s[2*node+1]+s[2*node+2]+delay[node]*(tr-tl);
}
int get(int node,int tl,int tr,int l,int r)
{
    if(tl>=l && tr<=r)
    {
        return s[node];
    }
    if(tl>=r || tr<=l)
    {
        return 0;
    }
    int tm=(tl+tr)/2;
    return get(2*node+1,tl,tm,l,r)+get(2*node+2,tm,tr,l,r)+delay[node]*(min(r,tr)-max(l,tl));
}
int k;
int cntl[maxn];
int cntr[maxn];
int go(vector <pair<int,int> > a)
{
    for(int i=0;i<a.size();++i)
    {
        cntl[a[i].first]++;cntr[a[i].second]++;
    }
    int j=0;
    int currans=0;
    int sum=0;
    int n=a.size();
    for(int i=0;i<n;++i)
    {
        currans+=max(0LL,min(a[i].second,j+k-1)-max(a[i].first,j)+1);
        if(a[i].first<=j && a[i].second>=j) sum--;
        if(a[i].first<=(j+k) && a[i].second>=(j+k)) sum++;
    }
    int ans=currans;
    for(;j<(2e3+10)-k;++j)
    {
         currans+=sum;
         ans=max(ans,currans);
         sum-=cntl[j+1];
         sum+=cntr[j];
         sum+=cntl[j+k+1];
         sum-=cntr[j+k];
    }
    for(int i=0;i<a.size();++i)
    {
        cntl[a[i].first]--;cntr[a[i].second]--;
    }
    return ans;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m>>k;
    pair <int,int> a[m];
    for(int i=0;i<m;++i) cin>>a[i].first>>a[i].second;
    sort(a,a+m,cmp);
    int ans=0;
    for(int s=2;s<=(2*n);++s)
    {
        vector <pair<int,int> > v1,v2;
        for(int i=0;i<m;++i)
        {
            if((a[i].first+a[i].second)<=s)
            {
                v1.push_back(a[i]);
            }
            else
            {
                v2.push_back(a[i]);
            }
        }
        ans=max(ans,go(v1)+go(v2));
    }
    cout<<ans;
    return 0;
}