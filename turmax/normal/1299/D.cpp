#include <bits/stdc++.h>

using namespace std;
const int p=1e9+7;
const int maxn=1e5+5;
vector <pair<int,int> > a[maxn];
int po[60];
bool used[maxn];
int val[maxn];
int corn[maxn];
vector <int> cyc;
vector <int> cyc1;
vector <int> d1;
vector <pair<int,pair<bool,int> > > d2;
vector <int> go1(vector <int> v,int m)
{
    vector <int> ans;
    if(m==0 || v.empty())
    {
        return ans;
    }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    if(v[0]<(1<<(m-1)))
    {
        return go1(v,m-1);
    }
    vector <int> z;
    for(int i=1;i<v.size();++i)
    {
        z.push_back(min(v[i],v[i]^v[0]));
    }
    ans=go1(z,m-1);
    ans.push_back(v[0]);
    return ans;
}
pair<bool,int> go(vector <int> v)
{
    int sz=v.size();
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    vector <int> u=go1(v,5);
    if(u.size()!=sz)
    {
        return {false,-1};
    }
    int ans=0;
    for(int mask=0;mask<(1<<u.size());++mask)
    {
        int l=0;
        for(int i=0;i<u.size();++i)
        {
            if(mask & (1<<i))
            {
                l^=u[i];
            }
        }
        ans+=(1<<l);
    }
    return {true,ans};
}
int go3(vector <int> v)
{
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    vector <int> u=go1(v,5);
    int ans=0;
    for(int mask=0;mask<(1<<u.size());++mask)
    {
        int l=0;
        for(int i=0;i<u.size();++i)
        {
            if(mask & (1<<i))
            {
                l^=u[i];
            }
        }
        ans+=(1<<l);
    }
    return ans;
}
int go2(int mask1,int mask2)
{
    if(!mask1)
    {
        return mask2;
    }
    if(!mask2)
    {
        return mask1;
    }
    if((mask1+1)==po[32])
    {
        return mask1;
    }
    if((mask2+1)==po[32])
    {
        return mask2;
    }
    int mask=(mask1 | mask2);
    for(int i=0;i<32;++i)
    {
        if(mask1 & (1<<i))
        {
        for(int j=0;j<32;++j)
        {
            if(mask2 & (1<<j))
            {
                mask |= (1<<(i^j));
            }
        }
        }
    }
    return mask;
}
void dfs(int x)
{
    used[x]=true;
    for(auto h:a[x])
    {
        int v=h.first;
        int w=h.second;
        if(!used[v])
        {
            corn[v]=corn[x]+1;
            val[v]=val[x]^w;
            dfs(v);
            if(x==0)
            {
                if(cyc1.empty())
                {
                    pair<bool,int> mask=go(cyc);
                    if(mask.first)
                    {
                    d1.push_back(mask.second-1);
                    }
                }
                else
                {
                     pair<bool,int> mask1=go(cyc);
                     if(mask1.first)
                     {
                          for(auto h:cyc1)
                          {
                          cyc.push_back(h);
                          }
                          pair<bool,int> mask2=go(cyc);
                          mask2.second--;
                          d2.push_back({mask1.second-1,mask2});
                     }
                }
                cyc1.clear();
                cyc.clear();
            }
        }
        else if(corn[v]<(corn[x]-1))
        {
            if(v!=0)
            cyc.push_back(val[x]^val[v]^w);
            else
            cyc1.push_back(val[x]^val[v]^w);
        }
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int u1=1;
    for(int i=0;i<60;++i)
    {
        po[i]=u1;
        u1*=2;
    }
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;++i)
    {
        int x,y,w;
        cin>>x>>y>>w;
        x--;y--;
        a[x].push_back({y,w});a[y].push_back({x,w});
    }
    val[0]=0;
    corn[0]=0;
    dfs(0);
    /*cout<<" d1 "<<endl;
    cout<<d1.size()<<endl;
    for(auto h:d1) cout<<h<<' ';
    cout<<endl;*/
    unordered_map <int,long long> u;
    vector <int> keys;
    u[0]=1;
    keys.push_back(0);
    for(auto h:d1)
    {
        vector <pair<int,int> > g;
        for(auto z:keys)
        {
            if(z & h) continue;
            int msk=go2(h,z);
            g.push_back({msk,u[z]});
        }
        for(auto l:g)
        {
            if(!u.count(l.first))
            {
                keys.push_back(l.first);
                u[l.first]=0;
            }
            u[l.first]+=l.second;
            u[l.first]%=p;
        }
    }
    for(auto l:d2)
    {
        vector <pair<int,int> > g;
        int h=l.first;
        for(auto z:keys)
        {
            if(z & h) continue;
            int msk=go2(h,z);
            g.push_back({msk,2*u[z]});
        }
        h=l.second.second;
        if(l.second.first)
        {
        for(auto z:keys)
        {
            if(z & h) continue;
            int msk=go2(h,z);
            g.push_back({msk,u[z]});
        }
        }
        for(auto l:g)
        {
            if(!u.count(l.first))
            {
                keys.push_back(l.first);
                u[l.first]=0;
            }
            u[l.first]+=l.second;
            u[l.first]%=p;
        }
    }
    long long sum=0;
    for(auto h:keys)
    {
        sum+=u[h];
        sum%=p;
    }
    cout<<sum;
    return 0;
}