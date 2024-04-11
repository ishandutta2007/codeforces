#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=1e6+5;
int t[4*maxn];
void to(int node,int tl,int tr,int pos,int x)
{
    if(tl>pos || tr<=pos)
    {
        return;
    }
    t[node]+=x;
    if((tr-tl)==1) return;
    int tm=(tl+tr)/2;
    to(2*node+1,tl,tm,pos,x);to(2*node+2,tm,tr,pos,x);
}
int get(int node,int tl,int tr,int l,int r)
{
    if(tl>=l && tr<=r)
    {
        return t[node];
    }
    if(tl>=r || tr<=l)
    {
        return 0;
    }
    int tm=(tl+tr)/2;
    return get(2*node+1,tl,tm,l,r)+get(2*node+2,tm,tr,l,r);
}
bool cmp(pair <int,pair<int,int> > a,pair <int,pair<int,int> > b)
{
    return a.second.second<b.second.second;
}
int go(vector <pair<int,pair<int,int> > > a,vector <pair<int,pair<int,int> > > b)
{
    for(int i=0;i<4*maxn;++i) t[i]=0;
    sort(a.begin(),a.end());
    sort(b.begin(),b.end(),cmp);
    int ans=0;
    int curr1=0;
    int curr2=0;
    for(int i=0;i<=1e6;++i)
    {
        while(curr1<a.size() && a[curr1].first==i)
        {
            to(0,0,maxn,a[curr1].second.second,1);
            ++curr1;
        }
        while(curr2<b.size() && b[curr2].second.second==i)
        {
            ans+=get(0,0,maxn,b[curr2].first,1e6+1);
            ++curr2;
        }
    }
    return ans;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    vector <pair<int,pair<int,int> > > a1;
    vector <pair<int,pair<int,int> > > a2;
    int ans=1;
    for(int i=0;i<n;++i)
    {
        int y,l,r;
        cin>>y>>l>>r;
        if((r-l)==1e6) ++ans;
        if(l==0)
        {
            a1.push_back({y,{l,r}});
        }
        else
        {
            a2.push_back({y,{l,r}});
        }
    }
    vector <pair<int,pair<int,int> > > b1;
    vector <pair<int,pair<int,int> > > b2;
    for(int i=0;i<m;++i)
    {
        int x,l,r;
        cin>>x>>l>>r;
        if((r-l)==1e6) ++ans;
        if(l==0)
        {
            b1.push_back({x,{l,r}});
        }
        else
        {
            b2.push_back({x,{l,r}});
        }
    }
    ans+=go(a1,b1);
    vector <pair<int,pair<int,int> > > b11=b1;
    vector <pair<int,pair<int,int> > > a21=a2;
    for(int i=0;i<b1.size();++i)
    {
        b11[i].first=1e6-b11[i].first;
    }
    for(int i=0;i<a2.size();++i)
    {
        a21[i].second.first=1e6-a21[i].second.first;
        a21[i].second.second=1e6-a21[i].second.second;
        swap(a21[i].second.first,a21[i].second.second);
    }
    ans+=go(a21,b11);
    vector <pair<int,pair<int,int> > > b21=b2;
    vector <pair<int,pair<int,int> > > a11=a1;
    for(int i=0;i<a1.size();++i)
    {
        a11[i].first=1e6-a11[i].first;
    }
    for(int i=0;i<b2.size();++i)
    {
        b21[i].second.first=1e6-b21[i].second.first;
        b21[i].second.second=1e6-b21[i].second.second;
        swap(b21[i].second.first,b21[i].second.second);
    }
    ans+=go(a11,b21);
    vector <pair<int,pair<int,int> > > b22=b2;
    vector <pair<int,pair<int,int> > > a22=a2;
    for(int i=0;i<a2.size();++i)
    {
        a22[i].first=1e6-a22[i].first;
        a22[i].second.first=1e6-a22[i].second.first;
        a22[i].second.second=1e6-a22[i].second.second;
        swap(a22[i].second.first,a22[i].second.second);
    }
    for(int i=0;i<b2.size();++i)
    {
        b22[i].first=1e6-b22[i].first;
        b22[i].second.first=1e6-b22[i].second.first;
        b22[i].second.second=1e6-b22[i].second.second;
        swap(b22[i].second.first,b22[i].second.second);
    }
    ans+=go(a22,b22);
    cout<<ans<<endl;
    return 0;
}