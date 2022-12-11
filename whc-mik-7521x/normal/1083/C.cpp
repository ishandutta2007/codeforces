#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,p[N],pos[N];
struct edge{
	int nxt,to;
}ed[N<<1];
int cnt,h[N];
void add(int x,int y){
	ed[++cnt]={h[x],y};
	h[x]=cnt;
}
struct dat{
    int val,num;
    bool operator<(const dat b)const{
        return val<b.val;
    }
};
template<typename T>
struct RMQ{
    T st[N<<1][21];
    RMQ(){}
    RMQ(T a[],int len){
        for(int i=1;i<=len;i++)st[i][0]=a[i];
        for(int o=1;o<=20;o++){
            for(int i=1;i+(1<<o)-1<=len;i++){
                st[i][o]=min(st[i][o-1],st[i+(1<<(o-1))][o-1]);
            }
        }
    }
    int query(int l,int r){
        if(l>r)swap(l,r);
        int len=r-l+1,k=30;
        while((1<<k)>len)k--;
        return min(st[l][k],st[r-(1<<k)+1][k]).num;
    }
};
RMQ<dat>ty;
int dfn[N],ct,en[N],id[N],hs[N],siz[N],top[N],dep[N],f[N],fr[N],dp[N<<1],ctt;
dat gen[N<<1];
void dfs1(int x,int fa){
    dp[++ctt]=x;
    fr[x]=ctt;
	id[++ct]=x;
	f[x]=fa;
	dep[x]=dep[fa]+1;
	siz[x]=1;
	dfn[x]=ct;
	for(int i=h[x];i;i=ed[i].nxt){
		int v=ed[i].to;
		if(v==fa)continue;
		dfs1(v,x);
        dp[++ctt]=x;
		if(siz[v]>siz[hs[x]])hs[x]=v;
		siz[x]+=siz[v];
	}
	en[x]=ct;
}
void dfs2(int x,int fa,int tp){
	top[x]=tp;
	if(hs[x])dfs2(hs[x],x,tp);
	for(int i=h[x];i;i=ed[i].nxt){
		int v=ed[i].to;
		if(v==fa||v==hs[x])continue;
		dfs2(v,x,v);
	}
}
int lca(int x,int y){
    return ty.query(fr[x],fr[y]);
	while(top[x]!=top[y])dep[top[x]]>dep[top[y]]?x=f[top[x]]:y=f[top[y]];
	return dep[x]>dep[y]?y:x;
}
int dis(int x,int y){
    return dep[x]+dep[y]-2*dep[lca(x,y)];
}
struct node{
    int x,y;
};
node merge(node a,int b){
    if(a.x<0||b<0)return (node){-1,-1};
    int aa=a.x,bb=a.y;
    int d1=dis(aa,b);
    int d2=dis(bb,b);
    int d3=dis(aa,bb);
    if(d1+d2==d3)return (node){aa,bb};
    if(d1+d3==d2)return (node){b,bb};
    if(d2+d3==d1)return (node){aa,b};
    return (node){-1,-1};
}
node operator+(node a,node b){
    if(a.x<0||b.x<0)return (node){-1,-1};
    node pd=merge(a,b.x);
    if(pd.x<0)return (node){-1,-1};
    else return merge(pd,b.y);
}
struct seg{
	node t[N<<2];
	void modify(int rt,int l,int r,int X,int d){
		if(l==r)return t[rt]={d,d},void();
		int mid=(l+r)>>1;
		if(X<=mid)modify(rt<<1,l,mid,X,d);
		else modify(rt<<1|1,mid+1,r,X,d);
		t[rt]=t[rt<<1]+t[rt<<1|1];
	}
    int query(int rt,int l,int r,node &nps){
        if(t[rt].x>=0){
            if(nps.x<0)return nps=t[rt],r+1;
            node now=nps+t[rt];
            if(now.x>=0)return nps=now,r+1;
        }
        if(l==r)return l;
        int mid=(l+r)>>1;
        int res=query(rt<<1,l,mid,nps);
        if(res<=mid)return res;
        return query(rt<<1|1,mid+1,r,nps);
    }
}tr;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&p[i]),pos[p[i]]=i;
	for(int i=2;i<=n;i++){
		int x;
		scanf("%d",&x);
		add(x,i);
		add(i,x);
	}
	dfs1(1,0);
	dfs2(1,0,1);
    for(int i=1;i<=ctt;i++){
        gen[i]={dep[dp[i]],dp[i]};
    }
    RMQ<dat>yq(gen,ctt);
    ty=yq;
    for(int i=0;i<n;i++){
        tr.modify(1,0,n-1,i,pos[i]);
    }
	int q;
	scanf("%d",&q);
	while(q--){
		int op;
		scanf("%d",&op);
        node it={-1,-1};
		if(op==2)printf("%d\n",tr.query(1,0,n-1,it));
		else{
			int x,y;
			scanf("%d%d",&x,&y);
			int vx=p[x],vy=p[y];
			swap(p[x],p[y]);
            pos[vx]=y,pos[vy]=x;
            tr.modify(1,0,n-1,vx,y);
            tr.modify(1,0,n-1,vy,x);
		}
	}
	return 0;
}