#include<bits/stdc++.h>
using namespace std;
#define ll long long
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
#define Mul(x,y)    (x=(x)*(y)%mod)
#define Add(x,y)    (x=(x+(y))%mod)
#define E(x)        return writeln(x),0
#define p(x)        printf("~%d~\n",x)
#define pp(x,y)     printf("~~%d %d~~\n",x,y)
#define ppp(x,y,z)  printf("~~~%d %d %d~~~\n",x,y,z)
#define pppp(x,y,z,a)  printf("~~~%d %d %d %d~~~\n",x,y,z,a)
#define f_in(x)     freopen(x".in","r",stdin)
#define f_out(x)    freopen(x".out","w",stdout)
#define open(x)     f_in(x),f_out(x)
#define fi first
#define se second
typedef complex<double> E;
namespace SHENZHEBEI{
#ifdef LOCAL
    struct _{_(){freopen("cf.in","r",stdin);}}_;
#endif
#define NEG 1
    inline char gc(){   return getchar();   }
#if NEG
    inline ll read(){    ll x=0,f=1; char ch=gc();   for (;!isdigit(ch);ch=gc()) if (ch=='-') f=-1;  for (;isdigit(ch);ch=gc())  x=x*10-48+ch;   return x*f; }
    inline void write(ll x){    if (x<0) putchar('-'),x=-x;  if (x>=10)   write(x/10);    putchar(x%10+'0');  }
#else
    inline ll read(){    ll x=0; char ch=gc();   for (;!isdigit(ch);ch=gc());    for (;isdigit(ch);ch=gc())  x=x*10-48+ch;   return x;   }
    inline void write(ll x){    if (x>=10)   write(x/10);    putchar(x%10+'0');  }
#endif
    inline char readchar(){ char ch=gc();   for(;isspace(ch);ch=gc());  return ch;  }
    inline ll readstr(char *s){ char ch=gc();   int cur=0;  for(;isspace(ch);ch=gc());      for(;!isspace(ch);ch=gc())  s[cur++]=ch;    s[cur]='\0';    return cur; }
    inline void writeln(ll x){  write(x);   puts("");   }
    inline ld getreal(){    static ld lbc;  scanf("%lf",&lbc);  return lbc; }
}using namespace SHENZHEBEI;
const ll N=1000010;
ll rev[N],x[N],y[N],a[N],ans[N],n,xxx;
struct Complex{
	ld a,b;
	Complex operator +(const Complex &o)const{return (Complex){a+o.a,b+o.b};}
	Complex operator -(const Complex &o)const{return (Complex){a-o.a,b-o.b};}
	Complex operator *(const Complex &o)const{return (Complex){a*o.a-b*o.b,b*o.a+a*o.b};}
	Complex operator *(const ll o)const{return (Complex){a*o,b*o};}
	Complex operator /(const ll o)const{return (Complex){a/o,b/o};}
	Complex operator !()const{return (Complex){a,-b};}
}xx[N],yy[N];
struct lbc{
	Complex wn[N][2],Wn[N];	ll L,n;
	void init(ll len){
		for(n=1,L=0;n<len;)n<<=1,++L;	ld t=pi/(n/2);
		rep(i,0,n)rev[i]=rev[i>>1]>>1|((i&1)<<L-1);
		rep(i,0,(n>>1))
					wn[i][0]=(Complex){cos(t*i),sin(t*i)},
				  	wn[i][1]=(Complex){wn[i][0].a,-wn[i][0].b};
	}
	void dft(Complex a[],ll f){
		rep(i,0,n)if (i<rev[i])swap(a[i],a[rev[i]]);
		Wn[0]=(Complex){1,0};Complex tmp;
		for(ll d=1;d<n;d<<=1){
			For(i,1,d)Wn[i]=wn[n/d*i/2][f];
			for(ll i=0;i<n;i+=d<<1)
			for(ll k=0,x=i,y=i+d;k<d;++k,++x,++y)
				tmp=a[y]*Wn[k],a[y]=a[x]-tmp,a[x]=a[x]+tmp;
		}if (f){rep(i,0,n)a[i]=a[i]/n;}
	}
}ntt;
void chengfa(){
	rep(i,0,ntt.n)	xx[i]=(Complex){x[i],0},
					yy[i]=(Complex){y[i],0};
	ntt.dft(xx,0);ntt.dft(yy,0);
	rep(i,0,ntt.n)	xx[i]=xx[i]*yy[i];
	ntt.dft(xx,1);
	rep(i,0,ntt.n)	ans[i]+=xx[i].a+0.5;
}
void cdq(ll l, ll r){
	if (l>r)return;
	if (l==r)return ++ans[a[l]],void(0);
	ll mid=(l+r)>>1;
	ntt.init(r-l+10);
	ll pos1=mid,pos2=mid,pre1=0,pre2=0;
	rep(i,0,ntt.n)x[i]=y[i]=0;
	FOr(i,mid,l){
		pre1+=a[i];
		++x[pre1];
	}
	For(i,mid,r){
		pre2+=i>mid?a[i]:0;
		++y[pre2];
	}
	chengfa();
	cdq(l,mid-1);
	cdq(mid+1,r);
}
int main(){
	n=read(),xxx=read();
	For(i,1,n)a[i]=read()<xxx;
	cdq(1,n);
	For(i,0,n)write(ans[i]),putchar(' ');
}