#include<cstdio>
#include<memory.h>
#include<algorithm>
using namespace std;
#define ll long long
#define For(i,x,y)  for(ll i=x;i<=y;++i)
#define FOr(i,x,y)  for(ll i=x;i>=y;--i)
ll read(){  ll x=0,f=0; char ch=getchar();  while(ch<'0'||ch>'9'){ if(ch=='-') f=1; ch=getchar(); }   while(ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0', ch=getchar(); return f?-x:x;}
void write(ll x){   if (x<0) x=-x,putchar('-');  if (x>=10)   write(x/10);    putchar(x%10+'0');}
void writeln(ll x)  {   write(x);   puts("");   }
ll n,l,m,lsg,b1[2000000],b2[2000000],b[200],a[200][200],f[200][200],fff[200][200],ff[200],ans,x;
void chen(ll a[200][200]){
		memset(fff,0,sizeof(fff));
		for (ll k=0;k<m;k++)
			for (ll j=0;j<m;j++)
				if (f[k][j])
				for (ll i=0;i<m;i++)
					fff[i][j]=(fff[i][j]+a[i][k]*f[k][j])%lsg;
		for (ll i=0;i<m;i++)
			for (ll j=0;j<m;j++)f[i][j]=fff[i][j];
	}
void ksm(ll x){
		if (x==0){
			memset(f,0,sizeof(f));
			for (ll i=0;i<m;i++)f[i][i]=1;
			return;
		}
		if (x==1)return;
		ksm(x/2);chen(f);if (x&1)chen(a);
	}
signed main(){
	n=read();	l=read();	m=read();
	lsg=1e9+7;
	for (ll i=1;i<=n;i++)	b1[i]=read();
	for (ll i=1;i<=n;i++){
			x=read();b2[i]+=x;
			for (ll j=0;j<m;j++)f[j][(j+x)%m]++;
		}
	for (ll i=1;i<=n;i++)x=read(),b2[i]+=x;
	for (ll i=0;i<m;i++)for (ll j=0;j<m;j++)a[i][j]=f[i][j];
	ksm(l-2);for (ll i=1;i<=n;i++)b[b1[i]%m]++;
	for (ll i=0;i<m;i++)
		for (ll j=0;j<m;j++)(ff[j]+=f[i][j]*b[i])%=lsg;
	for (ll i=1;i<=n;i++)(ans+=ff[(m-b2[i]%m)%m])%=lsg;
	writeln(ans);
}