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
#define Mul(x,y)    (x=1LL*(x)*(y)%mod)
#define Add(x,y)    (x=(x+(y))%mod)
#define Max(x,y)    ((x)=((x)<(y)?(y):(x)))
#define Min(x,y)    ((x)=((x)>(y)?(y):(x)))
#define E(x)        return writeln(x),0
#define p(x)        printf("~%lld~\n",x)
#define pp(x,y)     printf("~~%lld %lld~~\n",x,y)
#define ppp(x,y,z)  printf("~~~%lld %lld %lld~~~\n",x,y,z)
#define pppp(a,b,c,d)	printf("~~~%d %d %d %d\n",a,b,c,d)
#define f_in(x)     freopen(x".in","r",stdin)
#define f_out(x)    freopen(x".out","w",stdout)
#define open(x)     f_in(x),f_out(x)
#define fi first
#define se second
#define GuYueNa		puts("GYN_________________________________________")
typedef complex<double> E;
namespace _GuYueNa{
#ifdef LOCAL
    struct _{_(){freopen("cf.in","r",stdin);}}_;
#endif
#define NEG 1
    inline char gc(){   return getchar();   }	
#if NEG
    inline ll read(){    ll x=0,f=1; char ch=gc();   for (;!isdigit(ch);ch=gc()) if (ch=='-') f=-1;  for (;isdigit(ch);ch=gc())  x=x*10-48+ch;   return x*f; }
    inline void write(ll x){    if (x<0) putchar('-'),x=-x;  if (x>=10)   write(x/10);    putchar(x%10+'0');  }
#else
    inline ll read(){    ll x=0; char ch=gc();   for (;!isdigit(ch);ch=gc());    for (;isdigit(ch);ch=gc()aaaaaaaaaaaaa)  x=x*10-48+ch;   return x;   }
    inline void write(ll x){    if (x>=10)   write(x/10);    putchar(x%10+'0');  }
#endif
    inline char readchar(){ char ch=gc();   for(;isspace(ch);ch=gc());  return ch;  }
    inline ll readstr(char *s){ char ch=gc();   int cur=0;  for(;isspace(ch);ch=gc());      for(;!isspace(ch);ch=gc())  s[cur++]=ch;    s[cur]='\0';    return cur; }
    inline void writeln(ll x){  write(x);   puts("");   }
    inline ld getreal(){    static ld lbc;  scanf("%lf",&lbc);  return lbc; }
}using namespace _GuYueNa;
const ll N=6010;
ll n;
char s1[N],s2[N];
ll sum[100],q[N];
void change(ll pos){
	if (pos>n)return;
//	writeln(pos);
	q[++q[0]]=pos;
	reverse(s1+1,s1+pos);
	reverse(s1+1,s1+n+1);
}
int main(){
	n=read();
	scanf("%s%s",s1+1,s2+1);
	For(i,1,n)s1[i]-='a',s2[i]-='a',
				sum[s1[i]]++,sum[s2[i]]--;
	For(i,0,25)if (sum[i])return puts("-1"),0;
	FOr(len,n-1,1)	reverse(s2+1,s2+len+1);
	For(len,1,n){
		ll pos=len;
		for(;s1[pos]!=s2[len];++pos);
		change(pos+1);
//		For(i,1,n)putchar(s1[i]+'a');puts("");
		change(len+(n-pos));
//		For(i,1,n)putchar(s1[i]+'a');puts("");
		change(n-len+2);
//		For(i,1,n)putchar(s1[i]+'a');puts("");
//		GuYueNa;
	}
	writeln(q[0]);For(i,1,q[0])printf("%d ",n-q[i]+1);
}
/*
*/