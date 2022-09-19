#pragma GCC optimize("O3","unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>

using namespace std;
const int maxn=1e6+5;
int n;
bool used[maxn];
vector <int> v[maxn];
vector <int> g[maxn];
int ans[maxn];int pr[maxn];
int t[4*maxn];
void init()
{
    used[0]=true;used[1]=true;
    for(int i=2;i<maxn;++i)
    {
        if(used[i]) continue;
        v[i]={i};
        for(int j=2*i;j<maxn;j+=i)
        {
            used[j]=true;
            v[j].push_back(i);
        }
    }
}
vector <int> slv(vector <pair<int,int> > z)
{
    vector <int> f;
    for(auto h:z) f.push_back(h.second);
    pr[0]=0;
    for(int i=0;i<f.size();++i) pr[i+1]=pr[i]+f[i];
    stack <pair<int,int> > o;
    for(int i=0;i<=f.size();++i) ans[i]=1e9;
    for(int i=0;i<=f.size();++i)
    {
        while(true)
        {
        if(o.empty())
        {
            o.push({pr[i],i});
            break;
        }
        pair <int,int> z=o.top();
        if(z.first<=pr[i])
        {
            o.push({pr[i],i});
            break;
        }
        else
        {
            ans[z.second]=i;
            o.pop();
        }
        }
    }
    vector <int> res;
    for(int i=0;i<f.size();++i)
    {
        if(ans[i]==1e9) res.push_back(n);
        else res.push_back(z[ans[i]-1].first);
    }
    return res;
}
void to(int node,int tl,int tr,int l,int r,int val)
{
    if(tl>=l && tr<=r)
    {
        t[node]=min(t[node],val);
        return;
    }
    if(tl>=r || tr<=l)
    {
        return;
    }
    int tm=(tl+tr)/2;
    to(2*node+1,tl,tm,l,r,val);to(2*node+2,tm,tr,l,r,val);
}
int get(int node,int tl,int tr,int pos)
{
    if(tl>pos || tr<=pos) return 1e9;
    int ans=t[node];
    if((tr-tl)==1) return ans;
    int tm=(tl+tr)/2;
    ans=min(ans,get(2*node+1,tl,tm,pos));ans=min(ans,get(2*node+2,tm,tr,pos));
    return ans;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    for(int i=0;i<4*maxn;++i) t[i]=1e9;
    init();
    cin>>n;
    int a[n];
    for(int i=0;i<n;++i) cin>>a[i];
    string s;
    cin>>s;
    for(int i=0;i<n;++i) for(auto h:v[a[i]]) g[h].push_back(i);
    vector <pair<pair<int,int>,int> > o;
    for(int i=2;i<maxn;++i)
    {
        if(g[i].empty()) continue;
        vector <pair<int,int> > z;
        int o1=0;
        for(auto j:g[i])
        {
            o1=0;
            int x=a[j];
            assert(x%i==0);
            while(x%i==0)
            {
                ++o1;
                x/=i;
            }
            if(s[j]=='*')
            z.push_back({j,o1});
            else
            z.push_back({j,-o1});
        }
        /*for(auto h:z)
        {
            cout<<h.first<<' '<<h.second<<endl;
        }
        cout<<endl;*/
        vector <int> t=slv(z);
        for(int i=0;i<z.size();++i)
        {
            if(i==0) o.push_back({{0,z[0].first+1},t[i]});
            else o.push_back({{z[i-1].first+1,z[i].first+1},t[i]});
        }
        //cout<<i<<" i "<<endl;
        //for(auto l:o) cout<<l.first.first<<' '<<l.first.second<<' '<<l.second<<endl;
    }
    //cout<<" ytg fr"<<endl;
    to(0,0,n,0,n,n);
    //for(auto l:o) cout<<l.first.first<<' '<<l.first.second<<' '<<l.second<<endl;
    for(auto l:o) to(0,0,n,l.first.first,l.first.second,l.second);
    long long res=0;
    for(int i=0;i<n;++i)
    {
        int val=get(0,0,n,i);
        //cout<<val<<" val "<<endl;
        res+=max(0,val-i);
    }
    cout<<res<<endl;
    return 0;
}