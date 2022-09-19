#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=1e5+5;
const int p=1e9+7;
vector <int> a[maxn];
bool used[maxn];
int sub[maxn];
int n;
vector <int> u;
void dfs(int x)
{
    used[x]=true;
    sub[x]=1;
    for(auto v:a[x])
    {
        if(!used[v]){
        dfs(v);
        sub[x]+=sub[v];
        }
    }
    if(sub[x]!=n)
    u.push_back(sub[x]*(n-sub[x]));
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
    cin>>n;
    u.clear();
    for(int i=0;i<n;++i) {used[i]=false;a[i].clear();}
    for(int i=0;i<(n-1);++i)
    {
        int x,y;
        cin>>x>>y;
        x--;y--;
        a[x].push_back(y);a[y].push_back(x);
    }
    dfs(0);
    sort(u.begin(),u.end());
    int m;
    cin>>m;
    vector <int> b(m);
    for(int i=0;i<m;++i) cin>>b[i];
    sort(b.begin(),b.begin()+m);
    if(m<(n-1))
    {
        for(int i=m;i<(n-1);++i)
        {
            b.push_back(1);
        }
        sort(b.begin(),b.end());
    }
    else if(m>(n-1))
    {
        while(b.size()!=(n-1))
        {
            int x=b.back();
            b.pop_back();
            int y=b.back();
            b.pop_back();
            b.push_back((x*y)%p);
        }
    }
    int ans=0;
    for(int i=0;i<(n-1);++i)
    {
        ans+=((u[i]%p)*b[i]);
        ans%=p;
    }
    cout<<ans<<endl;
    }
    return 0;
}