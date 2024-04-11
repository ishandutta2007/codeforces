#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=2e5+5;
map <pair<int,int>,int> u;
set <int> d;
vector <int> a[maxn];
vector <int> b[maxn];
bool ok[maxn];
int sub[maxn];
bool used[maxn];
int pr[maxn];
vector <int> g;
void dfs(int x)
{
    g.push_back(x);
    sub[x]=1;
    used[x]=true;
    for(int i=0;i<a[x].size();++i)
    {
        int v=a[x][i];
        if(ok[b[x][i]] && !used[v])
        {
            pr[v]=x;
            dfs(v);
            sub[x]+=sub[v];
        }
    }
    used[x]=false;
}
void go(int x,int n)
{
    if(!d.count(n))
    {
        cout<<"NO";
        exit(0);
    }
    if(n==1) return;
    dfs(x);
    assert(g.size()==n);
    for(auto h:g)
    {
        if(h!=x && d.count(sub[h]) && d.count(n-sub[h]))
        {
            ok[u[{h,pr[h]}]]=false;
            g.clear();
            int val=sub[h];int v=pr[h];
            go(h,val);
            go(v,n-val);
            return;
        }
    }
    cout<<"NO";
    exit(0);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int x=0,y=1;d.insert(x);d.insert(y);while(x<=2e5) {x=x+y;swap(x,y);d.insert(x);}
    int n;
    cin>>n;
    for(int i=0;i<n-1;++i) ok[i]=true;
    for(int i=0;i<n-1;++i) {int x,y;cin>>x>>y;--x;--y;u[{x,y}]=i;u[{y,x}]=i;b[x].push_back(i);b[y].push_back(i);a[x].push_back(y);a[y].push_back(x);}
    go(0,n);
    cout<<"YES";
    return 0;
}