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
struct node{int sm,tg,lz,fg[10];}T[400005];
int p[10],pc,phi,P,n,a[100005],Q,tf[10],tt;
inline void init(int P)
{
	phi=P;for(int i=2;i*i<=P;i++) if(P%i==0) {p[++pc]=i;while(P%i==0) P/=i;}
	int t=phi;if(P^1) p[++pc]=P;
	for(int i=2;i*i<=t;i++) if(t%i==0) {phi=phi/i*(i-1);while(t%i==0) t/=i;}
	if(t^1) phi=phi/t*(t-1);
}
inline int ksm(int x,int q) {int r=1;for(;q;q>>=1,x=1ll*x*x%P) if(q&1) r=1ll*r*x%P;return r;}
inline void FAC(int w,int &v,int *f) {for(int i=1;i<=pc;i++) {f[i]=0;while(w%p[i]==0) w/=p[i],f[i]++;}v=w%P;}
inline void DIV(int w,int &v,int *f) {for(int i=1;i<=pc;i++) while(w%p[i]==0) f[i]--,w/=p[i];v=1ll*v*ksm(w,phi-1)%P;}
inline int CAL(int v,int *f) {for(int i=1;i<=pc;i++) v=1ll*v*ksm(p[i],f[i])%P;return v;}
inline void pushup(int x) {T[x].sm=(T[x<<1].sm+T[x<<1|1].sm)%P;}
inline void allc(int x,int lz,int tg,int *w)
{
	T[x].sm=1ll*T[x].sm*lz%P,T[x].tg=1ll*T[x].tg*tg%P,T[x].lz=1ll*T[x].lz*lz%P;
	for(int i=1;i<=pc;i++) T[x].fg[i]+=w[i];
}
inline void pushdw(int x)
{
	allc(x<<1,T[x].lz,T[x].tg,T[x].fg),allc(x<<1|1,T[x].lz,T[x].tg,T[x].fg);
	T[x].lz=T[x].tg=1;for(int i=1;i<=pc;i++) T[x].fg[i]=0;
}
inline void build(int x,int l,int r)
{
	T[x].lz=T[x].tg=1;if(l==r) return T[x].sm=a[l]%P,FAC(a[l],T[x].tg,T[x].fg),void();
	build(x<<1,l,(l+r)>>1),build(x<<1|1,((l+r)>>1)+1,r),pushup(x);
}
inline void dddiv(int x,int l,int r,int dw,int dc)
{
	if(l==r) return DIV(dc,T[x].tg,T[x].fg),T[x].sm=CAL(T[x].tg,T[x].fg),void();else pushdw(x);
	if(dw<=((l+r)>>1)) dddiv(x<<1,l,(l+r)>>1,dw,dc),pushup(x);
	else dddiv(x<<1|1,((l+r)>>1)+1,r,dw,dc),pushup(x);
}
inline void modif(int x,int l,int r,int dl,int dr,int dc)
{
	if(l>dr||dl>r) return;else if(dl<=l&&r<=dr) return allc(x,dc,tt,tf);
	pushdw(x),modif(x<<1,l,(l+r)>>1,dl,dr,dc),modif(x<<1|1,((l+r)>>1)+1,r,dl,dr,dc),pushup(x);
}
inline int query(int x,int l,int r,int dl,int dr)
{
	if(l>dr||dl>r) return 0;else if(dl<=l&&r<=dr) return T[x].sm;else pushdw(x);
	return (query(x<<1,l,(l+r)>>1,dl,dr)+query(x<<1|1,((l+r)>>1)+1,r,dl,dr))%P;
}
int main()
{
	read(n),read(P);for(int i=1;i<=n;i++) read(a[i]);
	for(init(P),build(1,1,n),read(Q);Q--;)
	{
		int op,l,r,w;read(op),read(l),read(r);
		if(op==1) read(w),FAC(w,tt,tf),modif(1,1,n,l,r,w);
		else if(op==2) dddiv(1,1,n,l,r);
		else printf("%d\n",query(1,1,n,l,r));
		//for(int i=1;i<=n;i++) printf("%d%c",query(1,1,n,i,i),i==n?'\n':' ');
	}
	return 0;
}