#include <bits/stdc++.h>

using namespace std;
const int maxn=1e6+5;
vector <pair<int,int> > a[maxn];
vector <pair<int,int> > ch[maxn];
vector <int> z[maxn];
vector <long long> prsum[maxn];
bool used[maxn];
int pr[maxn];
int prw[maxn];
void dfs(int x)
{
    z[x].push_back(0);
    used[x]=true;
    for(auto h:a[x])
    {
        int v=h.first;int w=h.second;
        if(used[v]) continue;
        pr[v]=x;prw[v]=w;
        ch[x].push_back({v,w});
        dfs(v);
        vector <int> cur=z[v];
        for(auto d:cur) z[x].push_back(d+w);
    }
    sort(z[x].begin(),z[x].end());
    prsum[x].resize(z[x].size()+1);
    //cout<<x<<" x "<<z[x].size()<<" size "<<endl;
    prsum[x][0]=0;for(int i=0;i<z[x].size();++i) prsum[x][i+1]=prsum[x][i]+z[x][i];
}
long long go(int x,long long w)
{
    //cout<<x<<" x "<<w<<" w "<<endl;
    if(w<0) return 0;
    long long o=lower_bound(z[x].begin(),z[x].end(),w)-z[x].begin();
    return (w*o-prsum[x][o]);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    pr[0]=(-1);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=(n-1);++i)
    {
        int l;cin>>l;int x=(i-1)/2;int y=i;a[x].push_back({y,l});a[y].push_back({x,l});
    }
    dfs(0);
    while(q--)
    {
        int x,w;
        cin>>x>>w;
        x--;
        long long ans=w;
        for(auto h:ch[x]) {ans+=go(h.first,w-h.second);}
        int cur=w;
        int lst=x;
        while(x!=0)
        {
            cur-=prw[x];
            ans+=max(0,cur);
            //cout<<cur<<" cur "<<endl;
            lst=x;
            x=pr[x];
            for(auto h:ch[x]) if(h.first!=lst) ans+=go(h.first,cur-h.second);
        }
        cout<<ans<<endl;
    }
    return 0;
}