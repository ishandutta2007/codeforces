#include <bits/stdc++.h>

using namespace std;
#define int long long
vector <vector<int> > a;
vector <vector <int> > b;
vector <bool> use;
vector <bool> used;
vector <int> sub;
vector <char> res;
void dfs(int x)
{
    //cout<<x<<" x "<<endl;
    int v;
    sub[x]=1;
    used[x]=true;
    for(int i=0;i<a[x].size();++i)
    {
        v=a[x][i];
        if(!used[v] && !use[b[x][i]])
        {
            dfs(v);
            sub[x]+=sub[v];
        }
    }
    used[x]=false;
}
int fin(int x,int sz)
{
    //cout<<x<<" "<<sz<<endl;
    int v;
    used[x]=true;
    bool h=(sub[x]>=(sz/2));
    vector <int> v1;
    for(int i=0;i<a[x].size();++i)
    {
        v=a[x][i];
        if(!used[v] && !use[b[x][i]])
        {
            v1.push_back(v);
            h=(h && sub[v]<(sz/2));
        }
    }
    if(h)
    {
        //cout<<" tfrdesw "<<endl;
        used[x]=false;
        return x;
    }
    else
    {
        int u=(-1);
        for(int i=0;i<v1.size();++i)
        {
            u=max(u,fin(v1[i],sz));
        }
        used[x]=false;
        return u;
    }
}
void go(int x,char s)
{
    dfs(x);
    int t=fin(x,sub[x]);
    //cout<<t<<" t "<<endl;
    res[t]=s;
    for(int i=0;i<a[t].size();++i)
    {
        if(!use[b[t][i]])
        {
        use[b[t][i]]=true;
        go(a[t][i],s+1);
        }
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    a.resize(n);
    used.resize(n);
    res.resize(n);
    sub.resize(n);
    use.resize(n);
    b.resize(n);
    for(int i=0;i<n;++i)
    {
        used[i]=false;
        use[i]=false;
    }
    int x,y;
    for(int i=0;i<(n-1);++i)
    {
        cin>>x>>y;
        x--;y--;
        a[x].push_back(y);a[y].push_back(x);
        b[x].push_back(i);b[y].push_back(i);
    }
    go(0,'A');
    for(int i=0;i<n;++i)
    {
        cout<<res[i]<<" ";
    }
    return 0;
}