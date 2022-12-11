#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10,M=16e5;
int n,q;
char chos1[N],chos2[N];
int ty[N];
struct graph{
    struct edge{
        int to,nxt;
        edge(){to=nxt=0;}
    };
    edge ed[N<<3];
    int cnt,h[N<<1],dfn[N<<1],tot;
    int vis[N<<1];
    graph(){
        cnt=tot=0;
        memset(h,0,sizeof h);
        memset(dfn,0,sizeof dfn);
        memset(vis,0,sizeof vis);
    }
    void add(int st,int et){
        cnt++;
        ed[cnt].to=et;
        ed[cnt].nxt=h[st];
        h[st]=cnt;
    }
    void dfs(int x){
        vis[x]=1;
        for(int i=h[x];i;i=ed[i].nxt){
            int v=ed[i].to;
            if(!vis[v])dfs(v);
        }
        dfn[tot++]=x;
    }
    void solve(int x){
        vis[x]=tot;
        for(int i=h[x];i;i=ed[i].nxt){
            int v=ed[i].to;
            if(!vis[v])solve(v);
        }
    }
}g1,g2;
void calc(){
    int tim=0;
    for(int i=M-1;i>=0;i--)if(!g2.vis[g1.dfn[i]])g2.tot++,g2.solve(g1.dfn[i]);
}
struct edge{
    int to,nxt;
    edge(){to=nxt=0;}
};
edge ed[N<<1];
int cnt,h[N],dfn[N],en[N],tot,fa[N],dep[N];
void add(int st,int et){
    cnt++;
    ed[cnt].to=et;
    ed[cnt].nxt=h[st];
    h[st]=cnt;
}
void add1(int x,int y){
    g1.add(x,y);
    g2.add(y,x);
}
void add2(int x,int y){
    add1(x,y);
    add1(y^1,x^1);
}
void dfs(int x,int f){
    fa[x]=f;
    dfn[x]=tot++;
    for(int i=h[x];i;i=ed[i].nxt){
        int v=ed[i].to;
        if(v==f)continue;
        dfs(v,x);
    }
    en[x]=tot;
}
bool check(int x,int y){
    return dfn[x]<=dfn[y]&&en[y]<=en[x];
}
void upp(int x,int tl,vector<int>&vec){
	while(1){
		vec.push_back(x);
		if(check(x,tl))return;
		x=fa[x];
	}
}
int main(){
    scanf("%d%d",&n,&q);
    for(int i=1;i<n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        x--,y--;
        add(x,y);
        add(y,x);
    }
    dfs(0,0);
    for(int kp=0;kp<q;kp++){
        int x,y;
        char s[N];
        scanf("%d%d%s",&x,&y,s);
        x--,y--;
        vector<int>v1,v2;
        v1.clear();
        v2.clear();
        upp(x,y,v1);
        upp(y,x,v2);
        v2.pop_back();
        reverse(v2.begin(),v2.end());
        for(int kl:v2)v1.push_back(kl);
        int m=v1.size();
        for(int i=0;i<m;i++){
            int now=v1[i];
            char s1=s[i],s2=s[m-i-1];
            if(!ty[now])ty[now]=1,chos1[now]=s1,chos2[now]=s2;
            if(chos1[now]!=s1)add2(kp*2,now*2+1+q*2);
            if(chos2[now]!=s1)add2(kp*2,now*2+q*2);
            if(chos1[now]!=s2)add2(kp*2+1,now*2+1+q*2);
            if(chos2[now]!=s2)add2(kp*2+1,now*2+q*2);
        }
    }
    for(int i=0;i<M;i++)if(!g1.vis[i])g1.dfs(i);
    calc();
    bool pd=0;
    for(int i=0;i<M;i++)if(g2.vis[i]==g2.vis[i^1])pd=1;
    if(pd)return puts("NO"),0;
    puts("YES");
    for(int i=0;i<n;i++){
        if(ty[i])printf("%c",g2.vis[i*2+q*2]<g2.vis[i*2+1+q*2]?chos2[i]:chos1[i]);
        else printf("s");
    }
    return  0;
}