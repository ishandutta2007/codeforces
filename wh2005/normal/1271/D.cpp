#include<bits/stdc++.h>
using namespace std;
const int N = 5009;
const int M = 3e5+9;
int n,m,k,head[N],tot;
struct pp{int nxt,to;}g[M];
void add(int u,int v){
    g[++tot].nxt=head[u],g[tot].to=v,head[u]=tot;
}
int a[N],b[N],c[N],p[N];
struct castle{
    int pos,val;
    bool operator<(const castle x) const{
        return val>x.val;
    }
}t[N];
bool cmp(castle x,castle y){return x.val<y.val;}
priority_queue<castle> q;

int main(){
    memset(head,-1,sizeof(head));tot=0;
    scanf("%d%d%d",&n,&m,&k);a[n+1]=0,b[n+1]=0;
    for(int i=1;i<=n;i++){
        scanf("%d%d%d",&a[i],&b[i],&c[i]);p[i]=i;
    }
    for(int i=1;i<=m;i++){
        int u,v;scanf("%d%d",&u,&v);p[v]=max(p[v],u);
    }
    for(int i=1;i<=n;i++) t[i].pos=i,t[i].val=c[i];
    sort(t+1,t+n+1,cmp);
    for(int i=1;i<=n;i++) add(p[t[i].pos],t[i].pos);
    int num=k,ans=0;
    for(int i=1;i<=n+1;i++){
        while(num<a[i]&&!q.empty()){
            castle x=q.top();q.pop();
            ans-=c[x.pos];num++;
        }
        if(num<a[i]){
            printf("-1\n");
            return 0;
        }
        if(num>=a[i]){
            num+=b[i];
            for(int j=head[i];j!=-1;j=g[j].nxt){
                int v=g[j].to;num--;
                q.push(castle{v,c[v]});
                ans+=c[v];
            }
        }
    }  
    printf("%d\n",ans);
    return 0;
}