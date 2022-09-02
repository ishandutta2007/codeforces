//by xay5421 2449670833@qq.com
#include<set>
#include<map>
#include<cmath>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
#define debug(...) fprintf(stderr,__VA_ARGS__)
//#define debug(...) ((void)0)
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
typedef long long ll;typedef unsigned long long ull;typedef std::pair<int,int> pii;
template<typename T>void rd(T&x){int f=0,c;while((c=getchar())<48||57<c)f^=!(c^45);x=(c&15);while(47<(c=getchar())&&c<58)x=x*10+(c&15);if(f)x=-x;}
template<typename T>inline void pt(T x){if(x<0)x=-x,putchar('-');if(x>9)pt(x/10);putchar(x%10+48);}
template<typename T>inline void pt(T x,int c){pt(x),putchar(c);}
template<typename T>inline T max(const T&x,const T&y){return x<y?y:x;}
template<typename T>inline T min(const T&x,const T&y){return x<y?x:y;}
const int N=100005;
int n,m,a[N];
struct seg{
	int l,r,s;
	seg operator+(const seg&b)const{return (seg){l,b.r,s+b.s};}
	bool operator<(const seg&b)const{return s<b.s;}
};
seg mx[N<<2],mn[N<<2],lmx[N<<2],rmx[N<<2],lmn[N<<2],rmn[N<<2],sum[N<<2],q[50];int rev[N<<2];
void merge(int a,int b,int c){
	mx[c]=max(max(mx[a],mx[b]),rmx[a]+lmx[b]);
	mn[c]=min(min(mn[a],mn[b]),rmn[a]+lmn[b]);
	lmx[c]=max(lmx[a],sum[a]+lmx[b]);
	rmx[c]=max(rmx[a]+sum[b],rmx[b]);
	lmn[c]=min(lmn[a],sum[a]+lmn[b]);
	rmn[c]=min(rmn[a]+sum[b],rmn[b]);
	sum[c]=sum[a]+sum[b];
	rev[c]=0;
}
void build(int u,int l,int r){
	if(l==r){mx[u]=mn[u]=lmx[u]=rmx[u]=lmn[u]=rmn[u]=sum[u]=(seg){l,l,a[l]},rev[u]=0;return;}
	int mid=(l+r)>>1;
	build(u<<1,l,mid);
	build(u<<1|1,mid+1,r);
	merge(u<<1,u<<1|1,u);
}
void reverse(int u){
	std::swap(lmn[u],lmx[u]);
	std::swap(rmn[u],rmx[u]);
	std::swap(mn[u],mx[u]);
	mx[u].s*=-1,mn[u].s*=-1;
	lmx[u].s*=-1,lmn[u].s*=-1;
	rmx[u].s*=-1,rmn[u].s*=-1;
	sum[u].s*=-1;
	rev[u]^=1;
}
void modify(int u,int l,int r,int x,int y){
	if(l==r){mx[u]=mn[u]=lmx[u]=rmx[u]=lmn[u]=rmn[u]=sum[u]=(seg){l,l,a[l]},rev[u]=0;return;}
	if(rev[u]){
		reverse(u<<1);
		reverse(u<<1|1);
		rev[u]^=1;
	}
	int mid=(l+r)>>1;
	if(x<=mid)modify(u<<1,l,mid,x,y);
	else modify(u<<1|1,mid+1,r,x,y);
	merge(u<<1,u<<1|1,u);
}
int fst;
void query(int u,int l,int r,int lx,int rx){
	if(l==lx&&r==rx){
		if(fst){
			mx[0]=mx[u],mn[0]=mn[u];
			lmx[0]=lmx[u],lmn[0]=lmn[u];
			rmx[0]=rmx[u],rmn[0]=rmn[u];
			sum[0]=sum[u];
			fst=0;
		}else{
			merge(0,u,0);
		}
		return;
	}
	if(rev[u]){
		reverse(u<<1);
		reverse(u<<1|1);
		rev[u]^=1;
	}
	int mid=(l+r)>>1;
	if(rx<=mid)query(u<<1,l,mid,lx,rx);else
	if(mid<lx)query(u<<1|1,mid+1,r,lx,rx);else
		query(u<<1,l,mid,lx,mid),query(u<<1|1,mid+1,r,mid+1,rx);
//	merge(u<<1,u<<1|1,u);
}
void change(int u,int l,int r,int lx,int rx){
	if(l==lx&&r==rx){reverse(u);return;}
	if(rev[u]){
		reverse(u<<1);
		reverse(u<<1|1);
		rev[u]^=1;
	}
	int mid=(l+r)>>1;
	if(rx<=mid)change(u<<1,l,mid,lx,rx);else
	if(mid<lx)change(u<<1|1,mid+1,r,lx,rx);else
		change(u<<1,l,mid,lx,mid),change(u<<1|1,mid+1,r,mid+1,rx);
	merge(u<<1,u<<1|1,u);
}
signed main(){
	rd(n);
	rep(i,1,n)rd(a[i]);
	build(1,1,n);
	rd(m);
	int op,l,r,k,x,y;
	while(m--){
		rd(op);
		if(op){
			rd(l),rd(r),rd(k);
			int top=0,ans=0;
			for(int i=1;i<=k;++i){
				fst=1;
				query(1,1,n,l,r);
				if(mx[0].s<=0)break;
				ans+=mx[0].s;
				q[++top]=mx[0];
				change(1,1,n,mx[0].l,mx[0].r);
			}
			printf("%d\n",ans);
			for(int i=1;i<=top;++i)change(1,1,n,q[i].l,q[i].r);
		}else{
			rd(x),rd(y),a[x]=y;
			modify(1,1,n,x,y);
		}
	}
	return 0;
}