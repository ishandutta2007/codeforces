#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=1e4+5;
vector<int> g[maxn];pair<int,int> b[maxn];int a[maxn];bool used[maxn];bool s[maxn];
void rev(int id)
{
    swap(b[id].first,b[id].second);a[b[id].first]+=2;a[b[id].second]-=2;
}
bool dfs(int x,bool flag)
{
    if(used[x]) return false;
    used[x]=true;
    if(!s[x]) return true;
    if(a[x]<0 && flag) return true;
    if(a[x]>0 && !flag) return true;
    for(int id:g[x])
    {
        if(flag && b[id].first==x)
        {
            bool ok=dfs(b[id].second,flag);
            if(ok) {rev(id);return true;}
        }
        if(!flag && b[id].second==x)
        {
            bool ok=dfs(b[id].first,flag);
            if(ok) {rev(id);return true;}
        }
    }
    return false;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m;cin>>n>>m;
    for(int i=0;i<n;++i) cin>>s[i];
    for(int i=0;i<n;++i) cin>>a[i];
    for(int i=0;i<m;++i) {int x,y;cin>>x>>y;if(x>y) swap(x,y); --x;--y;b[i]={x,y};++a[x];--a[y];g[x].push_back(i);g[y].push_back(i);}
    for(int i=0;i<n;++i)
    {
        if(a[i]%2 && s[i]) {cout<<"NO";return 0;}
    }
    while(true)
    {
        bool ok1=true;
        for(int i=0;i<n;++i)
        {
            if(!s[i]) continue;
            if(a[i]==0) continue;
            ok1=false;
            fill(used,used+maxn,0);
            if(!dfs(i,a[i]>0)) {cout<<"NO";return 0;}
        }
        if(ok1) break;
    }
    for(int i=0;i<n;++i) if(a[i] && s[i]) {cout<<"NO";return 0;}
    cout<<"YES"<<endl;
    for(int i=0;i<m;++i) cout<<b[i].first+1<<' '<<b[i].second+1<<endl;
    return 0;
}