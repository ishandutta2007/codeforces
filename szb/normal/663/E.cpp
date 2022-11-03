#include<queue>
#include<ctime>
#include<vector>
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<memory.h>
#include<map>
#include<ctime>
#include<algorithm>
#include<ctime>
#include<set>
#define ll int
#define For(i,j,k)  for(ll i=j;i<=k;++i)
#define FOr(i,j,k)  for(ll i=j;i>=k;--i)
#define ld double
#define fi first
#define se second
using namespace std;
inline ll read(){   ll x=0,f=1;char ch=getchar();   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}  while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  return x*f; }
inline void wrote(ll x){    if (x<0) putchar('-'),x=-x; if (x>=10) wrote(x/10);   putchar(x%10+'0');  }
inline void writeln(ll x){ wrote(x);   puts("");   }
const ll N=20;
ll answ,n,m,f[N+1][(1<<N)|111],all;
char s[21][100010];
int main(){
	n=read();	m=read();
	For(i,1,n)	scanf("%s",s[i]+1);
	For(i,1,m){
		ll sz=0;
		For(j,1,n)	sz=sz<<1|(s[j][i]-'0');
		f[0][sz]++;
	}
	all=(1<<n)-1;
	For(v,0,n-1)	FOr(k,n-1,0)	For(l,0,all)	f[k+1][l^(1<<v)]+=f[k][l];
	answ=n*m;
	For(v,0,all){
		ll ans=0;
		For(k,0,n)	ans+=min(k,n-k)*f[k][v];
		answ=min(answ,ans);
	}writeln(answ);
}