#include <bits/stdc++.h>

using namespace std;
//#define int long long
const int maxn=4e5+5;
int t1[4*maxn];
int t2[4*maxn];
int delay1[4*maxn];
int delay2[4*maxn];
pair <int,int> h[maxn];
void to1(int node,int tl,int tr,int l,int r,int val)
{
    if(tl>=r || tr<=l)
    {
        return;
    }
    if(tl>=l && tr<=r)
    {
        t1[node]+=val;
        delay1[node]+=val;
        return;
    }
    int tm=(tl+tr)/2;
    to1(2*node+1,tl,tm,l,r,val);to1(2*node+2,tm,tr,l,r,val);
    t1[node]=max(t1[2*node+1],t1[2*node+2])+delay1[node];
}
void to2(int node,int tl,int tr,int l,int r,int val)
{
    if(tl>=r || tr<=l)
    {
        return;
    }
    if(tl>=l && tr<=r)
    {
        t2[node]+=val;
        delay2[node]+=val;
        return;
    }
    int tm=(tl+tr)/2;
    to2(2*node+1,tl,tm,l,r,val);to2(2*node+2,tm,tr,l,r,val);
    t2[node]=max(t2[2*node+1],t2[2*node+2])+delay2[node];
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    for(int i=0;i<maxn;++i) h[i]={-1,-1};
    int n;
    cin>>n;
    vector <pair<int,pair<int,int> > > a(n);
    vector <pair<int,int> > mom;
    for(int i=0;i<n;++i)
    {
        cin>>a[i].second.first>>a[i].second.second>>a[i].first;
        mom.push_back({a[i].second.first,i});mom.push_back({a[i].second.second,i+n});
    }
    vector <pair<int,pair<int,int> > > b=a;
    sort(mom.begin(),mom.end());
    for(int i=0;i<mom.size();++i)
    {
        pair <int,int> o=mom[i];
        if(o.second<n)
        {
            h[i]={o.second,0};
            b[o.second].second.first=i;
        }
        else
        {
            h[i]={o.second-n,1};
            b[o.second-n].second.second=i;
        }
    }
    int dp[maxn];
    for(int i=(maxn-1);i>=0;i--)
    {
        if(h[i].second==0)
        {
            //cout<<h[i].first<<" h[i].first "<<endl;
            if(b[h[i].first].first==1)
            to1(0,0,maxn,b[h[i].first].second.second+1,maxn,1);
            else
            to2(0,0,maxn,b[h[i].first].second.second+1,maxn,1);
        }
        dp[i]=max(t1[0],t2[0]);
        /*if(i<=10)
        {
            cout<<i<<" i "<<dp[i]<<" dp[i] "<<endl;
        }*/
        to1(0,0,maxn,i,i+1,dp[i]);
        to2(0,0,maxn,i,i+1,dp[i]);
    }
    cout<<dp[0];
    return 0;
}