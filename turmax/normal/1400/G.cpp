#include <bits/stdc++.h>

using namespace std;
#define int long long
const int p=998244353;
const int maxn=3e5+5;
vector <pair<int,int> > z[maxn];
vector <pair<int,int> > u;
vector <int> r;
vector <pair<int,int> > g;
vector <int> g1[maxn];
int o;
bool used[maxn];
bool use[maxn];
bool h[maxn];
bool h1[maxn];
int dp[50];
int dp1[60][50];
int parent[maxn];
int fact[maxn];
int invf[maxn];
int po(int a,int b)
{
    if(b==0) return 1;
    if(b==1) return a;
    if(b%2==0)
    {
        int u=po(a,b/2);
        return (u*u)%p;
    }
    else
    {
        int u=po(a,b-1);
        return (a*u)%p;
    }
}
int inv(int x)
{
    return po(x,p-2);
}
int c(int n,int k)
{
    if(k>n) return 0;
    if(k<0) return 0;
    if(n<0) return 0;
    int ans=fact[n];
    ans*=invf[k];
    ans%=p;
    ans*=invf[n-k];
    ans%=p;
    return ans;
}
void dfs(int x)
{
    use[x]=true;
    r.push_back(x);
    for(auto v:g1[x])
    {
        if(!use[v])
        {
            dfs(v);
        }
    }
}
void recalc()
{
   // cout<<" rec "<<endl;
    for(int i=0;i<100;++i) use[i]=false;
    for(int i=0;i<60;++i)
    {
        for(int j=0;j<50;++j)
        {
            dp1[i][j]=0;
        }
    }
    g=u;
    int i=0;
    while(i<g.size())
    {
        if(h[g[i].first] || h[g[i].second])
        {
            g.erase(g.begin()+i);
            i--;
        }
        ++i;
    }
    //cout<<g.size()<<" size "<<endl;
    vector <int> l;
    for(int i=0;i<u.size();++i)
    {
        if(!h[u[i].first]) l.push_back(u[i].first);if(!h[u[i].second]) l.push_back(u[i].second);
    }
    sort(l.begin(),l.end());
    l.erase(unique(l.begin(),l.end()),l.end());
    map <int,int> o1;
    for(int i=0;i<l.size();++i) o1[l[i]]=i;
    for(int i=0;i<100;++i) g1[i].clear();
    for(int i=0;i<g.size();++i)
    {
        g[i].first=o1[g[i].first];g[i].second=o1[g[i].second];
    }
    for(int i=0;i<g.size();++i)
    {
        g1[g[i].first].push_back(g[i].second);g1[g[i].second].push_back(g[i].first);
    }
    for(int i=0;i<l.size();++i)
    {
        use[i]=false;
    }
    vector <vector<int> > d;
    bool u1[60];
    for(int i=0;i<l.size();++i)
    {
        if(!use[i])
        {
            //cout<<i<<" i "<<endl;
            r.clear();
            for(int i=0;i<60;++i) u1[i]=false;
            dfs(i);
            //cout<<r.size()<<" r.size() "<<endl;
            for(int mask=0;mask<(1<<r.size());++mask)
            {
                for(int i=0;i<r.size();++i)
                {
                    u1[r[i]]=(mask & (1<<i));
                }
                bool e=true;
                for(auto t:g)
                {
                    if(u1[t.first] && u1[t.second])
                    {
                        //cout<<" No "<<mask<<endl;
                       // if(mask==10) cout<<t.first<<" t.first "<<t.second<<" t.second "<<endl;
                        e=false;
                        break;
                    }
                }
                if(e)
                {
                   // cout<<mask<<" mask "<<endl;
                    dp1[i][__builtin_popcount(mask)]++;
                }
            }
        }
        else
        {
            dp1[i][0]=1;
        }
    }
    int s[50];
    for(int i=0;i<50;++i) s[i]=0;
    s[0]=1;
    for(int i=0;i<l.size();++i)
    {
        int s1[100];
        for(int j=0;j<100;++j) s1[j]=0;
        for(int j=0;j<50;++j)
        {
            for(int k=0;k<50;++k)
            {
                s1[j+k]+=(s[j]*dp1[i][k]);
                s1[j+k]%=p;
            }
        }
        for(int j=0;j<50;++j) s[j]=s1[j];
    }
    for(int i=0;i<50;++i) {dp[i]=s[i];dp[i]%=p;}
    //for(int i=0;i<10;++i) cout<<i<<" i "<<dp[i]<<" dp[i] "<<endl;
}
void pl(int x)
{
    //cout<<x<<" x "<<endl;
    if(!used[x]) {++o;return;}
    recalc();
}
void mi(int x)
{
    if(!used[x]) {--o;return;}
    recalc();
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    dp[0]=1;
    int u1=1;
    for(int i=0;i<maxn;++i)
    {
    fact[i]=u1;
    invf[i]=inv(fact[i]);
    u1*=(i+1);
    u1%=p;
    }
    int n,m;
    cin>>n>>m;
    pair <int,int> a[n];
    vector <pair<int,pair<int,int> > > v;
    for(int i=0;i<n;++i)
    {
        cin>>a[i].first>>a[i].second;
        v.push_back({a[i].first,{0,i}});
        v.push_back({a[i].second+1,{1,i}});
    }
    sort(v.begin(),v.end());
    for(int i=0;i<m;++i)
    {
        int x,y;
        cin>>x>>y;
        x--;y--;
        used[x]=true;used[y]=true;
        z[x].push_back({y,i});z[y].push_back({x,i});
        u.push_back({x,y});
    }
    for(int i=0;i<n;++i) h[i]=true;
    int curr=0;
    int sum=0;
    for(int i=1;i<=n;++i)
    {
        while(curr<v.size() && v[curr].first==i)
        {
            if(v[curr].second.first==0)
            {
                h[v[curr].second.second]=false;
                pl(v[curr].second.second);
            }
            else
            {
                h[v[curr].second.second]=true;
                mi(v[curr].second.second);
            }
            ++curr;
        }
        int ans=0;
        for(int j=0;j<50;++j)
        {
            dp[j]%=p;
            ans+=c(o,i-j)*dp[j];
            ans%=p;
        }
        //cout<<ans<<" ans "<<endl;
        sum+=ans;
        sum%=p;
    }
    cout<<sum;
    return 0;
}