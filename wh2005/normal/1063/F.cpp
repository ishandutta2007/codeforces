#include<bits/stdc++.h>
using namespace std;
const int N = 2e6+9;
int n,th[N],id[N],sz[N];
char s[N];
namespace SAM{
    int cnt,las;
    struct SAM{
        int len,fa,ch[26];
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
                t[np].fa=t[q].fa=nq;
                for(;p&&t[p].ch[c]==q;p=t[p].fa) t[p].ch[c]=nq;
            }
        }
        return ;
    }
    int head[N],tot,f[N][21];
    struct pp{int nxt,to;}g[N<<1];
    void add(int u,int v){g[++tot].nxt=head[u],g[tot].to=v,head[u]=tot;}
    int num;
    void dfs(int u,int fa){
        id[u]=++num,f[u][0]=fa,sz[u]=1;
        for(int i=head[u];i!=-1;i=g[i].nxt){int v=g[i].to;dfs(v,u);sz[u]+=sz[v];}
        return ;
    }
    void tree(){
        memset(head,-1,sizeof(head));tot=0;
        for(int i=2;i<=cnt;i++) add(t[i].fa,i);
        num=0;dfs(1,0);
        for(int j=1;j<=20;j++) for(int i=1;i<=cnt;i++) f[i][j]=f[f[i][j-1]][j-1];
        return ;
    }
    int jump(int u,int len){
        for(int j=20;j>=0;j--) if(t[f[u][j]].len>=len) u=f[u][j];
        return u;
    }
}
namespace SEG{
    #define ls(x) (x<<1)
    #define rs(x) (x<<1|1)
    int n;struct seg{int mx;}t[N<<2];
    void pushup(int c){t[c].mx=max(t[ls(c)].mx,t[rs(c)].mx);return ;}
    void build(int c,int l,int r){
        if(l==r){t[c].mx=0;return ;}
        int mid=(l+r)>>1;build(ls(c),l,mid);build(rs(c),mid+1,r);pushup(c);return ;
    }
    void modify(int c,int l,int r,int x,int y){
        if(l==r){t[c].mx=max(t[c].mx,y);return ;}
        int mid=(l+r)>>1;if(x<=mid) modify(ls(c),l,mid,x,y);if(x>mid) modify(rs(c),mid+1,r,x,y);pushup(c);return ;
    }
    int query(int c,int l,int r,int x,int y){
        if(x<=l&&r<=y){return t[c].mx;}int mid=(l+r)>>1,ans=0;
        if(x<=mid) ans=max(ans,query(ls(c),l,mid,x,y));if(y>mid) ans=max(ans,query(rs(c),mid+1,r,x,y));pushup(c);return ans;
    }
    #undef ls
    #undef rs
}

int f[N];
int check(int u,int x){
    int p=SAM::jump(th[u-1],x-1),fi=0;
    fi=max(fi,SEG::query(1,1,SEG::n,id[p],id[p]+sz[p]-1));
    p=SAM::jump(th[u],x-1);
    fi=max(fi,SEG::query(1,1,SEG::n,id[p],id[p]+sz[p]-1));
    return (fi>=(x-1));
}

int main(){
    SAM::begin();
    scanf("%d%s",&n,s+1);
    reverse(s+1,s+n+1);
    for(int i=1;i<=n;i++){SAM::insert(s[i]-'a');th[i]=SAM::las;}
    SAM::tree();SEG::n=SAM::cnt;SEG::build(1,1,SEG::n);
    f[1]=1;
    for(int i=2;i<=n;i++){
        f[i]=f[i-1]+1;
        while(f[i]>1&&!check(i,f[i])){
            f[i]--;
            SEG::modify(1,1,SEG::n,id[th[i-f[i]]],f[i-f[i]]);
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++) ans=max(ans,f[i]);
    printf("%d\n",ans);
    return 0;
}
/*
abcdbcc
ccbcba
c,cb,cba
1
dp

f[i]i[1...x]x

f[i-1]>=f[i]-1
(f[i]if[i-1])

f[i]<=f[i-1]+1

f[i]checkcheckO(n)
i
checkcheck(x)check(x-1)


O(n)O(n)

check
check
i1,2,...,x



 query(i,f[i]) 
 [i-f[i]+1,i]
s[i-f[i]+1:i-1],s[i-f[i]+2:i]endpos[1,i-f[i]]
SAM
endpos->pf[p]>=f[i]-1
endposdfnendpos<=i-f[i]

iid[tag[i]]

i-f[i]

i-f[i]i
if[i]<=f[i-1]+1
-> f[i]-1<=f[i-1]
-> i-1-(f[i]-1)>=i-1-f[i-1]
 i-f[i]>=i-1-f[i-1]
f


*/