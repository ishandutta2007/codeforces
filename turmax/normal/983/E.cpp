#include <bits/stdc++.h>

using namespace std;
const int maxn=2e5+5;
vector <int> ch[maxn];
int u[maxn][20];
int tin[maxn];int tout[maxn];int timer=0;
int t[2*maxn];int corn[maxn];
int z[8*maxn];vector <int> arr[2*maxn];vector <int> h[8*maxn];
void dfs(int x)
{
    for(int i=1;i<20;++i) u[x][i]=u[u[x][i-1]][i-1];
    tin[x]=timer;++timer;for(auto v:ch[x]) {corn[v]=corn[x]+1;u[v][0]=x;dfs(v);} ++timer;tout[x]=timer;
}
bool pred(int x,int y)
{
    return (tin[x]<=tin[y] && tout[x]>=tout[y]);
}
int lca(int x,int y)
{
    if(pred(x,y)) return x;
    if(pred(u[x][0],y)) return u[x][0];
    for(int i=1;i<20;++i)
    {
        if(pred(u[x][i],y)) return lca(u[x][i-1],y);
    }
    assert(false);
}
int sz;
int f(int x,int y)
{
    if(x==(-1)) return y;
    if(y==(-1)) return x;
    if(corn[x]<corn[y]) return x;
    return y;
}
void build(int node,int tl,int tr)
{
    if((tr-tl)==1) {z[node]=t[tl];return;}
    int tm=(tl+tr)/2;build(2*node+1,tl,tm);build(2*node+2,tm,tr);z[node]=f(z[2*node+1],z[2*node+2]);
}
int get(int node,int tl,int tr,int l,int r)
{
    if(tl>=l && tr<=r) return z[node];
    if(tl>=r || tr<=l) return (-1);
    int tm=(tl+tr)/2;
    return f(get(2*node+1,tl,tm,l,r),get(2*node+2,tm,tr,l,r));
}
int getmi(int t1,int t2) {return get(0,0,sz,t1,t2);}
int d[maxn];
int zu[maxn][20];
void buildh(int node,int tl,int tr)
{
    if((tr-tl)==1) {h[node]=arr[tl];sort(h[node].begin(),h[node].end());return;}
    int tm=(tl+tr)/2;buildh(2*node+1,tl,tm);buildh(2*node+2,tm,tr);
    h[node]=h[2*node+1];for(auto l:h[2*node+2]) h[node].push_back(l);
    sort(h[node].begin(),h[node].end());
}
bool fn(int node,int tl,int tr,int l1,int r1,int l2,int r2)
{
    //cout<<endl;
    //for(auto g:h[node]) cout<<g<<" g "<<endl;
    //cout<<endl;
    if(tl>=l1 && tr<=r1) {int val=lower_bound(h[node].begin(),h[node].end(),r2)-lower_bound(h[node].begin(),h[node].end(),l2);/*if(val) {cout<<node<<" node "<<tl<<" tl "<<tr<<" tr "<<endl;}*/ return val;}
    if(tl>=r1 || tr<=l1) return false;
    int tm=(tl+tr)/2;
    return (fn(2*node+1,tl,tm,l1,r1,l2,r2) || fn(2*node+2,tm,tr,l1,r1,l2,r2));
}
bool is(int x,int y)
{
    int t1=tin[x];int t2=tout[x];int t3=tin[y];int t4=tout[y];
    //cout<<t1<<" t1 "<<t2<<" t2 "<<t3<<" t3 "<<t4<<" t4 "<<endl;
    return fn(0,0,sz,t1,t2,t3,t4);
}
pair<int,int> go(int x,int o)
{
    //cout<<x<<" xxxx "<<o<<" oooo "<<endl;
    if(corn[x]<corn[o]) assert(false);
    if(corn[x]==corn[o]) return {0,x};
    if(d[x]==(-1)) return {0,-1};
    if(corn[d[x]]<=corn[o]) return {0,x};
    //cout<<" rteg "<<endl;
    for(int j=1;j<20;++j)
    {
        if(zu[x][j]==(-1) || corn[zu[x][j]]<=corn[o]) {pair <int,int> ans=go(zu[x][j-1],o);ans.first+=(1<<(j-1));return ans;}
    }
    return {0,-1};
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<n;++i) {int x;cin>>x;--x;ch[x].push_back(i);}
    dfs(0);
    for(int i=0;i<2*maxn;++i) t[i]=(-1);
    for(int i=0;i<n;++i) d[i]=(-1);
    int m;cin>>m;for(int i=0;i<m;++i) {int x,y;cin>>x>>y;x--;y--;int o=lca(x,y);t[tin[x]]=f(t[tin[x]],o);t[tin[y]]=f(t[tin[y]],o);arr[tin[x]].push_back(tin[y]);arr[tin[y]].push_back(tin[x]);}
    sz=2*n;build(0,0,sz);buildh(0,0,sz);
    //for(int i=0;i<sz;++i) for(int j:arr[i]) cout<<i<<" i "<<j<<" j "<<endl;
    for(int i=0;i<n;++i) {int t1=tin[i];int t2=tout[i];int z=getmi(t1,t2);d[i]=f(d[i],z);}
    for(int i=0;i<n;++i)
    {
        zu[i][0]=d[i];
        for(int j=1;j<20;++j)
        {
            if(zu[i][j-1]==(-1)) zu[i][j]=(-1);
            else zu[i][j]=zu[zu[i][j-1]][j-1];
        }
    }
    //cout<<d[4]<<" d[4] "<<d[3]<<" d[3] "<<endl;
    int q;
    cin>>q;
    while(q--)
    {
        int x,y;cin>>x>>y;x--;y--;
        int o=lca(x,y);
        //cout<<x<<" x "<<y<<" y "<<o<<" o "<<endl;
        pair <int,int> u1=go(x,o);pair <int,int> u2=go(y,o);
        //cout<<u1.first<<' '<<u1.second<<' '<<u2.first<<' '<<u2.second<<endl;
        if(u1.second==(-1) || u2.second==(-1)) {cout<<(-1)<<endl;continue;}
        if(u1.second==u2.second)
        {
            cout<<u1.first+u2.first<<endl;
            continue;
        }
        else
        {
            //if(is(u1.second,u2.second)) cout<<" is "<<endl;
            if(u1.second==o || u2.second==o || is(u1.second,u2.second)) cout<<u1.first+u2.first+1<<endl;
            else cout<<u1.first+u2.first+2<<endl;
        }
    }
    return 0;
}