#include<algorithm>
#include<cmath>
#include<vector>
#include<cstdio>
#define ll long long
#define maxn 200010
#define mod 1000000007
#define For(i,x,y)  for(ll i=x;i<=y;++i)
#define FOr(i,x,y)  for(ll i=x;i>=y;--i)
using namespace std;
inline ll read(){   ll x=0,f=1;char ch=getchar();   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}  while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  return x*f; }
inline void write(ll x){    if (x<0) putchar('-'),x=-x; if (x>=10) write(x/10);   putchar(x%10+'0');  }
inline void writeln(ll x){  write(x);   puts("");   }
struct data{
	ll x,y;
}p[maxn];
ll inv[maxn],sum[maxn],inv_sum[maxn],h,w,n,f[maxn];
bool cmp(data a,data b){
	if (a.x==b.x)	return a.y<b.y;
	return a.x<b.x;
}
void init(){
	sum[0]=inv[0]=inv[1]=inv_sum[0]=inv_sum[1]=1;
	For(i,1,200000)	sum[i]=sum[i-1]*i%mod;
	For(i,2,200000)	inv[i]=(mod-mod/i)*inv[mod%i]%mod,inv_sum[i]=inv_sum[i-1]*inv[i]%mod;
}
ll calc(ll n,ll m){	return sum[n+m]*inv_sum[n]%mod*inv_sum[m]%mod;}
int main(){
	init();
	h=read();	w=read();	n=read();
	For(i,1,n)	p[i].x=read(),p[i].y=read();
	p[++n].x=h;	p[n].y=w;
	sort(p+1,p+n+1,cmp);
	For(i,1,n){
		f[i]=calc(p[i].x-1,p[i].y-1);
		For(j,1,i-1)	if (p[i].x>=p[j].x&&p[i].y>=p[j].y)	f[i]=(f[i]-f[j]*calc(p[i].x-p[j].x,p[i].y-p[j].y))%mod;
	}
	writeln((f[n]%mod+mod)%mod);
}