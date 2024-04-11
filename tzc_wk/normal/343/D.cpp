#include <bits/stdc++.h>
using namespace std;
#define fi			first
#define se			second
#define fz(i,a,b)	for(int i=a;i<=b;i++)
#define fd(i,a,b)	for(int i=a;i>=b;i--)
#define put(x)		putchar(x)
#define eoln        put('\n')
#define space		put(' ')
inline int read(){
	int x=0,neg=1;char c=getchar();
	while(!isdigit(c)){
		if(c=='-')	neg=-1;
		c=getchar();
	}
	while(isdigit(c))	x=x*10+c-'0',c=getchar();
	return x*neg;
}
inline void print(int x){
	if(x<0){
		putchar('-');
		print(abs(x));
		return;
	}
	if(x<=9)	putchar(x+'0');
	else{
		print(x/10);
		putchar(x%10+'0');
	}
}
int n=read();
vector<int> g[500005];
int siz[500005],fa[500005],dep[500005],wson[500005];
int top[500005],L[500005],R[500005],idx=0;
inline void dfs1(int x,int f){
	siz[x]=1;fa[x]=f;
	for(int i=0;i<g[x].size();i++){
		int y=g[x][i];
		if(y==f)	continue;
		dep[y]=dep[x]+1;
		dfs1(y,x);
		siz[x]+=siz[y];
		if(siz[y]>siz[wson[x]])	wson[x]=y;
	}
}
inline void dfs2(int x,int tp){
	L[x]=++idx;
	top[x]=tp;
	if(wson[x]>0)	dfs2(wson[x],tp);
	for(int i=0;i<g[x].size();i++){
		int y=g[x][i];
		if(y==fa[x]||y==wson[x])	continue;
		dfs2(y,y);
	}
	R[x]=idx;
}
struct SegTree{
	struct node{
		int l,r,val,lz;
	} s[2000005];
	inline void build(int k,int l,int r){
		s[k].l=l;s[k].r=r;s[k].lz=-1;
		if(l==r)	return;
		int mid=(l+r)>>1;
		build(k<<1,l,mid);
		build(k<<1|1,mid+1,r);
	}
	inline void pushdown(int k){
		if(s[k].lz==-1)	return;
		s[k<<1].lz=s[k].lz;
		s[k<<1].val=(s[k<<1].r-s[k<<1].l+1)*s[k].lz;
		s[k<<1|1].lz=s[k].lz;
		s[k<<1|1].val=(s[k<<1|1].r-s[k<<1|1].l+1)*s[k].lz;
		s[k].lz=-1;
	}
	inline void modify(int k,int l,int r,int x){
		if(l<=s[k].l&&s[k].r<=r){
			s[k].val=(s[k].r-s[k].l+1)*x;
			s[k].lz=x;
			return;
		}
		pushdown(k);
		int mid=(s[k].l+s[k].r)>>1;
		if(r<=mid)		modify(k<<1,l,r,x);
		else if(l>mid)	modify(k<<1|1,l,r,x);
		else			modify(k<<1,l,mid,x),modify(k<<1|1,mid+1,r,x);
		s[k].val=s[k<<1].val+s[k<<1|1].val;
	}
	inline int query(int k,int l,int r){
		if(l<=s[k].l&&s[k].r<=r){
			return s[k].val;
		}
		pushdown(k);
		int mid=(s[k].l+s[k].r)>>1;
		if(r<=mid)		return query(k<<1,l,r);
		else if(l>mid)	return query(k<<1|1,l,r);
		else			return query(k<<1,l,mid)+query(k<<1|1,mid+1,r);
	}
} st;
inline void update(int x,int y){
	if(dep[x]<dep[y])	swap(x,y);
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]])	swap(x,y);
		st.modify(1,L[top[x]],L[x],0);
		x=fa[top[x]];
	}
	if(dep[x]<dep[y])	swap(x,y);
	st.modify(1,L[y],L[x],0);
}
int main(){
	for(int i=1;i<n;i++){
		int a=read(),b=read();
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dep[1]=1;
	dfs1(1,0);
	dfs2(1,1);
	st.build(1,1,n);
	int T=read();
	while(T--){
		int opt=read(),x=read();
		if(opt==1)		st.modify(1,L[x],R[x],1);
		else if(opt==2)	update(x,1);
		else			print(st.query(1,L[x],L[x])),eoln;
	}
	return 0;
}