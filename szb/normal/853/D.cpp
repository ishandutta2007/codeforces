#include<bits/stdc++.h>
#define ll long long
#define FOr(i,x,y)  for(ll i=x;i>=y;--i)
#define For(i,x,y)	for(ll i=x;i<=y;++i)
using namespace std;
namespace SHENZHEBEI{
#ifdef LOCAL
	struct szb{	szb(){	freopen("shenzhebei.in","r",stdin);	}	}shenzhebei;
#endif
#define NEG 1
	const int L=2333333;
	char SZB[L],*S=SZB,*T=SZB;
	inline char gc(){	if (S==T){	T=(S=SZB)+fread(SZB,1,L,stdin);	if (S==T) return '\n';	}	return *S++;	}
#if NEG
	inline ll readint(){	ll x=0,f=1;	char ch=gc();	for (;!isdigit(ch);ch=gc())	if (ch=='-') f=-1;	for (;isdigit(ch);ch=gc())	x=x*10-48+ch;	return x*f;	}
	inline void write(ll x){	if (x<0)	putchar('-'),x=-x;	if (x>=10)	write(x/10);	putchar(x%10+'0');	}
#else
	inline ll readint(){	ll x=0;	char ch=gc();	for (;!isdigit(ch);ch=gc());	for (;isdigit(ch);ch=gc())	x=x*10-48+ch;	return x;	}
	inline void write(ll x){	if (x>=10)	write(x/10);	putchar(x%10+'0');	}
#endif
	inline char readchar(){	char ch=gc();	for(;isspace(ch);ch=gc());	return ch;	}
	inline ll readstr(char *s){	char ch=gc();	int cur=0;	for(;isspace(ch);ch=gc());		for(;!isspace(ch);ch=gc())	s[cur++]=ch;	s[cur]='\0';	return cur;	}
	inline void writeln(ll x){	write(x);	puts("");	}
}using namespace SHENZHEBEI;
ll f[300010][50],a[300010],n,ans;
void add(ll &x,ll y){	x=min(x,y);	}
int main(){
	n=readint();
	For(i,1,n)	a[i]=readint()/100;
	memset(f,60,sizeof f);
	f[0][0]=0;
	For(i,1,n)	For(j,0,40){
		add(f[i][j+a[i]/10],f[i-1][j]+a[i]);
		if (j>=a[i])	add(f[i][j-a[i]],f[i-1][j]);
		else	add(f[i][0],f[i-1][j]+a[i]-j);
	}ans=f[n+1][0];
	For(i,0,40)	ans=min(ans,f[n][i]);
	writeln(ans*100); 
}