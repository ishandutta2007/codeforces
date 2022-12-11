#include<bits/stdc++.h>
using namespace std;
const int N=3e5+10;
struct edge{
	int x,y;
} ed[N<<2];
struct que{
	int x,y;
} qu[N];
struct node{
	int x,y,rt,id;
	bool operator<(const node &b)const{
		if(x!=b.x) return x<b.x;
		if(y!=b.y) return y<b.y;
		return id<b.id;
	}
	bool operator!=(const node b)const{return x!=b.x||y!=b.y;}
}a[N<<1];
int n,m,x,y,id,len1,mp[N][2],ver[5000001],nxt[5000001],head[N<<2],ans,fa[N],siz[N],stk[N<<1],stack1[N<<1],stack2[N<<1],top,tot[N];
bool vis[N<<1];
inline void add(int x,int y){ver[++ans]=y,nxt[ans]=head[x],head[x]=ans;}
int find(int x) {return fa[x]==x?x:find(fa[x]);}
inline void unnion(int x,int y) {
	x=find(x),y=find(y);if(siz[x]<siz[y]) x^=y^=x^=y;
	if(x!=y) {
		stk[++top]=x,stack1[top]=fa[x],stack2[top]=siz[x];
		stk[++top]=y,stack1[top]=fa[y],stack2[top]=siz[y];
		fa[y]=x,siz[x]+=siz[y];
	}
}
void upd(int rt,int l,int r,int L,int R,int k){
	if(L<=l&&r<=R) return (void)(add(rt,k));
	int mid=(l+r)>>1;
	if(L<=mid) upd(rt<<1,l,mid,L,R,k);
	if(R>mid) upd(rt<<1|1,mid+1,r,L,R,k);
}
void rtt(int x){
    while(x<top)fa[stk[top]]=stack1[top],siz[stk[top]]=stack2[top],--top;
}
void solve(int rt,int l,int r) {
	int now=top;
	for(int i=head[rt];i;i=nxt[i]) if(vis[ver[i]])unnion(ed[ver[i]].x,ed[ver[i]].y);
	if(l==r) {
		if(!qu[l].x) tot[l]=tot[l-1],vis[mp[l][tot[l]]]^=1;
		else tot[l]=(find((qu[l].x+tot[l-1]-1)%n+1)==find((qu[l].y+tot[l-1]-1)%n+1));
        rtt(now);
		return;
	}
	int mid=(l+r)>>1;
	solve(rt<<1,l,mid),solve(rt<<1|1,mid+1,r);
    rtt(now);
}
int main(){
    scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)fa[i]=i,siz[i]=1;
	for(int i=1;i<=m;++i){
        scanf("%d%d%d",&id,&x,&y);
		if(id==1){
			if(x>y)x^=y^=x^=y;
            a[++len1]={x,y,0,i};
			x%=n,y%=n,++x,++y;
            if(x>y)x^=y^=x^=y;
            a[++len1]={x,y,1,i};
		}
		else qu[i]={x,y};
	}
	sort(a+1,a+1+len1);
	int len2=1;ed[1]={a[1].x,a[1].y},mp[a[1].id][a[1].rt]=1;
	for(int i=2;i<=len1;++i) { 
		int now=(a[i]!=a[i-1])?m:a[i].id;
		if(a[i-1].id<now) upd(1,1,m,a[i-1].id+1,now,len2);
		if(a[i]!=a[i-1]) ed[++len2]={a[i].x,a[i].y};
		mp[a[i].id][a[i].rt]=len2;
	}
	if(a[len1].id<m)upd(1,1,m,a[len1].id+1,m,len2);
	solve(1,1,m);
	for(int i=1;i<=m;++i)if(qu[i].x)printf("%d",tot[i]);
	return 0;
}