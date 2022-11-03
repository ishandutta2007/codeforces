

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
#define max(x,y)    ((x)<(y)?(y):(x))
#define min(x,y)    ((x)<(y)?(x):(y))
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
const ll N=1500010;
ll a[N],b[N],sum[N],L,n;
void ok(ll l,ll r){;sum[l]++;--sum[r+1];}
void ok(ll l,ll r,ll rev){
//	pp(l,r);
	l-=rev;r-=rev;
	if (r<=0)l+=n,r+=n;
	if (l<=0)ok(l+n,n),ok(1,r);
	else	ok(l,r);
}
bool check(ll len){
	memset(sum,0,sizeof sum);
	For(i,1,n){
		ll	left=lower_bound(b+1,b+3*n+1,a[i+n]-len)-b,
			rigt=upper_bound(b+1,b+3*n+1,a[i+n]+len)-b-1,
			qian,hou;
//		ppp(left,rigt,i);	//	[3,5]	[4,6]	2,3,6,7,10,11
		if (rigt-left+1>=n){sum[1]++;continue;}
		if (rigt<=n){
			ok(left,rigt,i);
		}
		lf (left>2*n){
			ok(left-2*n,rigt-2*n,i);
		}lf (rigt>2*n){
			ok(left-n,n,i);
			ok(1,rigt-2*n,i);
		}
		lf (left<=n){
			ok(left,n,i);
			ok(1,rigt-n,i);
		}
		else{
			ok(left-n,rigt-n,i);
		}
	}
	For(i,1,n){
		sum[i]+=sum[i-1];
		if(sum[i]==n)return 1;
	}return 0;
}
int main(){
	n=read();L=read();
	For(i,1,n)a[i]=read();
	For(i,1,n)b[i]=read();
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	For(i,1,n)
	a[i+n]=a[i]+L,b[i+n]=b[i]+L,
	a[i+2*n]=a[i]+L*2,b[i+2*n]=b[i]+L*2,
	a[i+3*n]=a[i]+L*3,b[i+3*n]=b[i]+L*3;
	ll l=0,r=L,mid,ans=0;
	for(;l<=r;){
		mid=(l+r)/2;
		if (check(mid))r=mid-1,ans=mid;
		else	l=mid+1;
	}writeln(ans);
}
/*
[		]
				|		[		|	]
*/