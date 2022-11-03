#include<cstdio> 
#include<cstring> 
#include<cmath> 
#include<algorithm> 
#include<ctime> 
using namespace std; 
#define ll long long 
#define For(i,x,y)  for(ll i=x;i<=y;++i) 
#define FOr(i,x,y)  for(ll i=x;i>=y;--i) 
ll read(){  ll x=0,f=1; char ch=getchar();  for(;ch<'0'||ch>'9';ch=getchar()) if (ch=='-')    f=-1;   for(;ch>='0'&&ch<='9';ch=getchar())   x=x*10+ch-'0';  return x*f; } 
void write(ll x){   if (x<0) putchar('-'),x=-x;  if (x>=10)   write(x/10);    putchar(x%10+'0');  } 
void writeln(ll x){ write(x);   puts("");   }
const ll mod=998244353,N=1e6+7;
char s[N];	ll a[N],bin[N],n;
ll ppow(ll x,ll k){
	ll ans=1;
	while(k){
		if (k&1)	ans=ans*x%mod;	x=x*x%mod;
		k>>=1;
	}return ans;
}
void print(ll a,ll b){
	For(i,1,a)	putchar(s[i]);	putchar('+');
	For(i,a+1,b)putchar(s[i]);	putchar('=');
	For(i,b+1,n)putchar(s[i]);
}
inline ll get(ll x,ll y){	return ((a[y]-a[x-1]*bin[y-x+1])%mod+mod)%mod;	}
inline ll pd(ll x,ll y){
	if (x<=0||y<=0)	return 0;
	if (x>(n-x-y))	return 0;
	if (y>(n-x-y))	return 0;
	if (x>1&&(s[1]=='0'))	return 0;
	if (y>1&&(s[x+1]=='0'))	return 0;
	if (n-x-y>1&&(s[x+y+1]=='0'))	return 0;

	if ((get(1,x)+get(x+1,x+y))%mod==get(x+y+1,n))	return print(x,x+y),1;
	return 0;
}
int main(){
	gets(s+1);	n=strlen(s+1);
	For(i,1,n)	a[i]=(a[i-1]*10+s[i]-'0')%mod;
	bin[0]=1;	For(i,1,n)	bin[i]=bin[i-1]*10%mod;
	For(i,3,n){
		ll t1=(n-(i-1)),t2=i-1;
		if (pd(t1,t2-t1))	return 0;
		if (pd(t1-1,t2-t1+1))	return 0;
		t1=t2-t1;
		if (pd(t1,t2-t1))	return 0;
		if (pd(t1+1,t2-t1-1))	return 0;
	}
}
/*
19999999999999999999991000000000000000000000

*/