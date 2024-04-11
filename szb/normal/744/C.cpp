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
ll opt[30],r[30],b[30],ans1,ans2,f[1<<16|111][400],sum[1<<16|111][2],n,answ=1e18;	char s[10];
void add(ll &x,ll y){	x=min(x,y);	}
void Add(ll &x,ll y){	x=max(x,y);	}
int main(){
//	freopen("shenzhebei.in","r",stdin);
	n=read();
	For(i,0,n-1){
		scanf("%s",s);
		if (s[0]=='R')	opt[i]=0,r[i]=read(),b[i]=read();
		else			opt[i]=1,r[i]=read(),b[i]=read();
		ans1+=r[i];	ans2+=b[i];
	}
	For(S,0,(1<<n)-1)	For(i,0,n-1)	if (S>>i&1)	sum[S][opt[i]]++;
	memset(f,-60,sizeof f);
	f[0][0]=0;
	For(S,0,(1<<n)-1)	For(i,0,n-1)	if (!(S>>i&1))
	For(red,0,n*n)	Add(f[S^(1<<i)][red+min(r[i],sum[S][0])],f[S][red]+min(b[i],sum[S][1]));
	For(i,0,n*n)	add(answ,max(ans1-i,ans2-f[(1<<n)-1][i]));
	writeln(answ+n);
}