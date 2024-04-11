#include<cstdio>
#include<cstring>
#include<algorithm>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
template<typename T>void rd(T&x){int f=0,c;while((c=getchar())<48||57<c)f^=!(c^45);x=(c&15);while(47<(c=getchar())&&c<58)x=x*10+(c&15);if(f)x=-x;}
template<typename T>T max(const T&x,const T&y){return x<y?y:x;}
template<typename T>T min(const T&x,const T&y){return x<y?x:y;}
const int N=400005,INF=0x3f3f3f3f;
int n,m,ans[N],st[N],val[N],fa[N],rev[N],tag[N],mx[N],ch[N][2];bool vis[N];
struct edge{int u,v,w,id;bool operator<(const edge&b)const{return w<b.w;}}e[N];
int get(int u){return ch[fa[u]][1]==u;}
int isroot(int u){return ch[fa[u]][0]!=u&&ch[fa[u]][1]!=u;}
void update(int u){mx[u]=max(val[u],max(mx[ch[u][0]],mx[ch[u][1]]));}
void puttag(int u,int w){ans[u]=min(ans[u],w),tag[u]=min(tag[u],w);}
void pushdown(int u){
	if(rev[u])std::swap(ch[u][0],ch[u][1]),rev[ch[u][0]]^=1,rev[ch[u][1]]^=1,rev[u]^=1;
	if(tag[u]!=INF)puttag(ch[u][0],tag[u]),puttag(ch[u][1],tag[u]),tag[u]=INF;
}
void rotate(int u){
	int p=fa[u],gp=fa[p],x=get(u);
	if(!isroot(p))ch[gp][get(p)]=u;fa[u]=gp;
	ch[p][x]=ch[u][x^1],fa[ch[u][x^1]]=p;
	ch[u][x^1]=p,fa[p]=u;
	update(p),update(u);
}
void splay(int u){
	st[*st=1]=u;
	for(int i=u;!isroot(i);i=fa[i])st[++*st]=fa[i];
	for(int i=*st;i>=1;--i)pushdown(st[i]);
	for(;!isroot(u);rotate(u))
		if(!isroot(fa[u]))
			rotate(get(u)==get(fa[u])?fa[u]:u);
}
void access(int u){
	for(int i=0;u;i=u,u=fa[u]){
		splay(u);
		ch[u][1]=i;
		update(u);
	}
}
void makeroot(int u){
	access(u);
	splay(u),rev[u]^=1; 
}
void link(int u,int v){
	makeroot(u),fa[u]=v;
}
int findroot(int u){
	access(u),splay(u);
	while(ch[u][0])u=ch[u][0];
	return u;
}
int main(){
	memset(ans,63,sizeof(ans)),memset(tag,63,sizeof(tag));
	rd(n),rd(m);rep(i,1,m)rd(e[i].u),rd(e[i].v),rd(e[i].w),e[i].id=i;std::sort(e+1,e+1+m);
	rep(i,1,m){
		int u=e[i].u,v=e[i].v,w=e[i].w,id=e[i].id+n;
		if(findroot(u)!=findroot(v)){
			val[id]=w;
			link(u,id);
			link(v,id);
			vis[id]=1;
		}else{
			makeroot(u),access(v),splay(v);
			ans[id]=mx[v]-1;
			puttag(v,w);
		}
	}
	rep(i,n+1,n+m){
		if(vis[i]){
			access(i),splay(i);
			if(ans[i]!=INF)printf("%d ",ans[i]-1);else printf("%d ",-1);
		}else printf("%d ",ans[i]);
	}
	return 0;
}