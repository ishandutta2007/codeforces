
 #include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define ld long double
#define rep(i,x,y)  for(ll i=x;i<y;++i)
#define For(i,x,y)  for(ll i=x;i<=y;++i) 
#define FOr(i,x,y)  for(ll i=x;i>=y;--i) 
#define pi acos(-1)
#define mk make_pair<ll,ll>
#define pa pair<ll,ll>
#define lf else if
#define max(x,y)    ((x)<(y)?(y):(x))
#define min(x,y)    ((x)<(y)?(x):(y))
#define sqr(x)		(x)*(x)
#define abs(x)		(x)>0?(x):-(x)
#define Mul(x,y)    x=x*(y)%mod
#define Add(x,y)    x=(x+(y))%mod
#define Max(x,y)	x=x<(y)?(y):x
#define Min(x,y)	x=x>(y)?(y):x
#define E(x) 		return writeln(x),0
#define p(x)		printf("~%d~\n",x)
#define pp(x,y)		printf("~~%d %d~~\n",x,y)
#define ppp(x,y,z)	printf("~~~%d %d %d~~~\n",x,y,z)
#define f_in(x)		freopen(x".in","r",stdin)
#define f_out(x) 	freopen(x".out","w",stdout)
#define open(x)		f_in(x),f_out(x)
#define fi first
#define se second
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
const ll N=2100000;
ll gcd[N],a[N],n,Q,used;
void change(ll l,ll r,ll p,ll pos,ll v){
	if (l==r)	return gcd[p]=v,void(0);
	ll mid=(l+r)>>1;
	pos<=mid?change(l,mid,p<<1,pos,v):change(mid+1,r,p<<1|1,pos,v);
	gcd[p]=__gcd(gcd[p<<1],gcd[p<<1|1]);
}
void query(ll l,ll r,ll p,ll s,ll t,ll v){
	if (l==s&&r==t){
		if (l==r)	return used+=gcd[p]%v>0,void(0);
		ll mid=(l+r)>>1;
		if (gcd[p<<1]%v>0)	query(l,mid,p<<1,l,mid,v);
		if (used>1)	return;
		if (gcd[p<<1|1]%v>0)query(mid+1,r,p<<1|1,mid+1,r,v);
		return;
	}ll mid=(l+r)>>1;
	if(t<=mid)	query(l,mid,p<<1,s,t,v);
	else if (s>mid)	query(mid+1,r,p<<1|1,s,t,v);
	else{
		query(l,mid,p<<1,s,mid,v);
		if(used>1)	return;
		query(mid+1,r,p<<1|1,mid+1,t,v);
	}
}
void build(ll l,ll r,ll p){
	if (l==r)	return gcd[p]=a[l],void(0);
	ll mid=(l+r)>>1;
	build(l,mid,p<<1);	build(mid+1,r,p<<1|1);
	gcd[p]=__gcd(gcd[p<<1],gcd[p<<1|1]);
}
int main(){
	n=read();
	For(i,1,n)a[i]=read();
	build(1,n,1);
	Q=read();
	while(Q--){
		if (read()==1){
			ll l=read(),r=read(),x=read();
			used=0;	query(1,n,1,l,r,x);
			puts(used<=1?"YES":"NO");
		}else{
			ll l=read(),r=read();
			change(1,n,1,l,r);
		}
	}
}
/*
1x 
*/