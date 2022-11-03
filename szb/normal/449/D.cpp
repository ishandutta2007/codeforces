#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define ll long long
#define For(i,x,y)	for(ll i=x;i<=y;++i)
#define FOr(i,x,y)	for(ll i=x;i>=y;--i)
using namespace std;
inline ll read(){	char ch=getchar();	ll x=0,f=1;	for(;ch<'0'||ch>'9';ch=getchar())	if (ch=='-')	f=-1;	for(;ch>='0'&&ch<='9';ch=getchar())	x=x*10+ch-'0';	return x*f;	}
inline void write(ll x){	if (x>9)	write(x/10);	putchar(x%10+'0');	}
inline void writeln(ll x){	write(x);	puts("");	}
const ll N=1090000,mod=1e9+7;
ll n,f[N],bin[N],ans,ct[N];
int main(){
	n=read();
	For(i,1,n)	f[read()]++;
	For(i,0,19)	For(j,0,(1<<20)-1)	if (!(j>>i&1))	f[j]+=f[j|(1<<i)];
	ct[0]=1;
	For(i,1,(1<<20)-1)	ct[i]=-ct[i-(i&-i)];
	bin[0]=1;
	For(i,1,(1<<20)-1)	bin[i]=bin[i-1]*2%mod;
	For(i,0,(1<<20)-1)	if (f[i])	ans+=ct[i]*(bin[f[i]]-1);//1 
	writeln((ans%mod+mod)%mod);
}
/*
*/