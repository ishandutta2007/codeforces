#include<bits/stdc++.h>
using namespace std; 
#define ll int
#define rep(i,x,y)  for(ll i=x;i<y;++i)
#define For(i,x,y)  for(ll i=x;i<=y;++i) 
#define FOr(i,x,y)  for(ll i=x;i>=y;--i) 
#define pi acos(-1)
#define mk make_pair<ll,ll>
#define pa pair<ll,ll>
#define fi first
#define se second
#define lf else if
#define max(x,y)    ((x)<(y)?(y):(x))
#define min(x,y)    ((x)<(y)?(x):(y))    
#define EXIT(x)	return writeln(x),0;
typedef complex<double> E;
namespace SHENZHEBEI{
#ifdef LOCAL
	struct _{_(){freopen("cf.in","r",stdin);}}_;
#endif 
#define NEG 1
    const int L=2333333;
    char SZB[L],*S=SZB,*T=SZB;
    inline char gc(){   if (S==T){  T=(S=SZB)+fread(SZB,1,L,stdin); if (S==T) return '\n';  }   return *S++;    }
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
}using namespace SHENZHEBEI;
const ll N=1200000;
E a[N],b[N];	char s[N];
ll rev[N],ans[N],n,len,has[N],tot;
void dft(E *a,ll f){
	For(i,0,n-1)	if (i<rev[i])	swap(a[i],a[rev[i]]);
	for(ll d=1;d<n;d<<=1){
		E wn(cos(pi/d),sin(pi/d)*f);
		for(ll i=0;i<n;i+=d<<1){
			E w(1,0),x,y;
			rep(j,0,d)	x=a[i+j],y=a[i+j+d]*w,a[i+j]=x+y,a[i+j+d]=x-y,w*=wn;
		}
	}if (f==-1)	rep(i,0,n)	a[i]/=n;
}
void work(){
	ll hh=0;
	for(n=1;n<=len*2;n<<=1)	++hh;
	rep(i,0,n)	rev[i]=(rev[i>>1]>>1)|((i&1)<<hh-1),a[i]=b[i]=0;
	rep(i,0,len)	if (s[i]=='V')	a[i]=1;
	rep(i,0,len)	if (s[i]=='K')	b[len-i]=1;
	dft(a,1);	dft(b,1);	rep(i,0,n)	a[i]*=b[i];	dft(a,-1);
	rep(i,0,n)	has[i]=(ll)(a[i].real()+0.5)>0;
}
int main(){
	ll T=read();
	while(T--){
		len=read();	readstr(s);
		if (len==1){	puts("1\n1");	continue;	}
		work();	tot=0;
		for(ll i=1;i<=len;i++){
			bool fl=1;
			for(ll j=i;j<=len;j+=i)		fl&=!has[len-j]&&!has[len+j];
			if (fl)	ans[++tot]=i;
		}
		writeln(tot);	For(i,1,tot)	write(ans[i]),putchar(' ');	puts("");
	}
}
/*

	10010
*	10000
---------
	10010

f[i-j]|=a[i]*b[j]
f[i-j+n]|=a[i]*b[j]
f[i+(n-j)]=a[i]*b[j]
f[i+rev[j]]=a[i]*rev_b[j]

*/