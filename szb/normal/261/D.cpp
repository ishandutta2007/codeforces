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
const ll N=100010;
ll f[N],a[N],T,n,maxb,t,ans;
int main(){
	T=read();	n=read();	maxb=read();	t=min(maxb+1,min(n+1,read()));
	while(T--){
		For(i,1,n)	a[i]=read();	ans=0;
		memset(f,0,sizeof f);
		For(i,1,n*t){
			ll x=a[(i-1)%n+1];
			if (!f[x]){
				f[x]=1;	++x;
				while(!f[x]&&x<=maxb)	++x;	f[x]=0;
			}
		}
		For(i,1,maxb)	ans+=f[i];
		writeln(ans);
	}
}