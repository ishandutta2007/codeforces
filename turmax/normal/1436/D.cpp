#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=2e5+5;
vector <int> ch[maxn];
int b[maxn];
bool used[maxn];
int sub[maxn];
int l[maxn];
int ans;
void dfs(int x)
{
    used[x]=true;
    sub[x]=b[x];
    if(ch[x].empty())
    {
        l[x]=1;
    }
    for(auto v:ch[x])
    {
        dfs(v);
        sub[x]+=sub[v];
        l[x]+=l[v];
    }
    ans=max(ans,(sub[x]+l[x]-1)/l[x]);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<n;++i)
    {
        int x;
        cin>>x;
        x--;
        ch[x].push_back(i);
    }
    for(int i=0;i<n;++i) cin>>b[i];
    dfs(0);
    cout<<ans;
    return 0;
}