#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<map>
#include<vector>
#include<string>
#define ll long long
#define lf else if
#define For(i,x,y)  for(ll i=x;i<=y;++i)
#define FOr(i,x,y)  for(ll i=x;i>=y;--i)
using namespace std;
inline ll read(){   ll x=0,f=1;char ch=getchar();   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}  while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  return x*f; } 
inline void write(ll x){    if (x<0) putchar('-'),x=-x; if (x>=10) write(x/10);   putchar(x%10+'0');  } 
inline void writeln(ll x){ write(x);   puts("");   }
const ll N=1000010,bas=37,mod=998244353;
ll n,bin[N],a[N],b[N],c,d;
char s1[N],s2[N];
ll get(char ch){
	if (ch=='N')	return 0;
	if (ch=='S')	return 3;
	if (ch=='W')	return 1;
	return 2;
}
int main(){
//	freopen("shenzhebei.in","r",stdin);
	n=read()-1;	scanf("%s%s",s1+1,s2+1);
	For(i,1,n)	a[i]=3-get(s1[i]),b[i]=get(s2[i]);
	bin[0]=1;	For(i,1,n)	bin[i]=bin[i-1]*bas%mod;
	FOr(i,n,1){
		c=(c*bas+a[i])%mod;
		d=(d+bin[n-i]*b[i])%mod;
		if (c==d)	return puts("NO");
	}puts("YES");
}