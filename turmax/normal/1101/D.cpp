#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=2e5+5;
vector <int> rasl(int n)
{
    vector <int> v;
    if(n==1) return v;
    for(int i=2;i*i<=n;++i)
    {
        if(n%i==0)
        {
            v=rasl(n/i);
            v.push_back(i);
            return v;
        }
    }
    v.push_back(n);
    return v;
}
vector <int> a[maxn];
int g[maxn];
vector <int> h[maxn];
bool used[maxn];
bool z[maxn];
int answ[maxn];
int ans=0;
void dfs(int x)
{
    if(used[x])
    {
        return;
    }
    used[x]=true;
    answ[x]=1;
    pair <int,int> ma=make_pair(-1,-1);
    for(int i=0;i<a[x].size();++i)
    {
        int v=a[x][i];
        if(z[v] && !used[v])
        {
            dfs(v);
            answ[x]=max(answ[x],answ[v]+1);
            ma=max(ma,{ma.first,answ[v]});
            if(ma.second>ma.first)
            {
                swap(ma.first,ma.second);
            }
        }
    }
    ans=max(ans,answ[x]);
    ans=max(ans,ma.first+ma.second+1);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;++i) cin>>g[i];
    for(int i=0;i<n;++i)
    {
        vector <int> v=rasl(g[i]);
        sort(v.begin(),v.end());
        for(int j=0;j<v.size();++j)
        {
            int x=v[j];
            if(j==0 || x!=v[j-1])
            {
                h[x].push_back(i);
            }
        }
    }
    for(int i=0;i<(n-1);++i)
    {
        int x,y;
        cin>>x>>y;
        x--;y--;
        a[x].push_back(y);a[y].push_back(x);
    }
    for(int i=0;i<maxn;++i)
    {
        if(h[i].size()==0) continue;
        for(int j=0;j<h[i].size();++j)
        {
            z[h[i][j]]=true;
        }
        for(int j=0;j<h[i].size();++j)
        {
            dfs(h[i][j]);
        }
        for(int j=0;j<h[i].size();++j)
        {
            used[h[i][j]]=false;
            z[h[i][j]]=false;
        }
    }
    cout<<ans;
    return 0;
}