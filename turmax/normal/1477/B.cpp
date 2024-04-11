#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=2e5+5;
int sum[4*maxn];
int tag[4*maxn];
bool is[4*maxn];
string curr;
void build(int node,int tl,int tr)
{
    int tm=(tl+tr)/2;
    if((tr-tl)==1)
    {
        sum[node]=(curr[tl]-'0');
        is[node]=false;
        tag[node]=0;
        return;
    }
    build(2*node+1,tl,tm);build(2*node+2,tm,tr);
    sum[node]=sum[2*node+1]+sum[2*node+2];
    is[node]=false;
    tag[node]=0;
    return;
}
void build1(string s)
{
    curr=s;
    build(0,0,s.size());
}
void push(int node,int tl,int tr)
{
    if(!is[node]) return;
    int tm=(tl+tr)/2;
    tag[2*node+1]=tag[node];tag[2*node+2]=tag[node];
    is[2*node+1]=true;is[2*node+2]=true;
    is[node]=false;
    sum[2*node+1]=tag[2*node+1]*(tm-tl);sum[2*node+2]=tag[2*node+2]*(tr-tm);
}
void to(int node,int tl,int tr,int l,int r,int val)
{
    if(tl>=l && tr<=r)
    {
        sum[node]=(tr-tl)*val;
        is[node]=true;
        tag[node]=val;
        return;
    }
    if(tl>=r || tr<=l)
    {
        return;
    }
    push(node,tl,tr);
    int tm=(tl+tr)/2;
    to(2*node+1,tl,tm,l,r,val);to(2*node+2,tm,tr,l,r,val);
    sum[node]=sum[2*node+1]+sum[2*node+2];
}
int get(int node,int tl,int tr,int l,int r)
{
    if(tl>=r || tr<=l) return 0;
    if(tl>=l && tr<=r) return sum[node];
    push(node,tl,tr);
    int tm=(tl+tr)/2;
    return get(2*node+1,tl,tm,l,r)+get(2*node+2,tm,tr,l,r);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,q;
        cin>>n>>q;
        string s,f;
        cin>>s>>f;
        vector <pair <int,int> > v;
        for(int i=0;i<q;++i)
        {
            int x,y;
            cin>>x>>y;
            x--;
            v.push_back({x,y});
        }
        reverse(v.begin(),v.end());
        build1(f);
        bool ok=true;
        for(auto h:v)
        {
            int ans1=get(0,0,s.size(),h.first,h.second);
            if(2*ans1>(h.second-h.first))
            {
                to(0,0,s.size(),h.first,h.second,1);
            }
            else if(2*ans1<(h.second-h.first))
            {
                to(0,0,s.size(),h.first,h.second,0);
            }
            else
            {
                ok=false;
            }
        }
        for(int i=0;i<s.size();++i)
        {
            if(get(0,0,s.size(),i,i+1)!=(s[i]-'0'))
            {
                ok=false;
            }
        }
        if(ok) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}