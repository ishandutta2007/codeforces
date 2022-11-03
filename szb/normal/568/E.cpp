	

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define llu unsigned long long
#define ld double
#define llu unsigned long long
#define rep(i,x,y)  for(ll i=(ll)(x);i<(ll)(y);++i)
#define For(i,x,y)  for(ll i=(ll)(x);i<=(ll)(y);++i)
#define FOr(i,x,y)  for(ll i=(ll)(x);i>=(ll)(y);--i)
#define pi acos(-1) 
#define mk make_pair
#define pa pair<ll,ll>
#define lf else if
#define IL inline
#define sqr(x)      ((x)*(x))
#define Mul(x,y)    ((x)=1LL*(x)*(y)%mod)
#define Add(x,y)    ((x)=((x)+(y))%mod)
#define E(x)        return writeln(x),0
#define LL			(long long)
#define p(x)        printf("~%lld~\n",LL(x))
#define pp(x,y)     printf("~~%lld %lld~~\n",LL(x),LL(y))
#define ppp(x,y,z)  printf("~~~%lld %lld %lld~~~\n",LL(x),LL(y),LL(z))
#define pppp(a,b,c,d)	printf("~~~%lld %lld %lld %lld\n",LL(a),LL(b),LL(c),LL(d))
#define f_in(x)     freopen(x".in","r",stdin)
#define f_out(x)    freopen(x".out","w",stdout)
#define open(x)     f_in(x),f_out(x)
#define fi first
#define se second
#define GuYue		puts("\nGuYueNa________________________________________________________________________________")
#define y1			fafa____
typedef complex<double> E;
namespace SHENZHEBEI{
#ifdef LOCAL
    struct _{_(){freopen("cf.in","r",stdin);}}_; 
#endif 
#define NEG 1
    static const int GYN=2333333;
    char SZB[GYN],*S=SZB,*T=SZB;
    inline char gc(){   if (S==T){  T=(S=SZB)+fread(SZB,1,GYN,stdin); if (S==T) return '\n';  }   return *S++;    }
#if NEG
    inline ll read(){    ll x=0,g=1; char ch=gc();   for (;!isdigit(ch);ch=gc()) if (ch=='-') g=-1;  for (;isdigit(ch);ch=gc())  x=x*10-48+ch;   return x*g; }
    inline void write(ll x){    if (x<0) putchar('-'),x=-x;  if (x>=10)   write(x/10);    putchar(x%10+'0');  }
#else
    inline ll read(){    ll x=0; char ch=gc();   for (;!isdigit(ch);ch=gc());    for (;isdigit(ch);ch=gc())  x=x*10-48+ch;   return x;   }
    inline void write(ll x){    if (x>=10)   write(x/10);    putchar(x%10+'0');  }
#endif
    inline char readchar(){ char ch=gc();   for(;isspace(ch);ch=gc());  return ch;  }
    inline ll readstr(char *s){ char ch=gc();   int cur=0;  for(;isspace(ch);ch=gc());      for(;!isspace(ch);ch=gc())  s[cur++]=ch;    s[cur]='\0';    return cur; }
	void Print(long long *a,int s,int t){For(i,s,t)printf("%lld ",a[i]);puts("");}
	void Print(int *a,int s,int t){For(i,s,t)printf("%d ",a[i]);puts("");}
	void Print(char *a,int s,int t){For(i,s,t)putchar(a[i]);puts("");}
	void writeln(ll x){write(x);putchar('\n');}
}using namespace SHENZHEBEI;
const ll N=100010;
multiset<ll>s;
ll cur[N],n,m,a[N],b[N];
pa nxt[N];
pair<ll,pa>f[N];
bool cmp(ll a,ll b){return a>b;}
int main(){
	n=read();
	For(i,1,n)a[i]=read(),f[i]=mk(2e9,mk(0,0));
	m=read();a[++n]=2e9;
	For(i,1,m)b[i]=read(),s.insert(b[i]);
	sort(b+1,b+m+1,cmp);
	For(i,1,n)if (a[i]!=-1){
		cur[i]=cur[i-1];
		ll l=1,r=i-1,ans=0;
		for(;l<=r;){
			ll mid=(l+r)>>1;
			if (f[mid].fi<a[i])	ans=mid,l=mid+1;
			else	r=mid-1;
		}
		nxt[i]=f[ans].se;
		f[ans+1]=min(f[ans+1],mk(a[i],mk(i,0ll)));
	}else{
		cur[i]=i;	ll j=i-1;
		For(k,1,m){
			for(;f[j].fi>=b[k];j--);
			f[j+1]=min(f[j+1],mk(b[k],mk(f[j].se.fi,f[j].se.se+1)));
		}
	}
	for(ll x=n;x;){
		ll lzh=nxt[x].se;
		ll pos=nxt[x].fi,val=a[x];
		For(i,1,lzh){
			x=cur[x-1];
			multiset<ll>::iterator it;
			it=s.lower_bound(val);--it;
			a[x]=val=*it;s.erase(it);
		}x=pos;
	}
	rep(i,1,n){
		if (a[i]==-1)write(*s.begin()),putchar(' '),s.erase(s.begin());
		else	write(a[i]),putchar(' ');
	}
}