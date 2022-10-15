// #pragma comment(linker, "/STACK:102400000,102400000")
#pragma GCC optimize("O3")
#pragma GCC optimize("O2")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
// #pragma GCC optimize("trapv")
#include<bits/stdc++.h>
// #include <bits/extc++.h>
#define int long long
// #define double long double
// #define i128 long long
// #define double long double
using namespace std;
 
#define rep(i,n) for (int i=0;i<(int)(n);++i)
#define rep1(i,n) for (int i=1;i<=(int)(n);++i)
#define range(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define F first
#define S second
 
typedef long long ll;
typedef unsigned long long ull;
// typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
const int mod=1e9+7;
const double EPS=1e-9;
// const double pi=acos(-1);
const int INF=1e18;
const int N=500007;
mt19937 rng(1231);

int n,m;
vi g[N];
pii pos[N];

bool in(int x,int y){
    if (x<0||x>=n||y<0||y>=m) return 0;
    return 1; 
}

bool is_bad(int x,int y){
    if (g[x][y]==1) return 0;
    rep(j,4) if (in(x+dx[j],y+dy[j])&&g[x][y]>g[x+dx[j]][y+dy[j]]) return 0;
    return 1;
}
int ch(int u,int v){
    auto [ax,ay]=pos[u];
    auto [bx,by]=pos[v];
    int ans=0;
    set<pii> vis;
    rep(_,4){
        if (!in(ax+dx[_],ay+dy[_])) continue;
        if (ax+dx[_]==bx&&ay+dy[_]==by) continue;
        vis.insert({ax+dx[_],ay+dy[_]});
        ans+=is_bad(ax+dx[_],ay+dy[_]); 
        swap(g[ax][ay],g[bx][by]);
        ans-=is_bad(ax+dx[_],ay+dy[_]);
        swap(g[ax][ay],g[bx][by]);
    }
    rep(_,4){
        if (!in(bx+dx[_],by+dy[_])) continue;
        if (vis.find({bx+dx[_],by+dy[_]})!=vis.end()) continue;
        if (bx+dx[_]==ax&&by+dy[_]==ay) continue;
        vis.insert({bx+dx[_],by+dy[_]});
        ans+=is_bad(bx+dx[_],by+dy[_]);
        swap(g[ax][ay],g[bx][by]);
        ans-=is_bad(bx+dx[_],by+dy[_]);
        swap(g[ax][ay],g[bx][by]);
    }
    ans+=is_bad(ax,ay), ans+=is_bad(bx,by);
    swap(g[ax][ay],g[bx][by]);
    ans-=is_bad(ax,ay), ans-=is_bad(bx,by);
    swap(g[ax][ay],g[bx][by]);
    return ans;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout.precision(15);
    cin>>n>>m;
    rep(i,n) g[i].resize(m,0);
    rep(i,n) rep(j,m) cin>>g[i][j], pos[g[i][j]]=make_pair(i,j);
    int bad=0,x=-1,y=-1;
    rep(i,n) rep(j,m){
        if (is_bad(i,j)) {bad++, x=i, y=j;}
    }
    int cnt=0;
    if (bad==0){
        cout<<0;
        return 0;
    }
    set<pii> hii;
    rep(_,4){
        if (!in(x+dx[_],y+dy[_])) continue;
        rep1(i,n*m) if (ch(g[x+dx[_]][y+dy[_]],i)==bad) hii.insert({g[x+dx[_]][y+dy[_]],i}), hii.insert({i,g[x+dx[_]][y+dy[_]]});
    }
    rep1(i,n*m) if (ch(g[x][y],i)==bad) hii.insert({g[x][y],i}), hii.insert({i,g[x][y]});
    if (sz(hii)) cout<<1<<" "<<sz(hii)/2;
    else cout<<2;
    return 0;
}
/*

*/