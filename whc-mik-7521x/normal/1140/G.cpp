#include<bits/stdc++.h>
using namespace std;
const int N=3e5+10;
long long dis[N],upp[N][2][21][2],f[N][21],dep[N];
struct edge{
    long long w1,w2;
    int to,nxt;
};
edge ed[N<<1];
int cnt,h[N];
void add(int st,int et,long long w1,long long w2){
    cnt++;
    ed[cnt].to=et;
    ed[cnt].w1=w1;
    ed[cnt].w2=w2;
    ed[cnt].nxt=h[st];
    h[st]=cnt;
}
int n,q;
void dfs(int x,int fa){
    dep[x]=dep[fa]+1;
    for(int i=h[x];i;i=ed[i].nxt){
        int v=ed[i].to;
        if(v==fa)continue;
        dfs(v,x);
        dis[x]=min(dis[x],dis[v]+ed[i].w1+ed[i].w2);
    }
}
void solve(int x,int fa){
    vector<int>vec;
    vector<long long>per,suf,wei;
    for(int i=h[x];i;i=ed[i].nxt){
        int v=ed[i].to;
        if(v==fa)continue;
        dis[v]=min(dis[v],dis[x]+ed[i].w1+ed[i].w2);
        vec.push_back(v);
        per.push_back(dis[v]+ed[i].w1+ed[i].w2);
        suf.push_back(dis[v]+ed[i].w1+ed[i].w2);
        wei.push_back(ed[i].w1+ed[i].w2);
    }
    for(int i=1;i<(int)per.size();i++)per[i]=min(per[i],per[i-1]);
    for(int i=(int)suf.size()-2;i>=0;i--)suf[i]=min(suf[i],suf[i+1]);
    for(int i=0;i<(int)vec.size();i++){
        dis[vec[i]]=min(dis[vec[i]],min(i?per[i-1]:(long long)1e18,i==(int)vec.size()-1?(long long)1e18:suf[i+1])+wei[i]);
        solve(vec[i],x);
    }
}
void dfs2(int x,int fa){
    f[x][0]=fa;
    for(int i=h[x];i;i=ed[i].nxt){
        int v=ed[i].to;
        if(v==fa)continue;
        upp[v][0][0][0]=min(ed[i].w1,ed[i].w2+dis[x]+dis[v]);
        upp[v][0][0][1]=min(ed[i].w1+dis[x],ed[i].w2+dis[v]);
        upp[v][1][0][0]=min(ed[i].w2+dis[x],ed[i].w1+dis[v]);
        upp[v][1][0][1]=min(ed[i].w2,ed[i].w1+dis[x]+dis[v]);
        dfs2(v,x);
    }
}
void init(){
    for(int i=1;i<=20;i++){
        for(int o=1;o<=n;o++){
            f[o][i]=f[f[o][i-1]][i-1];
        }
    }
    for(int i=1;i<=20;i++){
        for(int o=1;o<=n;o++){
            upp[o][0][i][0]=min(upp[o][0][i-1][0]+upp[f[o][i-1]][0][i-1][0],upp[o][0][i-1][1]+upp[f[o][i-1]][1][i-1][0]);
            upp[o][0][i][1]=min(upp[o][0][i-1][0]+upp[f[o][i-1]][0][i-1][1],upp[o][0][i-1][1]+upp[f[o][i-1]][1][i-1][1]);
            upp[o][1][i][0]=min(upp[o][1][i-1][0]+upp[f[o][i-1]][0][i-1][0],upp[o][1][i-1][1]+upp[f[o][i-1]][1][i-1][0]);
            upp[o][1][i][1]=min(upp[o][1][i-1][0]+upp[f[o][i-1]][0][i-1][1],upp[o][1][i-1][1]+upp[f[o][i-1]][1][i-1][1]);
        }
    }
}
long long calc(int x,int y){
    int k1=x>>1,k2=y>>1;
    if(dep[k1]<dep[k2])swap(k1,k2),swap(x,y);
    long long disx0=x&1?dis[k1]:0,disx1=x&1?0:dis[k1],disy0=y&1?dis[k2]:0,disy1=y&1?0:dis[k2];
    if(k1==k2)return min(disx0+disy0,disx1+disy1);
    for(int i=20;i>=0;i--){
        if(dep[k1]-(1<<i)>=dep[k2]){
            long long n0=min(disx0+upp[k1][0][i][0],disx1+upp[k1][1][i][0]),n1=min(disx0+upp[k1][0][i][1],disx1+upp[k1][1][i][1]);
            disx0=n0,disx1=n1;
            k1=f[k1][i];
        }
    }
    if(k1==k2)return min(disx0+disy0,disx1+disy1);
    for(int i=20;i>=0;i--){
        if(f[k1][i]!=f[k2][i]){
            long long n0=min(disx0+upp[k1][0][i][0],disx1+upp[k1][1][i][0]),n1=min(disx0+upp[k1][0][i][1],disx1+upp[k1][1][i][1]);
            long long nn0=min(disy0+upp[k2][0][i][0],disy1+upp[k2][1][i][0]),nn1=min(disy0+upp[k2][0][i][1],disy1+upp[k2][1][i][1]);
            disx0=n0,disx1=n1;
            disy0=nn0,disy1=nn1;
            k1=f[k1][i];
            k2=f[k2][i];
        }
    }
    long long n0=min(disx0+upp[k1][0][0][0],disx1+upp[k1][1][0][0]),n1=min(disx0+upp[k1][0][0][1],disx1+upp[k1][1][0][1]);
    long long nn0=min(disy0+upp[k2][0][0][0],disy1+upp[k2][1][0][0]),nn1=min(disy0+upp[k2][0][0][1],disy1+upp[k2][1][0][1]);
    disx0=n0,disx1=n1;
    disy0=nn0,disy1=nn1;
    return min(disx0+disy0,disx1+disy1);
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%lld",&dis[i]);
    for(int i=1;i<n;i++){
        int x,y;
        long long w1,w2;
        scanf("%d%d%lld%lld",&x,&y,&w1,&w2);
        add(x,y,w1,w2);
        add(y,x,w1,w2);
    }
    dfs(1,0);
    solve(1,0);
    dfs2(1,0);
    init();
    scanf("%d",&q);
    while(q--){
        int x,y;
        scanf("%d%d",&x,&y);
        printf("%lld\n",calc(x+1,y+1));
    }
    return  0;
}