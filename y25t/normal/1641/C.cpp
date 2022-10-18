#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")

#include<bits/stdc++.h>
#define N 200005

char buf[1<<23],*p1=buf,*p2=buf;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<23,stdin),p1==p2)?EOF:*p1++)
inline void rd(int &x){
	x=0;
	char c=getchar();
	while(c<'0'||c>'9')
		c=getchar();
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
}
char obuf[1<<23],*O=obuf;
#define putchar(c) (*O++=c)

int n,q;

int m,a[N][3];
std::vector<std::pair<int,int>> Q;

int b[N],c[N];

struct node{
	int mn,cnt,id,add;
	node(){
		mn=N,cnt=id=add=0;
	}
}t[N<<2];
node operator + (node x,node y){
	node res;
	res.mn=std::min(x.mn,y.mn);
	res.cnt=(x.mn==res.mn?x.cnt:0)+(y.mn==res.mn?y.cnt:0);
	res.id=x.mn==res.mn?x.id:y.id;
	return res;
}
inline void psh(int p,int d){
	t[p].mn+=d,t[p].add+=d;
}
inline void pshd(int p){
	psh(p<<1,t[p].add),psh(p<<1|1,t[p].add);
	t[p].add=0;
}
inline void build(int p,int L,int R){
	if(L==R)
		return t[p].mn=0,t[p].cnt=1,t[p].id=L,t[p].add=0,void();
	int mid=(L+R)>>1;
	build(p<<1,L,mid),build(p<<1|1,mid+1,R);
	t[p]=t[p<<1]+t[p<<1|1];
}
inline void add(int p,int L,int R,int l,int r,int d){
	if(L>r||R<l)
		return;
	if(l<=L&&R<=r)
		return psh(p,d);
	pshd(p);
	int mid=(L+R)>>1;
	add(p<<1,L,mid,l,r,d),add(p<<1|1,mid+1,R,l,r,d);
	t[p]=t[p<<1]+t[p<<1|1];
}
inline node sum(int p,int L,int R,int l,int r){
	if(L>r||R<l)
		return node();
	if(l<=L&&R<=r)
		return t[p];
	pshd(p);
	int mid=(L+R)>>1;
	return sum(p<<1,L,mid,l,r)+sum(p<<1|1,mid+1,R,l,r);
}

int d[N];
inline void sol(int L,int R,std::vector<int> &V){
	if(L==R){
		for(auto i:V)
			if(d[i])
				b[d[i]]=1,c[d[i]]=std::min(c[d[i]],std::max(i,L));
		return;
	}
	int mid=(L+R)>>1;
	std::vector<int> A,B;
	for(int i=L;i<=mid;i++)
		if(!a[i][2])
			add(1,1,n,a[i][0],a[i][1],1);
	for(auto i:V){
		node x=sum(1,1,n,a[i][0],a[i][1]);
		if(x.mn==0&&x.cnt==1){
			d[i]=x.id;
			A.push_back(i);
		}
		else
			B.push_back(i);
	}
	sol(mid+1,R,B);
	for(int i=L;i<=mid;i++)
		if(!a[i][2])
			add(1,1,n,a[i][0],a[i][1],-1);
	sol(L,mid,A);
}

int main(){
	rd(n),rd(q);
	for(int i=1;i<=n;i++)
		b[i]=-1,c[i]=N;
	std::set<int> s;
	for(int i=1;i<=n+1;i++)
		s.insert(i);
	std::vector<int> V;
	for(int i=1;i<=q;i++){
		int op;
		rd(op);
		if(!op){
			m++;
			rd(a[m][0]),rd(a[m][1]),rd(a[m][2]);
			if(!a[m][2]){
				int x=*s.lower_bound(a[m][0]);
				while(x<=a[m][1]){
					b[x]=0,c[x]=m;
					s.erase(x);
					x=*s.lower_bound(x);
				}
			}
			else
				V.emplace_back(m);
		}
		else{
			int x;
			rd(x);
			Q.emplace_back(m,x);
		}
	}
	build(1,1,n);
	sol(1,m+1,V);
	for(auto [x,y]:Q)
		if(b[y]==-1||c[y]>x)
			putchar('N'),putchar('/'),putchar('A'),putchar('\n');
		else if(b[y])
			putchar('Y'),putchar('E'),putchar('S'),putchar('\n');
		else
			putchar('N'),putchar('O'),putchar('\n');
	fwrite(obuf,O-obuf,1,stdout);
}