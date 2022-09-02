// author: xay5421
// created: Sat Jun 26 00:19:30 2021
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
inline char getc(){static char buf[1<<20],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
template<class T>void rd(T&x){int f=0,c;while(!isdigit(c=getc()))f^=!(c^45);x=(c&15);while(isdigit(c=getc()))x=x*10+(c&15);if(f)x=-x;}
template<class T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=100005,B=200;
int n,Q,b[N],bl[N],br[N],bel[N];
struct BIT{
	int t[N+5],st[B+5][2],top;
	void upd(int k1,int k2){
		st[++top][0]=k1,st[top][1]=k2;
		for(int i=k1;i<=n;i+=i&-i)t[i]+=k2;
	}
	int qry(int k1){
		int k2=0;
		for(int i=k1;i;i&=i-1)k2+=t[i];
		return k2;
	}
	void init(){
		rep(i,1,n)t[i]=1;
		rep(i,1,n)if(i+(i&-i)<=n)t[i+(i&-i)]+=t[i];
	}
	void clear(){
		while(top){
			upd(st[top][0],-st[top][1]);
			top-=2;
		}
	}
}t[N/B+5];
void reb(int bb){
	t[bb].clear();
	rep(i,bl[bb],br[bb]){
		int x=i-b[i],now=0,val=0;
		per(j,16,0)if(now+(1<<j)<=n&&val+t[bb].t[now+(1<<j)]<x){
			val+=t[bb].t[now+(1<<j)];
			now+=1<<j;
		}
		if(now<n){
			t[bb].upd(now+1,1);
		}
	}
}
void mdf(int k1,int k2){
	b[k1]=k2;
	reb(bel[k1]);
}
int sol(int pos){
	int bb=bel[pos];
	int x=pos-b[pos];
	rep(i,pos+1,br[bb]){
		if(x>=i-b[i])++x;
	}
	rep(i,bb+1,bel[n]){
		x=t[i].qry(x);
	}
	return x;
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rd(n);
	rep(i,1,n){
		rd(b[i]),bel[i]=(i-1)/B+1;
		if(!bl[bel[i]])bl[bel[i]]=i;
		br[bel[i]]=i;
	}
	rep(i,1,bel[n])t[i].init(),reb(i);
	rd(Q);
	rep(i,1,Q){
		int t;
		rd(t);
		if(t==1){
			int pos,x;
			rd(pos),rd(x);
			mdf(pos,x);
		}else{
			int x;
			rd(x);
			int ans=sol(x);
			printf("%d\n",ans);
		}
	}
	return 0;
}