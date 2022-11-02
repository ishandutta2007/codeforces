#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
#define si set<int >::iterator
const int N = 1e6+9;

namespace FHQ{
    #define ls(x) t[x].ch[0]
    #define rs(x) t[x].ch[1]
    int cnt,rt;
    struct FHQ{int ch[2],rnd,val,sz;}t[N];
    int nw(int v){
        ++cnt;ls(cnt)=rs(cnt)=0,t[cnt].rnd=rand(),t[cnt].sz=1,t[cnt].val=v;
        return cnt;
    }
    void pushup(int c){
        t[c].sz=1+t[ls(c)].sz+t[rs(c)].sz;return ;
    }
    void splitval(int c,int &x,int &y,int k){
        if(!c){x=0,y=0;return ;}
        if(t[c].val<=k) x=c,splitval(rs(c),rs(x),y,k);
        else y=c,splitval(ls(c),x,ls(y),k);
        pushup(c);return ;
    }
    int merge(int x,int y){
        if(!x||!y) return x+y;
        if(t[x].rnd<t[y].rnd){
            rs(x)=merge(rs(x),y);
            pushup(x);
            return x;
        }
        else{
            ls(y)=merge(x,ls(y));
            pushup(y);
            return y;
        }
    }
    int build(int l,int r){
        if(l==r) return nw(l);
        int mid=(l+r)>>1;
        return merge(build(l,mid),build(mid+1,r));
    }
    #undef ls
    #undef rs
}

int n,a[N],b[N];
int q[N],l,r,pre[N],dis[N],t[N];

void dfs(int u,int p){
    if(!u) return ;
    dis[FHQ::t[u].val]=dis[p]+1;
    pre[FHQ::t[u].val]=p;
    q[++r]=FHQ::t[u].val;
    dfs(FHQ::t[u].ch[0],p);
    dfs(FHQ::t[u].ch[1],p);
    return ;
}

int main(){
    srand(time(0));
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) scanf("%d",&b[i]);
    memset(dis,-1,sizeof(dis));
    l=1,r=1,q[1]=n,pre[n]=0,dis[n]=0;
    
    int rt=FHQ::build(0,n-1);
    
    while(l<=r){
        int u=q[l++];
        if(u==0) break;
        int x=u+b[u];
        if(!rt) break;
        if(x-a[x]==0){
            dis[0]=dis[u]+1;
            pre[0]=u;
            break;
        }
        int xx,yy,zz;
        FHQ::splitval(rt,xx,yy,x-a[x]-1);
        FHQ::splitval(yy,yy,zz,x);
        rt=FHQ::merge(xx,zz);
        dfs(yy,u);
    }
    if(dis[0]==-1) puts("-1");
    else{
        printf("%d\n",dis[0]);
        int cnt=0,x=0;
        while(x!=n){
            t[++cnt]=x;x=pre[x];
            if(cnt>n) throw;
        }
        for(int i=cnt;i>=1;i--) printf("%d ",t[i]);
    }
    return 0;
}