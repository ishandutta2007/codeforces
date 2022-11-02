#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+9;
map<string ,int >mp;
int n,m,head[N],tot,vis[N],val[N],cnt;string s;
struct pp{int nxt,to;}g[N<<1];
void add(int u,int v){g[++tot].nxt=head[u],g[tot].to=v,head[u]=tot;}
int dep[N],in[N],siz[N],dfn[N],num;
void dfs(int u,int fa){
    siz[u]=1,dep[u]=dep[fa]+1;dfn[++num]=u,in[u]=num;
    for(int i=head[u];i!=-1;i=g[i].nxt){
        int v=g[i].to;dfs(v,u);siz[u]+=siz[v];
    }
}
struct point{int Dep,Dfn,col,pre;}a[N];
bool cmp1(point x,point y){return x.Dep==y.Dep?(x.Dfn<y.Dfn):(x.Dep<y.Dep);}
int lst[N];
struct Ques{int l,r,id,pos;}q[N<<1];
bool chk(int i,int x,int y){
    if(a[i].Dep!=x) return a[i].Dep>x;
    return a[i].Dfn>=y;
}
int find(int x,int y){
    int l=1,r=n,ans=n+1;
    while(l<=r){
        int mid=(l+r)>>1;
        if(chk(mid,x,y)) r=mid-1,ans=mid;
        else l=mid+1;
    }
    return ans;
}
struct treearray{
    int tr[N];
    int lowbit(int x){return x&(-x);}
    void add(int x,int d){x+=1;while(x<=n+1){tr[x]+=d;x+=lowbit(x);}}
    int sum(int x){int ans=0;x+=1;while(x){ans+=tr[x];x-=lowbit(x);}return ans;}
}t;
bool cmp2(Ques x,Ques y){return x.r==y.r?(x.l<y.l):(x.r<y.r);}
int Ans[N];
int main(){
    memset(head,-1,sizeof(head));
    memset(vis,0,sizeof(vis));
    scanf("%d",&n);num=0,cnt=0;
    for(int i=1;i<=n;i++){
        int pa;cin>>s>>pa;if(pa) add(pa,i);else vis[i]=1;
        if(!mp[s]) mp[s]=++cnt;val[i]=mp[s];
    }
    for(int i=1;i<=n;i++) if(vis[i]) dfs(i,0);
    for(int i=1;i<=n;i++){a[i].Dfn=i,a[i].Dep=dep[dfn[i]],a[i].col=val[dfn[i]];}
    sort(a+1,a+n+1,cmp1);
    for(int i=1;i<=n;i++) a[i].pre=lst[a[i].col],lst[a[i].col]=i;
    scanf("%d",&m);int len=0;
    for(int i=1;i<=m;i++){
        int x,k;scanf("%d%d",&x,&k);
        int l=find(dep[x]+k,in[x]),r=find(dep[x]+k,in[x]+siz[x])-1;
        if(l==n+1||r<l) continue;
        q[++len].l=l,q[len].r=r,q[len].id=i,q[len].pos=1;
        q[++len].l=l,q[len].r=l-1;q[len].id=i,q[len].pos=-1;
    }
    memset(Ans,0,sizeof(Ans));
    sort(q+1,q+len+1,cmp2);
    int i=1,j=0;
    for(i=1;i<=n;i++){
        t.add(a[i].pre,1);
        while(q[j+1].r==i&&j<len){
            j++;Ans[q[j].id]+=q[j].pos*t.sum(q[j].l-1);
        }
    }
    for(int i=1;i<=m;i++) printf("%d\n",Ans[i]);
    return 0;
}