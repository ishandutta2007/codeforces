#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define rep(i,x,y)  for(ll i=x;i<y;++i)
#define For(i,x,y)  for(ll i=x;i<=y;++i) 
#define FOr(i,x,y)  for(ll i=x;i>=y;--i) 
ll read(){  ll x=0,f=1; char ch=getchar();  for(;ch<'0'||ch>'9';ch=getchar()) if (ch=='-')    f=-1;   for(;ch>='0'&&ch<='9';ch=getchar())   x=x*10+ch-'0';  return x*f; } 
void write(ll x){   if (x<0) putchar('-'),x=-x;  if (x>=10)   write(x/10);    putchar(x%10+'0');  } 
void writeln(ll x){ write(x);   puts("");   }
const ll N=2010,mod=1e9+7;
ll los[N],win[N],n,K,f[N][N],g[N][N];	char s[N];
void add(ll &x,ll y){	x=(x+y)%mod;	}
int main(){//0,1 
//	freopen("s.in","r",stdin);
	n=read();	K=read();	scanf("%s",s+1);
	f[0][0]=g[0][0]=1;
	For(i,1,n)	los[i]=s[i]-'a',
				win[i]='z'-s[i];los[n]++;
	For(i,1,n)	For(k,0,K){
		for(ll j=i-1;(k>=(i-j)*(n-i+1))&&(j>=0);--j)
		add(f[i][k],f[j][k-(i-j)*(n-i+1)]*win[i]);
		add(f[i][k],g[i-1][k]*los[i]);
		g[i][k]=(f[i][k]+g[i-1][k])%mod;
	}writeln(f[n][K]);
}
/*
2 2
yz
*/