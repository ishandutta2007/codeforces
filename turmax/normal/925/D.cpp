#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=3e5+5;
vector<int> a[maxn];
bool ok[maxn];
set<pair<int,int> > u;
bool cmp(int x,int y)
{
    return a[x].size()<a[y].size();
}
pair<int,int> f(int x)
{
    sort(a[x].begin(),a[x].end(),cmp);
    for(int i=0;i<a[x].size();++i)
    {
        for(int u:a[a[x][i]]) ok[u]=1;
        for(int j=i+1;j<a[x].size();++j)
        {
            if(!ok[a[x][j]])
                {
                    return {a[x][i],a[x][j]};
                }
        }
        for(int u:a[a[x][i]]) ok[u]=0;
    }
    return {-1,-1};
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m;cin>>n>>m;int pr[2*n+1];for(int i=0;i<=2*n;++i) pr[i]=(-1);
    for(int i=0;i<m;++i) {int x,y;cin>>x>>y;--x;--y;a[x].push_back(y);a[y].push_back(x);u.insert({x,y});u.insert({y,x});}
    queue<int> q;int d[2*n];for(int i=0;i<2*n;++i) {d[i]=1e9;} q.push(0);d[0]=0;
    while(!q.empty())
    {
        int x=q.front();q.pop();
        for(int v:a[x])
        {
            if(d[v]==1e9)
            {
                d[v]=d[x]+1;pr[v]=x;q.push(v);
            }
        }
    }
    int ans1=d[n-1];
    if(ans1<=4)
    {
        vector<int> ans;int cur=n-1;
        while(true)
        {
            ans.push_back(cur);
            if(cur==0) break;
            cur=pr[cur];
        }
        cout<<ans.size()-1<<'\n';
        reverse(ans.begin(),ans.end());
        for(auto h:ans) cout<<h+1<<' ';
        return 0;
    }
    for(int i=1;i<n;++i)
    {
        if(d[i]==2)
        {
            cout<<4<<endl;
            cout<<1<<' '<<pr[i]+1<<' '<<i+1<<' '<<1<<' '<<n;
            return 0;
        }
    }
    if(ans1<=5)
    {
        vector<int> ans;int cur=n-1;
        while(true)
        {
            ans.push_back(cur);
            if(cur==0) break;
            cur=pr[cur];
        }
        cout<<ans.size()-1<<'\n';
        reverse(ans.begin(),ans.end());
        for(auto h:ans) cout<<h+1<<' ';
        return 0;
    }
    vector<int> h=a[0];
    sort(a[0].begin(),a[0].end(),cmp);
    for(int h1:h)
    {
        pair<int,int> o=f(h1);
        if(o.first==(-1)) continue;
        int h2=o.first;int h3=o.second;
        {
            {
                if(h3==0) continue;
                if(!u.count({h2,h3}))
                {
                    cout<<5<<endl;
                    cout<<1<<' '<<h2+1<<' '<<h1+1<<' '<<h3+1<<' '<<h2+1<<' '<<n;
                    return 0;
                }
                else
                {
                    assert(false);
                }
            }
        }
    }
    if(ans1<1e9)
    {
        vector<int> ans;int cur=n-1;
        while(true)
        {
            ans.push_back(cur);
            if(cur==0) break;
            cur=pr[cur];
        }
        cout<<ans.size()-1<<'\n';
        reverse(ans.begin(),ans.end());
        for(auto h:ans) cout<<h+1<<' ';
        return 0;
    }
    cout<<(-1);
    return 0;
}