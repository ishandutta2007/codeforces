#include <bits/stdc++.h>

using namespace std;
#define int long long
int par[31];
bool ok[31];
int get(int x)
{
    if(par[x]==(-1)) return x; int ans=get(par[x]);par[x]=ans;return ans;
}
void merg(int x,int y)
{
    x=get(x);y=get(y);if(x==y) return;
    par[x]=y;
}
bool cmp(pair<int,int> u,pair<int,int> v)
{
    return u.second<v.second;
}
int f(int x)
{
    int ans=0;
    while(x%2==0) {x/=2;++ans;}
    return ans;
}
bool check(vector<int> a)
{
    int n=a.size();
    for(int i=0;i<31;++i) {par[i]=(-1);ok[i]=false;}
    for(int i=0;i<n;++i) {for(int j1=0;j1<30;++j1) if(a[i] & (1<<j1)) ok[j1]=true;}
    for(int i=0;i<n;++i) {for(int j1=0;j1<30;++j1) for(int j2=0;j2<j1;++j2) {if((a[i] & (1<<j1)) && (a[i] & (1<<j2))) merg(j1,j2);}}
    set<int> t;for(int i=0;i<30;++i) {if(ok[i]) t.insert(get(i));}
    return t.size()==1;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t1;cin>>t1;
    while(t1--)
    {
        for(int i=0;i<31;++i) {par[i]=(-1);ok[i]=false;}
        int n;cin>>n;vector<int> a(n);int ans=0;for(int i=0;i<n;++i) {cin>>a[i]; if(a[i]==0) {++ans;a[i]=1;}}
        if(check(a)) {cout<<ans<<endl;for(int i=0;i<n;++i) cout<<a[i]<<' '; cout<<endl; assert(check(a));continue;}
        vector<pair<int,int> > v;for(int i=0;i<n;++i) {v.push_back({i,f(a[i])});}
        sort(v.begin(),v.end(),cmp);reverse(v.begin(),v.end());a[v[0].first]--;++ans;if(check(a)){{cout<<ans<<endl;for(int i=0;i<n;++i) cout<<a[i]<<' '; cout<<endl; assert(check(a));continue;}} a[v[0].first]++;--ans;
        ++ans;a[v[0].first]++;if(check(a)) {cout<<ans<<endl;for(int i=0;i<n;++i) cout<<a[i]<<' '; cout<<endl; assert(check(a));continue;}
        --ans;a[v[0].first]--;
        vector<int> g;for(int i=0;i<n;++i) if((f(a[i]))==v[0].second) g.push_back(i);
        vector<int> g3;vector<int> g4;
        for(int u=0;u<n;++u)
        {
            if(((a[u]+1) & (1<<(v[0].second))) && (!(a[u] & (1<<(v[0].second)))) && a[u]>(1<<(v[0].second)))
            {
                g3.push_back(u);
            }
        }
        if(g.size()==(n-1) && g3.size()==1)
        {
             int u=g3[0];++a[u];++ans;
             {cout<<ans<<endl;for(int i=0;i<n;++i) cout<<a[i]<<' '; assert(check(a));cout<<endl; continue;}
        }
        vector<int> g2;for(int h:g) {if((__builtin_popcount(a[h]))!=1) g2.push_back(h); else g4.push_back(h);}
        bool ok1=false;
        for(int i=0;i<g3.size();++i)
        {
            if(ok1) break;
            for(int j=0;j<g3.size();++j)
            {
                if(ok1) break;
                if(i==j) continue;
                if(__builtin_popcount((a[g3[i]]+1) & a[g3[j]]))
                {
                    int u=g3[i];++a[u];++ans;
                    {cout<<ans<<endl;for(int i=0;i<n;++i) cout<<a[i]<<' '; cout<<endl; ok1=true;assert(check(a));continue;}
                }
            }
        }
        if(ok1) continue;
        for(int i=0;i<g3.size();++i)
        {
            if(ok1) break;
            for(int j=0;j<g4.size();++j)
            {
                if(ok1) break;
                if(g3[i]==g4[j]) continue;
                if(__builtin_popcount((a[g3[i]]+1) & a[g4[j]]))
                {
                    int u=g3[i];++a[u];++ans;
                    {cout<<ans<<endl;for(int i=0;i<n;++i) cout<<a[i]<<' '; cout<<endl; assert(check(a));ok1=true;continue;}
                }
            }
        }
        if(ok1) continue;
        int pos=(-1);bool ok0=false;
        for(int i=0;i<g2.size();++i)
        {
            if(ok0) break;
            for(int j=i+1;j<g2.size();++j)
            {
                if(ok0) break;
                if(__builtin_popcount(a[g2[i]] & a[g2[j]])>=2)
                {
                    ok0=true;
                    pos=g2[i];
                }
            }
        }
        if(ok0)
        {
            {a[pos]--;++ans;{cout<<ans<<endl;for(int i=0;i<n;++i) cout<<a[i]<<' '; cout<<endl; assert(check(a));continue;}}
        }
        else
        {
            ans+=2;a[v[0].first]--;a[v[1].first]++;
            {cout<<ans<<endl;for(int i=0;i<n;++i) cout<<a[i]<<' '; cout<<endl; assert(check(a));continue;}
        }
    }
    return 0;
}