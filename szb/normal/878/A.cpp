#include<bits/stdc++.h>
#define ll long long
#define FOr(i,x,y)  for(ll i=x;i>=y;--i)
#define For(i,x,y)	for(ll i=x;i<=y;++i)
using namespace std;
namespace SHENZHEBEI{
#define NEG 1
	const int L=2333333;
	char SZB[L],*S=SZB,*T=SZB;
	inline char gc(){	if (S==T){	T=(S=SZB)+fread(SZB,1,L,stdin);	if (S==T) return '\n';	}	return *S++;	}
#if NEG
	inline ll read(){	ll x=0,f=1;	char ch=gc();	for (;!isdigit(ch);ch=gc())	if (ch=='-') f=-1;	for (;isdigit(ch);ch=gc())	x=x*10-48+ch;	return x*f;	}
	inline void write(ll x){	if (x<0)	putchar('-'),x=-x;	if (x>=10)	write(x/10);	putchar(x%10+'0');	}
#else
	inline ll read(){	ll x=0;	char ch=gc();	for (;!isdigit(ch);ch=gc());	for (;isdigit(ch);ch=gc())	x=x*10-48+ch;	return x;	}
	inline void write(ll x){	if (x>=10)	write(x/10);	putchar(x%10+'0');	}
#endif
	inline char readchar(){	char ch=gc();	for(;isspace(ch);ch=gc());	return ch;	}
	inline int readstr(char *s){	char ch=gc();	int cur=0;	for(;isspace(ch);ch=gc());		for(;!isspace(ch);ch=gc())	s[cur++]=ch;	s[cur]='\0';	return cur;	}
	inline void writeln(ll x){	write(x);	puts("");	}
}using namespace SHENZHEBEI;
const ll N=500010;
ll cur[N][11],n,a1,a2,a3;
int main(){
	n=read();	For(i,0,9)	cur[i][0]=0,cur[i][1]=1;
	For(i,1,n){
		char ch[10]; readstr(ch);	ll x=read();
		For(j,0,9){
			ll t=x>>j&1;
			if (ch[0]=='|'){	cur[j][0]|=t;	cur[j][1]|=t;	}
			if (ch[0]=='^'){	cur[j][0]^=t;	cur[j][1]^=t;	}
			if (ch[0]=='&'){	cur[j][0]&=t;	cur[j][1]&=t;	}
		}
	}
	a1=1023;
	For(i,0,9){
		if (cur[i][0]==0&&cur[i][1]==0)	a1^=1<<i;
		if (cur[i][0]==1&&cur[i][1]==1)	a2^=1<<i;
		if (cur[i][0]==1&&cur[i][1]==0)	a3^=1<<i;
	}writeln(3);
	printf("& ");	writeln(a1);
	printf("| ");	writeln(a2);
	printf("^ ");	writeln(a3);
}
/*
a1 &
a2 |
a3 ^
*/