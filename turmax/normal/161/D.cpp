#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=50000;
vector <int> a[maxn];
vector <int> b[maxn];
bool use[maxn];
int k;
int sub[maxn];
bool used[maxn];
int corn[maxn];
vector <int> v;
int ans=0;
void dfs(int x)
{
    used[x]=true;
    sub[x]=1;
    for(int i=0;i<a[x].size();++i)
    {
        int v=a[x][i];
        if(!used[v] && !use[b[x][i]])
        {
            corn[v]=corn[x]+1;
            dfs(v);
            sub[x]+=sub[v];
        }
    }
    used[x]=false;
    v.push_back(corn[x]);
}
int fin(int x,int sz)
{
    int ans=(-1);
    used[x]=true;
    bool h=(sub[x]>=(sz/2));
    for(int i=0;i<a[x].size();++i)
    {
        int v=a[x][i];
        if(!used[v] && !use[b[x][i]])
        {
            ans=max(ans,fin(v,sz));
            h=(h && sub[v]<(sz/2));
        }
    }
    used[x]=false;
    if(h)
    {
        return x;
    }
    else
    {
        return ans;
    }
}
int cou(vector <int> &v,int x)
{
    return upper_bound(v.begin(),v.end(),x)-lower_bound(v.begin(),v.end(),x);
}
void go(int x)
{
    //cout<<x<<" x "<<endl;
    dfs(x);
    int t=fin(x,sub[x]);
    //cout<<t<<" t "<<endl;
    used[t]=true;
    vector <vector <int> > h;
    vector <int> z1;
    for(int i=0;i<b[t].size();++i)
    {
        v.clear();
        if(!use[b[t][i]])
        {
        use[b[t][i]]=true;
        corn[a[t][i]]=1;
        dfs(a[t][i]);
        z1.push_back(a[t][i]);
        h.push_back(v);
        //cout<<a[t][i]<<" "<<v.size()<<endl;
        }
    }
    used[t]=false;
    vector <int> z;
    for(int i=0;i<h.size();++i)
    {
        sort(h[i].begin(),h[i].end());
        for(int j=0;j<h[i].size();++j)
        {
            z.push_back(h[i][j]);
        }
    }
    /*for(int i=0;i<z.size();++i)
    {
        cout<<i<<" z[i] "<<z[i]<<endl;
    }*/
    sort(z.begin(),z.end());
    for(int i=0;i<h.size();++i)
    {
        for(int j=0;j<h[i].size();++j)
        {
            //cout<<i<<" "<<j<<" h[i][j] "<<h[i][j]<<endl;
            if(h[i][j]==k)
            {
                ans+=2;
            }
            ans+=(cou(z,k-h[i][j])-cou(h[i],k-h[i][j]));
        }
    }
    //cout<<ans<<" ans "<<endl;
    for(int i=0;i<z1.size();++i)
    {
        go(z1[i]);
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n>>k;
    for(int i=0;i<(n-1);++i)
    {
        int x,y;
        cin>>x>>y;
        x--;y--;
        a[x].push_back(y);a[y].push_back(x);
        b[x].push_back(i);b[y].push_back(i);
    }
    go(0);
    cout<<ans/2;
    return 0;
}