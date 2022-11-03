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
const ll N=1010;
vector<ll>g[N];
ll f[N],h[N],n,T;
int main(){
//	freopen("shenzhebei.in","r",stdin);
	n=read();	T=read();
	For(i,1,n){
		ll sgr=read();
		g[T-sgr].push_back(read());
	}
	f[0]=0;
	FOr(tim,T-1,0){
		memcpy(h,f,sizeof f);
		For(i,0,n)	f[i]=max(h[i*2],h[i*2-1]);
		for(ll i=0;i<g[tim].size();i++)	FOr(j,n,1)	f[j]=max(f[j],f[j-1]+g[tim][i]);
	}writeln(f[1]);
}
/*
n1000T100tiqi


1.
2.ti<=T

*/