#include<bits/stdc++.h>
using namespace std;
const int N = 2e3+9;
const int M = 1e6+9;
const int inf = 1e9+7;
#define fa(x) t[x].fa
#define ls(x) t[x].ch[0]
#define rs(x) t[x].ch[1]
#define lc(x) (x<<1)
#define rc(x) (x<<1|1)
#define ll long long
int n,m,a[N][N];
struct pp{int x,y;}p[M];
int l,r,st[M];
struct LCT{int fa,ch[2],tag;}t[M];
bool isroot(int x){return !(ls(fa(x))==x||rs(fa(x))==x);}
void update(int x){if(!x) return ;t[x].tag^=1;swap(ls(x),rs(x));return ;}
void pushdown(int x){if(t[x].tag){update(ls(x));update(rs(x));t[x].tag=0;}return ;}
void rotate(int x){
    int y=fa(x),z=fa(y),k=(rs(y)==x);int w=t[x].ch[!k];
    if(!isroot(y)) t[z].ch[rs(z)==y]=x;t[x].ch[!k]=y,t[y].ch[k]=w;
    fa(w)=y,fa(y)=x,fa(x)=z;return ;
}
void splay(int x){
    int y=x,z=0;st[++z]=x;
    while(!isroot(y)) st[++z]=y=fa(y);
    while(z) pushdown(st[z--]);
    while(!isroot(x)){
        int y=fa(x),z=fa(y);
        if(!isroot(y)) rotate((rs(z)==y)^(rs(y)==x)?x:y);
        rotate(x);
    }
    return ;
}
void access(int x){for(int y=0;x;x=fa(y=x)){splay(x);rs(x)=y;}return ;}
void makeroot(int x){access(x);splay(x);update(x);return ;}
int findroot(int x){access(x);splay(x);while(ls(x)) pushdown(x),x=ls(x);splay(x);return x;}
void link(int x,int y){makeroot(x);fa(y)=x;return ;}
void cut(int x,int y){makeroot(x);access(y);rs(x)=fa(y)=0;return ;}
void split(int x,int y){makeroot(x);access(y);splay(y);return ;}
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
bool Graph_Connected(int u){
    vector<int >vec;int x=p[u].x,y=p[u].y;
    for(int i=0;i<4;i++){
        int nx=x+dx[i],ny=y+dy[i];
        if(nx<1||nx>n||ny<1||ny>m) continue;
        if(a[nx][ny]>=l&&a[nx][ny]<r) vec.push_back(a[nx][ny]);
    }
    for(int i=0;i<(int)vec.size();i++){
        makeroot(vec[i]);
        for(int j=i+1;j<(int)vec.size();j++){
            x=vec[i],y=vec[j];
            if(findroot(y)==x) return 1;
        }
    }
    return 0;
}
struct segment{int mn,num,flag,tag;}g[M<<2];
segment operator+(const segment x,const segment y){
    segment z;z.tag=0,z.flag=0,z.mn=0,z.num=0;
    if(!x.flag){z=y,z.tag=0;return z;}if(!y.flag){z=x,z.tag=0;return z;}
    if(x.mn==y.mn){z.flag=1;z.mn=x.mn,z.num=x.num+y.num;return z;}
    if(x.mn<y.mn) z=x,z.tag=0;else z=y,z.tag=0;return z;
}
void Pushup(int c){g[c]=g[lc(c)]+g[rc(c)];return ;}
void build(int c,int l,int r){
    g[c].mn=1,g[c].num=r-l+1,g[c].flag=1,g[c].tag=0;if(l==r) return ;
    int mid=(l+r)>>1;build(lc(c),l,mid);build(rc(c),mid+1,r);
    Pushup(c);return ;
}
void Update(int c,int d,int l,int r){g[c].mn+=d,g[c].tag+=d;return ;}
void Pushdown(int c,int l,int r){
    int mid=(l+r)>>1;
    if(g[c].tag){
        Update(lc(c),g[c].tag,l,mid);
        Update(rc(c),g[c].tag,mid+1,r);
        g[c].tag=0;
    }
    return ;
}
void modify(int c,int l,int r,int x,int y,int d){
    if(x>y) return ;
    if(x<=l&&r<=y){Update(c,d,l,r);return ;}
    Pushdown(c,l,r);int mid=(l+r)>>1;
    if(x<=mid) modify(lc(c),l,mid,x,y,d);
    if(y>mid) modify(rc(c),mid+1,r,x,y,d);
    Pushup(c);return ;
}
segment query(int c,int l,int r,int x,int y){
    if(x<=l&&r<=y) return g[c];
    Pushdown(c,l,r);int mid=(l+r)>>1;segment ans;ans.flag=0;
    if(x<=mid) ans=ans+query(lc(c),l,mid,x,y);
    if(y>mid) ans=ans+query(rc(c),mid+1,r,x,y);
    Pushup(c);return ans;
}
void del(int u){
    int x=p[u].x,y=p[u].y;
    for(int i=0;i<4;i++){
        int nx=x+dx[i],ny=y+dy[i];
        if(nx<1||nx>n||ny<1||ny>m) continue;
        if(a[nx][ny]>=l&&a[nx][ny]<r){
            cut(u,a[nx][ny]);
        }
    }
    return ;
}
void linked(int u){
    int x=p[u].x,y=p[u].y;
    for(int i=0;i<4;i++){
        int nx=x+dx[i],ny=y+dy[i];
        if(nx<1||nx>n||ny<1||ny>m) continue;
        if(a[nx][ny]>=l&&a[nx][ny]<r){
            modify(1,1,n*m,l,a[nx][ny],-1);
            link(u,a[nx][ny]);
        }
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) scanf("%d",&a[i][j]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) p[a[i][j]].x=i,p[a[i][j]].y=j;    
    ll ans=0;build(1,1,n*m);
    for(r=1,l=1;r<=n*m;r++){
        while(Graph_Connected(r)) del(l++);
        modify(1,1,n*m,l,r,1);
        linked(r);
        segment fd=query(1,1,n*m,l,r);
        ans+=fd.num;
    }
    printf("%lld\n",ans);
    return 0;
}