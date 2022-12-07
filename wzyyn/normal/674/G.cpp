#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
using namespace std;
namespace FASTIO{
	const int LEN=2333333;
	/*char STR[LEN],*SSS=STR,*TTT=STR;
	inline char gc(){
		if (SSS==TTT){
			TTT=(SSS=STR)+fread(STR,1,LEN,stdin);
			if (SSS==TTT) return EOF;
		}
		return *SSS++;
	}*/
	#define gc getchar
	inline int read(){
		int x=0;
		char ch=gc();
		for (;ch<'0'||ch>'9';ch=gc());
		for (;ch>='0'&&ch<='9';ch=gc())
			x=x*10-48+ch;
		return x;
	}
	inline void write(int x){
		if (!x){
			putchar('0');
			return;
		}
		static int a[20],top;
		for (top=0;x;a[++top]=x%10,x/=10);
		for (;top;putchar(a[top--]+'0'));
	}
}
using namespace FASTIO;
const int N=150005;
int n,Q,p,k,a[N];
int sz[N*4],tg[N*4];
struct node{
	int v[5],S[5];
	node(){
		memset(v,0,20);
		memset(S,0,20);
	}
	node(int _S,int _v){
		memset(v,0,20);
		memset(S,0,20);
		v[0]=_v;
		S[0]=_S; 
	}
}t[N*4];
node operator +(node a,node b){
	For(i,0,k-1) For(j,0,k-1)
		if (b.v[j]==a.v[i]){
			a.S[i]+=b.S[j];
			b.S[j]=0;
		}
	For(i,0,k-1)
		if (b.S[i]){
			int mn=0;
			For(j,1,k-1)
				if (a.S[j]<a.S[mn])
					mn=j;
			int val=min(b.S[i],a.S[mn]);
			b.S[i]-=val;
			For(j,0,k-1) a.S[j]-=val;
			if (b.S[i]){
				a.v[mn]=b.v[i];
				a.S[mn]=b.S[i];
			}
		}
	return a;
}
void build(int k,int l,int r){
	sz[k]=r-l+1;
	if (l==r){
		t[k]=node(1,a[l]);
		return;
	}
	int mid=(l+r)/2;
	build(k*2,l,mid);
	build(k*2+1,mid+1,r);
	t[k]=t[k*2]+t[k*2+1];
}
void pushdown(int k){
	if (!tg[k]) return;
	tg[k*2]=tg[k*2+1]=tg[k];
	t[k*2]=node(sz[k*2],tg[k]);
	t[k*2+1]=node(sz[k*2+1],tg[k]);
	tg[k]=0;
}
void change(int k,int l,int r,int x,int y,int v){
	if (l==x&&r==y){
		t[k]=node(sz[k],v);
		tg[k]=v;
		return;
	}
	pushdown(k);
	int mid=(l+r)/2;
	if (y<=mid) change(k*2,l,mid,x,y,v);
	else if (x>mid) change(k*2+1,mid+1,r,x,y,v);
	else{
		change(k*2,l,mid,x,mid,v);
		change(k*2+1,mid+1,r,mid+1,y,v);
	}
	t[k]=t[k*2]+t[k*2+1];
}
node ask(int k,int l,int r,int x,int y){
	if (l==x&&r==y) return t[k];
	pushdown(k);
	int mid=(l+r)/2;
	if (y<=mid) return ask(k*2,l,mid,x,y);
	if (x>mid) return ask(k*2+1,mid+1,r,x,y);
	return ask(k*2,l,mid,x,mid)+ask(k*2+1,mid+1,r,mid+1,y);
}
namespace CHECKER{
	const int M=10000005;
	int sum[M],tg[M];
	int ls[M],rs[M],nd; 
	void change(int &k,int l,int r,int x,int y,int v){
		if (!k) k=++nd;
		sum[k]+=v*(y-x+1); 
		if (l==x&&r==y){
			tg[k]+=v;
			return;
		}
		int mid=(l+r)/2;
		if (y<=mid) change(ls[k],l,mid,x,y,v);
		else if (x>mid) change(rs[k],mid+1,r,x,y,v);
		else{
			change(ls[k],l,mid,x,mid,v);
			change(rs[k],mid+1,r,mid+1,y,v);
		}
	}
	int ask(int k,int l,int r,int x,int y){
		if (!k) return 0;
		if (l==x&&r==y) return sum[k];
		int mid=(l+r)/2,v=tg[k]*(y-x+1);
		if (y<=mid) return v+ask(ls[k],l,mid,x,y);
		if (x>mid) return v+ask(rs[k],mid+1,r,x,y);
		return v+ask(ls[k],l,mid,x,mid)+ask(rs[k],mid+1,r,mid+1,y);
	}
	set<pii> S;
	int v[N],rt[N];
	void split(int p){
		set<pii>::iterator it;
		it=S.lower_bound(pii(p,1<<30));
		if (it==S.begin()) return;
		it--;
		int l=it->fi,r=it->se;
		S.erase(it);
		v[p]=v[l];
		if (l!=p) S.insert(pii(l,p-1));
		S.insert(pii(p,r));
	}
	void work(int l,int r,int dif){
		change(rt[v[l]],1,n,l,r,dif);
	}
	void change(int l,int r,int val){
		split(l); split(r+1);
		set<pii>::iterator it,pre;
		it=S.lower_bound(pii(l,-1));
		for (;it!=S.end()&&it->fi<=r;){
			pre=it++;
			work(pre->fi,pre->se,-1);
			S.erase(pre);
		}
		v[l]=val;
		S.insert(pii(l,r));
		work(l,r,1);
	}
	void build(){
		For(i,1,n) v[i]=a[i];
		For(i,1,n){
			S.insert(pii(i,i));
			work(i,i,1);
		}
	}
	int res[10];
	void output(int l,int r,node ans){
		int limit=p*(r-l+1);
		limit=limit/100+(limit%100!=0);
		*res=0;
		For(i,0,k-1){
			int S=ask(rt[ans.v[i]],1,n,l,r);
			if (S>=limit) res[++*res]=ans.v[i];
		}
		write(*res);
		For(i,1,*res){
			putchar(' ');
			write(res[i]);
		}
		puts("");
	}
};
int main(){
	n=read(); Q=read(); p=read(); k=100/p;
	For(i,1,n) a[i]=read();
	build(1,1,n);
	CHECKER::build();
	while (Q--){
		int tp=read(),l=read(),r=read();
		if (tp==1){
			int v=read();
			change(1,1,n,l,r,v);
			CHECKER::change(l,r,v);
		}
		else{
			node tmp=ask(1,1,n,l,r);
			CHECKER::output(l,r,tmp);
		}
	}
}
/*
10 10 20
5 1 3 2 4 1 1 4 2 1
1 5 7 3
1 7 8 6
1 8 9 5
1 3 5 5
2 7 10
1 1 5 2
1 3 9 2
1 1 3 5
1 8 10 2
1 10 10 3
*/