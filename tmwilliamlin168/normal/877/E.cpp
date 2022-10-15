#include<iostream>
#include<cstdio>
using namespace std;
const int N=200005;
int ti,n,q,a[N],nextt[N],ed[N],son[N];
int nedge,tree[N<<2],in[N],out[N],lazy[N<<2];
inline int p(int a,int b){
	return a+b;
}
inline void cao(int p,int l,int r){
	tree[p]=r-l+1-tree[p];
}
inline void pushdown(int p,int l,int r){
	if(!lazy[p])return; int mid=(l+r)>>1;
	lazy[p<<1]^=lazy[p]; lazy[(p<<1)+1]^=lazy[p]; cao(p<<1,l,mid); cao((p<<1)^1,mid+1,r); lazy[p]=0;
}
inline int ask(int l,int r,int i,int j,int nod){int mid=(l+r)>>1;
	if (l==i&&j==r) return tree[nod]; pushdown(nod,l,r);
	if (j<=mid) return ask(l,mid,i,j,nod<<1);
	else if(i>mid) return ask(mid+1,r,i,j,(nod<<1)+1);
	int left=ask(l,mid,i,mid,nod<<1);
	int right=ask(mid+1,r,mid+1,j,(nod<<1)+1);
	return p(left,right);
}
inline void insert(int l,int r,int i,int j,int nod){int mid=(l+r)>>1;
	if(l==i&&r==j){
		lazy[nod]^=1; cao(nod,l,r); return;
	}
    pushdown(nod,l,r);
    if(j<=mid)insert(l,mid,i,j,nod<<1); else
    if(i>mid)insert(mid+1,r,i,j,(nod<<1)+1); else{
    	insert(l,mid,i,mid,nod<<1); insert(mid+1,r,mid+1,j,(nod<<1)+1);
	}
	tree[nod]=p(tree[nod<<1],tree[(nod<<1)^1]);
}
inline void build(int l,int r,int nod){int mid=(l+r)>>1;
	if (l==r) {tree[nod]=a[l]; return;}
	build(l,mid,nod<<1); build(mid+1,r,(nod<<1)+1);
	tree[nod]=p(tree[nod<<1],tree[(nod<<1)+1]);
}
inline void write(int a){
	if(a>=10)write(a/10);
	putchar('0'+a%10);
}
inline void writeln(int a){
	write(a); puts("");
}
inline int	read(){
	int x = 0; char ch = getchar(); bool positive = 1;
	for (; !isdigit(ch); ch = getchar())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = getchar())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void aedge(int a,int b){
	nextt[++nedge]=son[a]; son[a]=nedge; ed[nedge]=b;
}
inline void dfs(int p){
	in[p]=++ti;
	for(int i=son[p];i;i=nextt[i]){
		dfs(ed[i]);
	}
	out[p]=ti;
}
char ch[10];
int main(){
	n=read();
	for(int i=2;i<=n;i++){
		int t1=read();
		aedge(t1,i);
	}
	dfs(1);
	for(int i=1;i<=n;i++)a[in[i]]=read();
	build(1,n,1);
	q=read();
	while(q--){
		scanf("%s",&ch); int s1=read();
		if(ch[0]=='g'){
			writeln(ask(1,n,in[s1],out[s1],1));
		}else{
			insert(1,n,in[s1],out[s1],1);
		}
	}
}