#include <bits/stdc++.h>

using namespace std;
#define int long long
const int p=998244353;
const int maxn=2e3+3;
vector <pair<int,pair<int,int> > > a;
vector <pair<int,int> > b[maxn];
bool used[maxn];
int color[maxn];
bool z;
void dfs(int x,int c)
{
    used[x]=true;
    color[x]=c;
    for(auto v:b[x])
    {
        if(!used[v.first])
        {
            dfs(v.first,c^v.second);
        }
        else
        {
            if(color[v.first]!=(c^v.second))
            {
                z=false;
            }
        }
    }
}
int slv(int sz)
{
    for(int i=0;i<=sz;++i) b[i].clear();
    z=true;
    for(auto h:a)
    {
        b[h.second.first].push_back({h.second.second,h.first});
        b[h.second.second].push_back({h.second.first,h.first});
    }
    for(int i=0;i<maxn;++i) used[i]=false;
    int cnt=1;
    for(int i=0;i<=sz;++i)
    {
        if(!used[i])
        {
            cnt*=2;
            cnt%=p;
            dfs(i,0);
        }
    }
    if(z)
    return cnt;
    else
    return 0;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    string s;
    cin>>s;
    int n=s.size();
    int ans=0;
    for(int i=1;i<n;++i)
    {
         a.clear();
         a.push_back({1,{0,n+1}});
         for(int j=1;j<=n;++j)
         {
             a.push_back({0,{j,n-j+1}});
         }
         for(int j=1;j<=(n-i);++j)
         {
             a.push_back({0,{n+j,2*n-i-j+1}});
         }
         for(int j=1;j<=i;++j)
         {
             if(s[j-1]!='?')
             a.push_back({s[j-1]-'0',{0,j}});
         }
         for(int j=(i+1);j<=n;++j)
         {
             if(s[j-1]!='?')
             a.push_back({s[j-1]-'0',{j,n+j-i}});
         }
         int sz=(2*n-i);
         if(i!=0)
         ans+=(slv(sz)*(p+1)/2);
         else
         ans+=(slv(sz)*(3*p+1)/4);
         ans%=p;
    }
    cout<<ans;
    return 0;
}