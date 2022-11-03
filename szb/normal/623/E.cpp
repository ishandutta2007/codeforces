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
#define max(x,y)    ((x)<(y)?(y):(x))
#define min(x,y)    ((x)<(y)?(x):(y))
#define sqr(x)      ((x)*(x))
#define abs(x)      ((x)>0?(x):-(x))
#define Mul(x,y)    ((x)=1LL*(x)*(y)%mod)
#define Add(x,y)    ((x)=((x)+(y))%mod)
#define Max(x,y)    ((x)=((x)<(y)?(y):(x)))
#define Min(x,y)    ((x)=((x)>(y)?(y):(x)))
#define E(x)        return writeln(x),0
#define p(x)        printf("~%lld~\n",x)
#define pp(x,y)     printf("~~%lld %lld~~\n",x,y)
#define ppp(x,y,z)  printf("~~~%lld %lld %lld~~~\n",x,y,z)
#define pppp(a,b,c,d)	printf("~~~%lld %lld %lld %lld\n",a,b,c,d)
#define f_in(x)     freopen(x,"r",stdin)
#define f_out(x)    freopen(x,"w",stdout)
#define open(x)     f_in(x".in"),f_out(x".out")
#define fi first
#define se second
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
const ll N=200010,mod=1e9+7;
ll rev[N],bin[N],f[N],Inv[N],zy[N],n,m,cnt,ans;
struct Complex{
	ld a,b;
	Complex operator +(const Complex &o)const{return (Complex){a+o.a,b+o.b};}
	Complex operator -(const Complex &o)const{return (Complex){a-o.a,b-o.b};}
	Complex operator *(const Complex &o)const{return (Complex){a*o.a-b*o.b,b*o.a+a*o.b};}
	Complex operator *(const ll o)const{return (Complex){a*o,b*o};}
	Complex operator /(const ll o)const{return (Complex){a/o,b/o};}
	Complex operator !()const{return (Complex){a,-b};}
}BB[N],Bb[N],AA[N],Aa[N],pt1[N],pt2[N],pt3[N];
struct lbc{
	Complex wn[N][2],Wn[N];	ll L,n;
	void init(ll len){
		for(n=1;n<len;)n<<=1,++L;
		rep(i,0,n)rev[i]=rev[i>>1]>>1|((i&1)<<L-1);
		For(i,0,n)wn[i][0]=(Complex){cos(pi/n*i),sin(pi/n*i)},
				  wn[i][1]=(Complex){cos(pi/n*i),-sin(pi/n*i)};
	}
	void dft(Complex a[],ll f){
		rep(i,0,n)if (i<rev[i])swap(a[i],a[rev[i]]);
		Wn[0]=(Complex){1,0};Complex tmp;
		for(ll d=1;d<n;d<<=1){
			For(i,1,d)Wn[i]=wn[n/d*i][f];
			for(ll i=0;i<n;i+=d<<1)
			for(ll k=0,x=i,y=i+d;k<d;++k,++x,++y)
				tmp=a[y]*Wn[k],a[y]=a[x]-tmp,a[x]=a[x]+tmp;
		}if (f){rep(i,0,n)a[i]=a[i]/n;}
	}
}lbc;
void zhuanyi(ll Len,ll *a,ll *b){
	ll more=bin[Len],sml=1;
	rep(i,0,m)	Bb[i]=(Complex){b[i]>>15,0},
				BB[i]=(Complex){b[i]&32767,0};
	For(i,0,n)Mul(a[i],sml),Mul(sml,more);
	rep(i,0,m)	Aa[i]=(Complex){a[i]>>15,0},
				AA[i]=(Complex){a[i]&32767,0};
	lbc.dft(Aa,0),lbc.dft(AA,0),lbc.dft(Bb,0),lbc.dft(BB,0);
	rep(i,0,m)	pt1[i]=Aa[i]*Bb[i],
				pt2[i]=AA[i]*Bb[i]+Aa[i]*BB[i],
				pt3[i]=AA[i]*BB[i];
	lbc.dft(pt1,1),lbc.dft(pt2,1),lbc.dft(pt3,1);
	rep(i,0,m)	a[i]=	(((ll)(pt1[i].a+0.5)%mod<<30)%mod+
						((ll)(pt2[i].a+0.5)%mod<<15)%mod+
						((ll)(pt3[i].a+0.5))%mod)%mod;
	rep(i,(m>>1),m)a[i]=0;
}
int main(){
	cnt=read(),n=read();
	if (cnt>n)return puts("0"),0;
	m=1;for(;m<=n;m<<=1);m<<=1;lbc.init(m);
	bin[0]=1;For(i,1,n)bin[i]=bin[i-1]*2%mod;
	Inv[0]=Inv[1]=1;For(i,2,n)Inv[i]=Inv[mod%i]*(mod-mod/i)%mod;
	f[0]=1;For(i,1,m)zy[i]=Inv[i]=Inv[i-1]*Inv[i]%mod;
	for(ll k=1;k<=cnt;zhuanyi(k,zy,zy),k<<=1)if (k&cnt)zhuanyi(k,f,zy);
	For(i,0,n)Add(ans,f[i]*Inv[n-i]);
	For(i,1,n)Mul(ans,i);
	writeln((ans+mod)%mod);
}