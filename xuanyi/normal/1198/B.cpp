//by xay5421 2449670833@qq.com
#include<cstdio>
#define int long long
//#define debug(...) fprintf(stderr,__VA_ARGS__)
#define debug(...) ((void)0)
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
typedef long long ll;typedef unsigned long long ull;
template<typename T>inline void rd(T&x){int f=0,c;while(c=getchar(),c<48||57<c)f^=!(c^45);x=(c&15);while(c=getchar(),47<c&&c<58)x=x*10+(c&15);if(f)x=-x;}
template<typename T>inline void pt(T x){if(x<0)x=-x,putchar('-');if(x>9)pt(x/10);putchar(x%10+48);}
template<typename T>inline void pt(T x,int c){pt(x),putchar(c);}
template<typename T>inline T max(const T&x,const T&y){return x<y?y:x;}
template<typename T>inline T min(const T&x,const T&y){return x<y?x:y;}
const int N=200005;
int n,m,a[N],tag[N<<2];
void psd(int u){
	if(tag[u]){
		tag[u<<1]=max(tag[u<<1],tag[u]);
		tag[u<<1|1]=max(tag[u<<1|1],tag[u]); 
		tag[u]=0;
	}
}
void bud(int u,int l,int r){
	if(l==r){tag[u]=a[l];return;}int mid=(l+r)>>1;
	bud(u<<1,l,mid),bud(u<<1|1,mid+1,r);
}
void mdf(int u,int l,int r,int x,int y){
	if(l==r){tag[u]=y;return;}
	psd(u);int mid=(l+r)>>1;
	if(x<=mid)mdf(u<<1,l,mid,x,y);else mdf(u<<1|1,mid+1,r,x,y);
}
void calc(int u,int l,int r){
	if(l==r){pt(tag[u],l==n?'\n':' ');return;}
	psd(u);int mid=(l+r)>>1;
	calc(u<<1,l,mid),calc(u<<1|1,mid+1,r); 
}
signed main(){
	rd(n);
	rep(i,1,n)rd(a[i]);
	bud(1,1,n);
	rd(m);
	while(m--){
		int op;rd(op);
		if(op==1){
			int p,x;rd(p),rd(x);
			mdf(1,1,n,p,x);
		}else{
			int x;rd(x);
			tag[1]=max(tag[1],x);
		}
	}
	calc(1,1,n);
	return 0;
}