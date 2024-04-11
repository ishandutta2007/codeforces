#include<cstdio> 
#include<cstring> 
#include<cmath> 
#include<windows.h>
#include<algorithm> 
#include<ctime> 
using namespace std; 
#define ll long long 
#define For(i,x,y)  for(ll i=x;i<=y;++i) 
#define FOr(i,x,y)  for(ll i=x;i>=y;--i) 
#define rep(i,x,y)	for(ll i=x;i<y;++i)
ll read(){  ll x=0,f=1; char ch=getchar();  for(;ch<'0'||ch>'9';ch=getchar()) if (ch=='-')    f=-1;   for(;ch>='0'&&ch<='9';ch=getchar())   x=x*10+ch-'0';  return x*f; } 
void write(ll x){   if (x<0) putchar('-'),x=-x;  if (x>=10)   write(x/10);    putchar(x%10+'0');  } 
void writeln(ll x){ write(x);   puts("");   }
const ll N=1100000;
ll a[N],b[N],n,k,m,he=1,ta,ans;
int main(){
	n=read();	k=read();	m=read();
	For(i,1,n){
		ll x=read();
		if (!ta||a[ta]!=x)	a[++ta]=x,b[ta]=1;
		else{
			++b[ta]%=k;
			while(ta&&!b[ta])--ta;
		}
	}
	For(i,1,ta)	ans+=b[i];
	while(he<ta&&a[he]==a[ta]){
		if (!((b[he]+b[ta])%k))	++he,--ta;
		else{	b[he]=(b[he]+b[ta])%k;	b[ta]=0;	break;	}
	}
	if (he<ta)	For(i,he,ta)	ans+=b[i]*(m-1);
	else	ans=(b[he]*m%k)?(ans-b[he]+b[he]*m%k):0;
	writeln(ans);
}