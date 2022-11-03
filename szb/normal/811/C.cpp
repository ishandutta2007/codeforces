#include<cstdio>
#include<algorithm>
#include<cmath>
#include<memory.h>
#include<map>
#define ll int
#define maxn 10100
#define For(i,j,k)  for(ll i=j;i<=k;++i)
#define FOr(i,j,k)  for(ll i=j;i>=k;--i)
using namespace std;
inline ll read(){ll x=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
inline void write(ll x){if (x<0) putchar('-'),x=-x;if (x>=10) write(x/10);putchar(x%10+'0');	}
inline void writeln(ll x){	write(x);	puts("");}
ll f[maxn],L[maxn],R[maxn],a[maxn],b[maxn],n;
int main(){
	n=read();
	For(i,0,5000)	L[i]=n+1,R[i]=0;
//	writeln(L[4]);writeln(R[4]);
	For(i,1,n)	a[i]=read(),L[a[i]]=min(L[a[i]],i),R[a[i]]=max(R[a[i]],i);
	For(i,1,n){
		f[i]=f[i-1];
		for(ll j=i,need=j,now=0;j;--j){
			if (R[a[j]]>i)	break;
			if (R[a[j]]==j)	now^=a[j];
			need=min(need,L[a[j]]);
			if (j==need)	f[i]=max(f[i],f[j-1]+now);
///			writeln(need);
		}
	//	writeln(f[i]);	puts(">>>>>>>>");
	}
	writeln(f[n]);
}