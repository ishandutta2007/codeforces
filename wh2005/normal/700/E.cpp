#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+9;
int n,dp[N],tl[N];
char s[N];

int rt[N];
namespace SEG{
    #define ls(x) t[x].ch[0]
    #define rs(x) t[x].ch[1]
    int cnt;
    struct seg{int ch[2],sz,mx;}t[N*32];
    void begin(){cnt=0;return ;}
    int New(){
        ++cnt;ls(cnt)=rs(cnt)=t[cnt].sz=t[cnt].mx=0;return cnt;
    }
    void pushup(int c){
        t[c].sz=t[ls(c)].sz+t[rs(c)].sz,t[c].mx=max(t[ls(c)].mx,t[rs(c)].mx);return ;
    }
    void modify(int &c,int l,int r,int x){
        if(!c) c=New();if(l==r){t[c].sz=1,t[c].mx=x;return ;}
        int mid=(l+r)>>1;if(x<=mid) modify(ls(c),l,mid,x);if(x>mid) modify(rs(c),mid+1,r,x);pushup(c);return ;
    }
    int query(int c,int l,int r,int x,int y){
        if(!c) return 0;if(x<=l&&r<=y) return t[c].mx;int mid=(l+r)>>1,ans=0;
        if(x<=mid) ans=max(ans,query(ls(c),l,mid,x,y));if(y>mid) ans=max(ans,query(rs(c),mid+1,r,x,y));return ans;
    }
    int merge(int x,int y,int l,int r){
        if(!x||!y) return x+y;if(l==r) return x;int z=New(),mid=(l+r)>>1;
        ls(z)=merge(ls(x),ls(y),l,mid);rs(z)=merge(rs(x),rs(y),mid+1,r);pushup(z);return z;
    }
}


namespace SAM{
    int cnt,las;
    struct SAM{
        int ch[26],len,fa;
        SAM(){memset(ch,0,sizeof(ch));len=fa=0;}
    }t[N];
    void begin(){cnt=las=1;return ;}
    void insert(int c){
        int p=las,np=las=++cnt;t[np].len=t[p].len+1;
        for(;p&&!t[p].ch[c];p=t[p].fa) t[p].ch[c]=np;
        if(!p) t[np].fa=1;
        else{
            int q=t[p].ch[c];
            if(t[q].len==t[p].len+1) t[np].fa=q;
            else{
                int nq=++cnt;t[nq]=t[q];
                t[nq].len=t[p].len+1;
                t[q].fa=t[np].fa=nq;
                for(;p&&t[p].ch[c]==q;p=t[p].fa) t[p].ch[c]=nq;
            }
        }
        return ;
    }
    int head[N],tot;
    struct pp{int nxt,to;}g[N<<1];
    void add(int u,int v){g[++tot].nxt=head[u],g[tot].to=v,head[u]=tot;}
    int f[N][21];
    void dfs(int u,int fa){
        f[u][0]=fa;
        for(int i=head[u];i!=-1;i=g[i].nxt){int v=g[i].to;dfs(v,u);}
        return ;
    }
    void dfs2(int u){
        for(int i=head[u];i!=-1;i=g[i].nxt){int v=g[i].to;dfs2(v);rt[u]=SEG::merge(rt[u],rt[v],1,n);}
        return ;
    }
    void mkt(){
        memset(head,-1,sizeof(head));tot=0;
        for(int i=2;i<=cnt;i++) add(t[i].fa,i);
        dfs(1,0);
        for(int j=1;j<=20;j++) for(int i=1;i<=cnt;i++) f[i][j]=f[f[i][j-1]][j-1];
        dfs2(1);
        return ;
    }
    int jump(int u){
        int ed2=SEG::t[rt[u]].mx;
        int l2=ed2-t[u].len+1;
        for(int i=20;i>=0;i--)
            if(f[u][i]){
                int ed1=SEG::query(rt[f[u][i]],1,n,1,ed2-1);
                int l1=ed1-t[f[u][i]].len+1;
                if(l1<l2) u=f[u][i];
            }
        return u;
    }
    void dfs3(int u){
        dp[u]=1;
        for(int i=head[u];i!=-1;i=g[i].nxt){
            int v=g[i].to;dfs3(v);dp[u]=max(dp[u],dp[v]);
        }
        int p=f[jump(u)][0];
        if(p) dp[p]=max(dp[p],dp[u]+1);
    }
    void run(){dfs3(1);return ;}
}


int main(){
    SAM::begin();SEG::begin();
    scanf("%d%s",&n,s+1);
    for(int i=1;i<=n;i++){
        SAM::insert(s[i]-'a');
        tl[i]=SAM::las;dp[tl[i]]=1;
    }
    for(int i=1;i<=n;i++) SEG::modify(rt[tl[i]],1,n,i);
    SAM::mkt();
    SAM::run();
    printf("%d\n",dp[1]-1);
    return 0;
}
/*
n\log^2 n 
*/