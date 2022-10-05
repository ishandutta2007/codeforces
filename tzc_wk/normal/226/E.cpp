#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define fill0(a) memset(a,0,sizeof(a))
#define fill1(a) memset(a,-1,sizeof(a))
#define fillbig(a) memset(a,63,sizeof(a))
#define pb push_back
#define ppb pop_back
#define mp make_pair
template<typename T1,typename T2> void chkmin(T1 &x,T2 y){if(x>y) x=y;}
template<typename T1,typename T2> void chkmax(T1 &x,T2 y){if(x<y) x=y;}
typedef pair<int,int> pii;
typedef long long ll;
typedef unsigned int u32;
typedef unsigned long long u64;
namespace fastio{
	#define FILE_SIZE 1<<23
	char rbuf[FILE_SIZE],*p1=rbuf,*p2=rbuf,wbuf[FILE_SIZE],*p3=wbuf;
	inline char getc(){return p1==p2&&(p2=(p1=rbuf)+fread(rbuf,1,FILE_SIZE,stdin),p1==p2)?-1:*p1++;}
	inline void putc(char x){(*p3++=x);}
	template<typename T> void read(T &x){
		x=0;char c=getchar();T neg=0;
		while(!isdigit(c)) neg|=!(c^'-'),c=getchar();
		while(isdigit(c)) x=(x<<3)+(x<<1)+(c^48),c=getchar();
		if(neg) x=(~x)+1;
	}
	template<typename T> void recursive_print(T x){if(!x) return;recursive_print(x/10);putc(x%10^48);}
	template<typename T> void print(T x){if(!x) putc('0');if(x<0) putc('-'),x=~x+1;recursive_print(x);}
	void print_final(){fwrite(wbuf,1,p3-wbuf,stdout);}
}
const int MAXN=1e5;
int n,qu,hd[MAXN+5],to[MAXN+5],nxt[MAXN+5],ec=0,root=0;
void adde(int u,int v){to[++ec]=v;nxt[ec]=hd[u];hd[u]=ec;}
int fa[MAXN+5],dep[MAXN+5],siz[MAXN+5],wson[MAXN+5],top[MAXN+5];
int dfn[MAXN+5],tim=0,rid[MAXN+5];
void dfs1(int x){
	siz[x]=1;
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e];dep[y]=dep[x]+1;
		dfs1(y);siz[x]+=siz[y];
		if(siz[y]>siz[wson[x]]) wson[x]=y;
	}
}
void dfs2(int x,int tp){
	top[x]=tp;dfn[x]=++tim;rid[tim]=x;
	if(wson[x]) dfs2(wson[x],tp);
	for(int e=hd[x];e;e=nxt[e]) if(to[e]^wson[x]) dfs2(to[e],to[e]);
}
int getlca(int x,int y){
	while(top[x]<top[y]){
		if(dep[top[x]]<dep[top[y]]) x^=y^=x^=y;
		x=fa[top[x]];
	} if(dep[x]<dep[y]) x^=y^=x^=y;
	return y;
}
vector<pii> split(int x,int y){
	vector<pii> L,R;int lca=getlca(x,y);
	while(top[x]^top[y]){
		if(dep[top[x]]>dep[top[y]]) L.pb(mp(dfn[x],dfn[top[x]])),x=fa[top[x]];
		else R.pb(mp(dfn[top[y]],dfn[y])),y=fa[top[y]];
	} if(dep[x]<dep[y]) R.pb(mp(dfn[x],dfn[y]));
	else L.pb(mp(dfn[x],dfn[y]));
	reverse(R.begin(),R.end());
	for(int i=0;i<R.size();i++) L.pb(R[i]);
	return L;
}
int rt[MAXN+5],ncnt=0;
struct node{int ch[2],val;} s[MAXN*50+5];
void build(int &k,int l,int r){
	k=++ncnt;if(l==r) return;int mid=l+r>>1;
	build(s[k].ch[0],l,mid);build(s[k].ch[1],mid+1,r);
}
int modify(int k,int l,int r,int x,int v){
	int z=++ncnt;s[z]=s[k];s[z].val+=v;
	if(l==r) return z;int mid=l+r>>1;
	if(x<=mid) s[z].ch[0]=modify(s[k].ch[0],l,mid,x,v);
	else s[z].ch[1]=modify(s[k].ch[1],mid+1,r,x,v);
	return z;
}
int query(int k,int l,int r,int ql,int qr){
	if(ql<=l&&r<=qr) return s[k].val;int mid=l+r>>1;
	if(qr<=mid) return query(s[k].ch[0],l,mid,ql,qr);
	else if(ql>mid) return query(s[k].ch[1],mid+1,r,ql,qr);
	else return query(s[k].ch[0],l,mid,ql,mid)+query(s[k].ch[1],mid+1,r,mid+1,qr);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&fa[i]);
		if(fa[i]) adde(fa[i],i);
		else root=i;
	} dfs1(root);dfs2(root,root);
	build(rt[0],1,n);scanf("%d",&qu);
	for(int i=1;i<=qu;i++){
		int opt;scanf("%d",&opt);
		if(opt==1){
			int x;scanf("%d",&x);
			rt[i]=modify(rt[i-1],1,n,dfn[x],1);
		} else {
			rt[i]=rt[i-1];
			int a,b,k,y;scanf("%d%d%d%d",&a,&b,&k,&y);
			vector<pii> p=split(a,b);
			if(!(query(rt[i],1,n,dfn[a],dfn[a])-query(rt[y],1,n,dfn[a],dfn[a]))) ++k;
			for(int j=0;j<p.size();j++){
				int l=p[j].fi,r=p[j].se,rev=(l>r);
				if(l>r) l^=r^=l^=r;
				int cnt=r-l+1-(query(rt[i],1,n,l,r)-query(rt[y],1,n,l,r));
//				printf("P %d %d %d %d %d\n",l,r,k,cnt,rev);
				if(k>cnt) k-=cnt;
				else{
					int L=l,R=r,P=-1;
					while(L<=R){
						int mid=L+R>>1,cntt=(rev)?
						(r-mid+1-(query(rt[i],1,n,mid,r)-query(rt[y],1,n,mid,r))):
						(mid-l+1-(query(rt[i],1,n,l,mid)-query(rt[y],1,n,l,mid)));
						if(cntt>=k){
							P=mid;
							if(rev) L=mid+1;
							else R=mid-1;
						} else {
							if(rev) R=mid-1;
							else L=mid+1;
						}
					} k=0;if(rid[P]==b) puts("-1");
					else printf("%d\n",rid[P]);
					break;
				}
			} if(k) puts("-1");
		}
	}
	return 0;
}