#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=2e5+5;
int t[4*maxn];
void to(int node,int tl,int tr,int pos,int val)
{
    if(tr<=pos || tl>pos)
    {
        return;
    }
    if((tr-tl)==1)
    {
        t[node]=val;
        return;
    }
    int tm=(tl+tr)/2;
    to(2*node+1,tl,tm,pos,val);to(2*node+2,tm,tr,pos,val);
    t[node]=t[2*node+1]+t[2*node+2];
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
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    string s1;
    cin>>s1;
    string s2=s1;
    reverse(s2.begin(),s2.end());
    int ans=0;
    vector <int> v1[26];
    for(int i=0;i<n;++i)
    {
        v1[s1[i]-'a'].push_back(i);
    }
    for(int i=(n-1);i>=0;i--)
    {
        int x=s2[i]-'a';
        int pos=v1[x].back();
        v1[x].pop_back();
        int r=get(0,0,maxn,0,pos);
        to(0,0,maxn,pos,1);
        ans+=(i-(pos-r));
    }
    cout<<ans;
    return 0;
}