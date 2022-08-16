#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

namespace sgt{
	int timer;
	int lazy[600000],mina[600000],sum[600000],mark[600000];
	void clear(int id,int l,int r){if(mark[id]!=timer) lazy[id]=mina[id]=0,sum[id]=r-l+1,mark[id]=timer;}
	void pushdown(int id,int l,int r){
		int mid=(l+r)/2;
		clear(id<<1,l,mid),clear(id<<1|1,mid+1,r);
		if(lazy[id]){
			lazy[id<<1]+=lazy[id],mina[id<<1]+=lazy[id];
			lazy[id<<1|1]+=lazy[id],mina[id<<1|1]+=lazy[id];
			lazy[id]=0;
		}
	}
	void change(int id,int l,int r,int ql,int qr,int c){
		clear(id,l,r);
		if(l==ql&&r==qr) return (void)(lazy[id]+=c,mina[id]+=c);
		pushdown(id,l,r);
		int mid=(l+r)/2;
		if(qr<=mid) change(id<<1,l,mid,ql,qr,c);
		else if(ql>mid) change(id<<1|1,mid+1,r,ql,qr,c);
		else change(id<<1,l,mid,ql,mid,c),change(id<<1|1,mid+1,r,mid+1,qr,c);
		if(mina[id<<1]<mina[id<<1|1]) mina[id]=mina[id<<1],sum[id]=sum[id<<1];
		else if(mina[id<<1]>mina[id<<1|1]) mina[id]=mina[id<<1|1],sum[id]=sum[id<<1|1];
		else mina[id]=mina[id<<1],sum[id]=sum[id<<1]+sum[id<<1|1];
	}
	pii query(int id,int l,int r,int ql,int qr){
		clear(id,l,r);
		if(l==ql&&r==qr) return mp(mina[id],sum[id]);
		pushdown(id,l,r);
		int mid=(l+r)/2;
		if(qr<=mid) return query(id<<1,l,mid,ql,qr);
		else if(ql>mid) return query(id<<1|1,mid+1,r,ql,qr);
		pii lson=query(id<<1,l,mid,ql,mid),rson=query(id<<1|1,mid+1,r,mid+1,qr);
		if(lson.fi==rson.fi) return mp(lson.fi,lson.se+rson.se);
		else if(lson.fi<rson.fi) return lson;
		else return rson;
	}
}

struct node{
	int x,y,val,opt;
	node(int x=0,int y=0,int val=0,int opt=0):x(x),y(y),val(val),opt(opt){}
	bool operator<(const node c)const{return x==c.x?opt<c.opt:x<c.x;}
};

int n,m,tot,ncnt=0;
vector<vector<char> > a;
int v[400005],nxt[400005],h[200005],du[200005],rt[200005],dfn[200005],siz[200005];
char s[200005];
map<int,vector<node> > vec[200005];

int id(int x,int y){return (x-1)*m+y;}
void addedge(int x,int y){v[++tot]=y; nxt[tot]=h[x]; h[x]=tot; du[y]++;}

void dfs(int u,int r){
	rt[u]=r,dfn[u]=++ncnt,siz[u]=1;
	for(int p=h[u];p;p=nxt[p]) dfs(v[p],r),siz[u]+=siz[v[p]];
}

int main(){
	n=readint(); m=readint();
	a.pb(vector<char>(0));
	for(int i=1;i<=n;i++){
		scanf("%s",s+1);
		for(int j=1;j<=m;j++){
			if(s[j]=='U'&&i+2<=n) addedge(id(i+2,j),id(i,j));
			else if(s[j]=='D'&&i-2>=1) addedge(id(i-2,j),id(i,j));
			else if(s[j]=='L'&&j+2<=m) addedge(id(i,j+2),id(i,j));
			else if(s[j]=='R'&&j-2>=1) addedge(id(i,j-2),id(i,j));
		}
		vector<char> tmp(0);
		tmp.pb(0);
		for(int j=1;j<=m;j++) tmp.pb(s[j]);
		a.pb(tmp);
	}
	for(int i=1;i<=n*m;i++){
		if(!du[i]){
			ncnt=0;
			dfs(i,i);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]=='D'||a[i][j]=='R') continue;
			int x,y;
			if(a[i][j]=='U') x=id(i,j),y=id(i+1,j);
			else x=id(i,j),y=id(i,j+1);
			if(rt[x]>rt[y]) swap(x,y);
			if(rt[x]<rt[y]){
				vec[rt[x]][rt[y]].pb(node(dfn[x],y,siz[x],1));
				vec[rt[x]][rt[y]].pb(node(dfn[x]+siz[x],y,siz[x],-1));
			}
			else assert(0);
		}
	}
	ll ans=0;
	for(int i=1;i<=n*m;i++){
		if(rt[i]!=i) continue;
		for(auto q:vec[i]){
			auto g=q.se;
			sort(g.begin(),g.end());
			sgt::timer++;
			for(auto r:g){
				if(r.opt<0) sgt::change(1,1,n*m,dfn[r.y],dfn[r.y]+siz[r.y]-1,-1);
				else{
					pii tmp=sgt::query(1,1,n*m,dfn[r.y],dfn[r.y]+siz[r.y]-1);
					if(tmp.fi==0) ans+=1ll*tmp.se*r.val;
					sgt::change(1,1,n*m,dfn[r.y],dfn[r.y]+siz[r.y]-1,1);
				}
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}