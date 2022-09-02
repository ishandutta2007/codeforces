#include<cstdio>
#include<cstring>
#include<algorithm>
#define debug(...) fprintf(stderr,__VA_ARGS__) 
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
typedef std::pair<int,int> pii;typedef long long ll;
template<typename T>inline void rd(T&x){int fl=0,ch;while(ch=getchar(),ch<48||57<ch)fl^=!(ch^45);x=(ch&15);while(ch=getchar(),47<ch&&ch<58)x=x*10+(ch&15);if(fl)x=-x;}
template<typename T>inline void pt(T x){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);}
template<typename T>inline void pt(T x,int ch){pt(x),putchar(ch);}
template<typename T>inline T max(const T&x,const T&y){return x<y?y:x;}
template<typename T>inline T min(const T&x,const T&y){return x<y?x:y;}
const int N=200005,dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int n,m,tot,L=1,R=1,a[1005][1005],px[N],py[N],t[5];pii tr[N<<2];int tag[N<<2];ll ans;
namespace LCT{
	int fa[N],rev[N],ch[N][2],st[N];
	int get(int u){return ch[fa[u]][1]==u;}
	int isroot(int u){return u!=ch[fa[u]][0]&&u!=ch[fa[u]][1];}
	void pushdown(int u){if(rev[u])std::swap(ch[u][0],ch[u][1]),rev[ch[u][0]]^=1,rev[ch[u][1]]^=1,rev[u]^=1;}
	void rotate(int u){
		int p=fa[u],pp=fa[p],x=get(u);
		if(!isroot(p))ch[pp][get(p)]=u;fa[u]=pp;
		ch[p][x]=ch[u][x^1],fa[ch[u][x^1]]=p;
		ch[u][x^1]=p,fa[p]=u;
	}
	void splay(int u){
		st[*st=1]=u;
		for(int i=u;!isroot(i);i=fa[i])st[++*st]=fa[i];
		for(int i=*st;i>=1;--i)pushdown(st[i]);
		for(;!isroot(u);rotate(u))if(!isroot(fa[u]))rotate(get(u)==get(fa[u])?fa[u]:u);
	}
	void access(int u){
		for(int i=0;u;i=u,u=fa[u]){
			splay(u);
			ch[u][1]=i;
		}
	}
	void makeroot(int u){
		access(u),splay(u),rev[u]^=1;
	}
	int find(int u){
		access(u);
		splay(u);
		while(ch[u][0])u=ch[u][0];
		return splay(u),u;
	}
	void link(int u,int v){
//		debug("link(%lld,%lld);\n",u,v);
		makeroot(u),fa[u]=v;
	}
	void cut(int u,int v){
//		debug("cut(%lld,%lld);\n",u,v);
		makeroot(u),access(v),splay(v);
		fa[u]=0,ch[v][0]=0;
	}
}
bool ok(int x,int y){return x>=1&&x<=n&&y>=1&&y<=m&&a[x][y]>=L&&a[x][y]<=R;}
bool chk(){
	for(int i=*t=0;i<4;++i){
		int x=px[R+1]+dir[i][0],y=py[R+1]+dir[i][1];
		if(ok(x,y))t[++*t]=LCT::find(a[x][y]);
	}
	std::sort(t+1,t+1+*t);
	rep(i,2,*t)if(t[i-1]==t[i])return 0;
	return 1;
}
pii operator+(pii a,pii b){
	pii c;c.first=min(a.first,b.first);
	if(a.first==c.first)c.second+=a.second;
	if(b.first==c.first)c.second+=b.second;
	return c;
}
void psd(int u){
	int v=u<<1;tr[v].first+=tag[u],tag[v]+=tag[u];
	++v;tr[v].first+=tag[u],tag[v]+=tag[u];
	tag[u]=0;
}
void bud(int u,int l,int r){
	if(l==r){tr[u]=std::make_pair(0,1);return;}int mid=(l+r)>>1;
	bud(u<<1,l,mid),bud(u<<1|1,mid+1,r);tr[u]=tr[u<<1]+tr[u<<1|1];
}
void mdf(int u,int l,int r,int lx,int rx,int x){
	if(l==lx&&r==rx){tr[u].first+=x,tag[u]+=x;return;}int mid=(l+r)>>1;psd(u);
	if(rx<=mid)mdf(u<<1,l,mid,lx,rx,x);else if(mid<lx)mdf(u<<1|1,mid+1,r,lx,rx,x);
	else mdf(u<<1,l,mid,lx,mid,x),mdf(u<<1|1,mid+1,r,mid+1,rx,x); 
	tr[u]=tr[u<<1]+tr[u<<1|1]; 
}
pii qry(int u,int l,int r,int lx,int rx){
	if(l==lx&&r==rx){return tr[u];}int mid=(l+r)>>1;psd(u);
	if(rx<=mid)return qry(u<<1,l,mid,lx,rx);else if(mid<lx)return qry(u<<1|1,mid+1,r,lx,rx);
	else return qry(u<<1,l,mid,lx,mid)+qry(u<<1|1,mid+1,r,mid+1,rx);
}
signed main(){
	rd(n),rd(m);tot=n*m;
	rep(i,1,n)rep(j,1,m)rd(a[i][j]),px[a[i][j]]=i,py[a[i][j]]=j;
	bud(1,1,tot);mdf(1,1,tot,1,1,1);ans=1;
	while(R<tot){
		while(L<R&&!chk()){
			for(int i=0;i<4;++i){
				int x=px[L]+dir[i][0],y=py[L]+dir[i][1];
				if(ok(x,y))
					LCT::cut(L,a[x][y]);
			}
			++L;
		}
		++R;
//		debug("range:%lld %lld\n",L,R);
		mdf(1,1,tot,L,R,1);
		for(int i=0;i<4;++i){
			int x=px[R]+dir[i][0],y=py[R]+dir[i][1];
			if(ok(x,y))
				LCT::link(R,a[x][y]),mdf(1,1,tot,L,a[x][y],-1);
		}
//		if(L==8&&R==11){
//			puts("qaq");
//		}
		pii res=qry(1,1,tot,L,R);
		ans+=res.second;
	}
	pt(ans,'\n');
	return 0;
}