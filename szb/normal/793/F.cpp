#include<bits/stdc++.h>
using namespace std;
#define ll int
#define llu unsigned long long
#define ld double
#define llu unsigned long long
#define rep(i,x,y)  for(ll i=x;i<y;++i)
#define For(i,x,y)  for(ll i=x;i<=y;++i)
#define FOr(i,x,y)  for(ll i=x;i>=y;--i)
#define pi acos(-1)
#define mk make_pair<ll,ll>
#define pa pair<ll,ll>
#define lf else if
#define min(x,y)    ((x)<(y)?(x):(y))
#define sqr(x)      ((x)*(x))
#define abs(x)      ((x)>0?(x):-(x))
#define Mul(x,y)    ((x)=1LL*(x)*(y)%mod)
#define Add(x,y)    ((x)=((x)+(y))%mod)
#define Min(x,y)    ((x)=((x)>(y)?(y):(x)))
#define E(x)        return writeln(x),0
#define p(x)        printf("~%d~\n",x)
#define pp(x,y)     printf("~~%d %d~~\n",x,y)
#define ppp(x,y,z)  printf("~~~%d %d %d~~~\n",x,y,z)
#define pppp(a,b,c,d)	printf("~~~%d %d %d %d\n",a,b,c,d)
#define f_in(x)     freopen(x".in","r",stdin)
#define f_out(x)    freopen(x".out","w",stdout)
#define open(x)     f_in(x),f_out(x)
#define GuYue		puts("\nGuYueNa________________________________________________________________________________")
typedef complex<double> E;
namespace SHENZHEBEI{
#define NEG 1
    inline char gc(){	return getchar();	}
#if NEG
    inline ll read(){    ll x=0,fa=1; char ch=gc();   for (;!isdigit(ch);ch=gc()) if (ch=='-') fa=-1;  for (;isdigit(ch);ch=gc())  x=x*10-48+ch;   return x*fa; }
    inline void write(ll x){    if (x<0) putchar('-'),x=-x;  if (x>=10)   write(x/10);    putchar(x%10+'0');  }
#else
    inline ll read(){    ll x=0; char ch=gc();   for (;!isdigit(ch);ch=gc());    for (;isdigit(ch);ch=gc())  x=x*10-48+ch;   return x;   }
    inline void write(ll x){    if (x>=10)   write(x/10);    putchar(x%10+'0');  }
#endif
	void writeln(ll x){write(x);puts("");}
	void Print(long long *a,int s,int t){For(i,s,t)printf("%lld ",a[i]);}
	void Print(int *a,int s,int t){For(i,s,t)printf("%d ",a[i]);}
	void Print(char *a,int s,int t){For(i,s,t)putchar(a[i]);}
}using namespace SHENZHEBEI;
ll top,cnt,m,k,Q,Left[1000010],q[1000010],lzh[2000010],L[4000010],R[4000010],guyue[20000010],naer[20000010],fa[1000010],n,ans,x,y;
ll max(ll x,ll y){return x>y?x:y;}
inline ll find(ll x){return x==fa[x]?x:fa[x]=find(fa[x]);}
inline void Max(ll &x,ll y){x=x<y?y:x;}
void build(ll l,ll r,ll p){
	top=0;
	For(i,l,r)if (Left[i]&&Left[i]<l)q[++top]=Left[i];
	sort(q+1,q+top+1);top=unique(q+1,q+top+1)-1-q;
	For(i,1,top)lzh[i]=0;
	For(i,l,r+1)fa[i]=i;
	FOr(i,r,l)if (Left[i]){
		if (Left[i]<l)Max(lzh[lower_bound(q+1,q+top+1,Left[i])-q],find(i));
		else	for(ll j=find(Left[i]);j<i;j=find(j+1))fa[j]=i;
	}
	L[p]=cnt+1;
	FOr(i,top-1,1)Max(lzh[i],lzh[i+1]);
	For(i,1,top)naer[++cnt]=lzh[i],	guyue[cnt]=q[i];
	R[p]=cnt;
	if (l==r)return;
	ll mid=(l+r)>>1;
	build(mid+1,r,p<<1|1);build(l,mid,p<<1);
}
inline void query(ll l,ll r,ll s,ll t){
	ll pos=lower_bound(guyue+l,guyue+r+1,s)-guyue;
	if ((pos<=r)&&(guyue[pos]<=t))ans=naer[pos];
}
void Query(ll l,ll r,ll p,ll s,ll t){
	if (s<=l&&r<=t)return query(L[p],R[p],x,ans),void(0);
	ll mid=(l+r)>>1;
	if (s<=mid)	Query(l,mid,p<<1,s,t);
	if (t>mid)	Query(mid+1,r,p<<1|1,s,t);
}
int main(){
//	f_in("gemo");
//	f_out("gemo");
	n=read(),k=read();
	for(;k--;){ll x=read(),y=read();if (x^y)Left[y]=x;}
	Q=read();
	if (n>1){ll mid=(1+n)/2;	build(1,mid,2);	build(mid+1,n,3);}
	for(;Q--;){
		x=read(),y=read();ans=x;
		if (x==y)writeln(y);
		else{
			Query(1,n,1,x+1,y);
			writeln(ans);
		}
	}//writeln(clock());
}
/*
x--y

k	->max{x,x+k}

 
y

?
 
*/