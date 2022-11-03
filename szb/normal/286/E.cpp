#include<bits/stdc++.h>
#include<complex>
using namespace std; 
#define ll long long
#define rep(i,x,y)  for(ll i=x;i<y;++i)
#define For(i,x,y)  for(ll i=x;i<=y;++i) 
#define FOr(i,x,y)  for(ll i=x;i>=y;--i) 
#define pi acos(-1)
typedef complex<double> E;
ll read(){  ll x=0,f=1; char ch=getchar();  for(;ch<'0'||ch>'9';ch=getchar()) if (ch=='-')    f=-1;   for(;ch>='0'&&ch<='9';ch=getchar())   x=x*10+ch-'0';  return x*f; } 
void write(ll x){   if (x<0) putchar('-'),x=-x;  if (x>=10)   write(x/10);    putchar(x%10+'0');  } 
void writeln(ll x){ write(x);   puts("");   }
const ll N=2097152;
E a[N],b[N];
ll tot,m,n,c[N],rev[N],L,mark[N],q[N],d[N];
void fft(E *a,ll f){
	For(i,0,n-1)	if (i<rev[i])	swap(a[i],a[rev[i]]);
	for(ll i=1;i<n;i<<=1)	For(j,0,i-1){
		E wn(cos(pi/i*j),f*sin(pi/i*j)),x,y;
		for(ll k=j;k<n;k+=i<<1)	x=a[k],y=wn*a[k+i],a[k]=x+y,a[k+i]=x-y;
	}if (f==-1)	For(i,0,n-1)	a[i]/=n;
}
int main(){
//	freopen("s.in","r",stdin);
	n=read();	m=read();	--n;
	For(i,0,n)	c[i]=read(),a[c[i]]=b[c[i]]=d[c[i]]=1;	ll nn=n;
	ll t=m<<1;	for(n=1;n<=t;n<<=1)	L++;
	For(i,0,n-1)	rev[i]=(rev[i>>1]>>1)|((i&1)<<(L-1));
	fft(a,1);	fft(b,1);	For(i,0,n-1)	a[i]*=b[i];	fft(a,-1);
	For(i,1,m){
		ll now=a[i].real()+0.1;
		if (now)	mark[i]=1;
	}n=nn;
	For(i,0,nn)	if (!mark[c[i]])	q[++tot]=c[i];
	For(i,0,m)	if (!d[i]&&mark[i])	return puts("NO"),0;
	puts("YES");
	writeln(tot);
	For(i,1,tot)	printf("%lld ",q[i]);
}