#include<queue>
#include<ctime>
#include<vector>
#include<cstdio>
#include<cstring>
#include<memory.h>
#include<map>
#include<ctime>
#include<algorithm>
#define ll long long
#define For(i,j,k)  for(ll i=j;i<=k;++i)
#define FOr(i,j,k)  for(ll i=j;i>=k;--i)
#define F first
#define S second
using namespace std;
inline ll read(){   ll x=0,f=1;char ch=getchar();   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}  while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  return x*f; }
inline void wrote(ll x){    if (x<0) putchar('-'),x=-x; if (x>=10) wrote(x/10);   putchar(x%10+'0');  }
inline void writeln(ll x){ wrote(x);   puts("");   }
const ll maxn=1e6+7;
ll ans=1LL<<60,f[maxn][3],p[maxn],n,A,B;
void calc(ll x){
	ll w;
	For(i,1,n){
		if (p[i]%x==0)	w=0;
		else if (((p[i]+1)%x==0)||((p[i]-1)%x==0))	w=B;
		else	w=1LL<<35;
		f[i][0]=f[i-1][0]+w;
		f[i][1]=min(f[i-1][0],f[i-1][1])+A;
		f[i][2]=min(f[i-1][1],f[i-1][2])+w;
	}
	ans=min(ans,min(f[n][0],min(f[n][1],f[n][2])));
}
void push(ll x){
	if (x==1)	return;
	for(ll i=2;i*i<=x;i++)
	if (!(x%i)){
		calc(i);
		while(!(x%i))	x/=i;
		if (x==1)	break;
	}
	if (x>1)	calc(x);
}
int main(){
//	freopen("a.in","r",stdin);
	n=read();	A=read();	B=read();
	For(i,1,n)	p[i]=read();
	push(p[1]-1);
	push(p[1]);
	push(p[1]+1);
	push(p[n]-1);
	push(p[n]);
	push(p[n]+1);
	writeln(ans);
}