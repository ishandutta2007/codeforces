#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define rep(i,x,y)  for(ll i=x;i<y;++i)
#define For(i,x,y)  for(ll i=x;i<=y;++i) 
#define FOr(i,x,y)  for(ll i=x;i>=y;--i) 
ll read(){  ll x=0,f=1; char ch=getchar();  for(;ch<'0'||ch>'9';ch=getchar()) if (ch=='-')    f=-1;   for(;ch>='0'&&ch<='9';ch=getchar())   x=x*10+ch-'0';  return x*f; } 
void write(ll x){   if (x<0) putchar('-'),x=-x;  if (x>=10)   write(x/10);    putchar(x%10+'0');  } 
void writeln(ll x){ write(x);   puts("");   }
ll gcd(ll a,ll b){	return b?gcd(b,a%b):a;	}
const ll N=2010,mod=1073741824;
ll pri[N],mark[N],mu[N],g[N][N],n,m,h,mx,ans;
void init(ll n){
	mu[1]=1;
	For(i,2,n){
		if (!mark[i])	pri[++pri[0]]=i,mu[i]=-1;
		for(ll j=1;j<=pri[0]&&i*pri[j]<=n;++j){
			mark[i*pri[j]]=1;
			if (!(i%pri[j])){	mu[i*pri[j]]=0;	break;	}
			mu[i*pri[j]]=-mu[i];
		}
	}
}
int main(){
	n=read();m=read();h=read();	if (n>m)	swap(n,m);
	init(n);	mx=max(max(n,m),h);
	For(i,1,mx)	For(j,1,mx)	g[i][j]=gcd(i,j);
	For(i,1,h)	For(d,1,n)	if (gcd(i,d)==1){
		ll ans1=0,ans2=0;
		For(j,1,n/d)	if (g[i][j]==1)	ans1+=n/d/j;
		For(j,1,m/d)	if (g[i][j]==1)	ans2+=m/d/j;
		ans+=ans1*ans2%mod*mu[d]*(h/i)%mod;
	}writeln((ans+mod)%mod);
}