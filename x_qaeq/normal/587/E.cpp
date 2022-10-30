//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}/*}}}*/
struct xxj
{
	int a[30],v;inline void clear() {memset(a,0,sizeof(a));}
	inline void ins(int x) {for(int i=29;~i;i--) if((x>>i)&1) {if(a[i]) x^=a[i];else return a[i]=x,void();}}
	inline int qry() {int cnt=0;for(int i=29;~i;i--) cnt+=!!a[i];return 1<<cnt;}
	inline xxj operator+(xxj b) const {xxj r=*this;for(int i=29;~i;i--) if(b.a[i]) r.ins(b.a[i]);return r;}
	inline void debug() {for(int i=29;~i;i--) if(a[i]) printf("%d ",a[i]);putchar('\n');}
}t[800005];int n,m,T[200005],a[200005];
inline void add(int x,int w) {for(;x<=n;x+=x&(-x)) T[x]^=w;}
inline int qry(int x) {int r=0;for(;x;x-=x&(-x)) r^=T[x];return r;}
inline void build(int x,int l,int r)
{
	if(l==r) return t[x].ins(t[x].v=a[l]);
	build(x<<1,l,(l+r)>>1),build(x<<1|1,((l+r)>>1)+1,r),t[x]=t[x<<1]+t[x<<1|1];
}
inline xxj query(int x,int l,int r,int dl,int dr)
{
	if(l>dr||dl>r||dl>dr) return t[0];else if(dl<=l&&r<=dr) return t[x];
	return query(x<<1,l,(l+r)>>1,dl,dr)+query(x<<1|1,((l+r)>>1)+1,r,dl,dr);
}
inline void updat(int x,int l,int r,int dw,int dc)
{
	if(l==r) return t[x].clear(),t[x].ins(t[x].v^=dc);
	if(dw<=((l+r)>>1)) updat(x<<1,l,(l+r)>>1,dw,dc),t[x]=t[x<<1]+t[x<<1|1];
	else updat(x<<1|1,((l+r)>>1)+1,r,dw,dc),t[x]=t[x<<1]+t[x<<1|1];
}
int main()
{
	read(n),read(m);for(int i=1;i<=n;i++) read(a[i]);
	for(int i=n;i;i--) a[i]^=a[i-1],add(i,a[i]);
	for(build(1,1,n);m--;)
	{
		int tg,l,r,v;read(tg),read(l),read(r);
		if(!(tg&1)) {xxj tmp=query(1,1,n,l+1,r);tmp.ins(qry(l)),printf("%d\n",tmp.qry());}
		else {read(v),add(l,v),updat(1,1,n,l,v);if(r<n) add(r+1,v),updat(1,1,n,r+1,v);}
	}
	return 0;
}