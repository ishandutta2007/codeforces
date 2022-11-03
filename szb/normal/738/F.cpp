#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<map>
#include<vector>
#include<string>
#define ll int
#define lf else if
#define For(i,x,y)  for(ll i=x;i<=y;++i)
#define FOr(i,x,y)  for(ll i=x;i>=y;--i)
using namespace std;
inline ll read(){   ll x=0,f=1;char ch=getchar();   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}  while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  return x*f; } 
inline void write(ll x){    if (x<0) putchar('-'),x=-x; if (x>=10) write(x/10);   putchar(x%10+'0');  } 
inline void writeln(ll x){ write(x);   puts("");   }
ll f[90][2][4010][90];
ll sum[4010],n;
bool vis[90][2][4010][90];
inline ll calc(ll l,ll r){	return sum[r]-sum[l-1];	}
ll work(ll l,ll r,ll p,bool id){
	if (r-l+1<p)	return 0;
	if (vis[p][id][l][abs(r-l)])	return f[p][id][l][abs(r-l)];
	vis[p][id][l][abs(r-l)]=1;
	if (id==0){
		if (r-l+1==p)	f[p][id][l][abs(r-l)]=sum[r]-sum[l-1];
		else	f[p][id][l][abs(r-l)]=max(work(l+p,r,p,id^1)+calc(l,l+p-1),
								   work(l+p+1,r,p+1,id^1)+calc(l,l+p));
	}else{
		if (r-l+1==p)	f[p][id][l][abs(r-l)]=sum[l-1]-sum[r];
		else	f[p][id][l][abs(r-l)]=min(work(l,r-p,p,id^1)-calc(r-p+1,r),work(l,r-p-1,p+1,id^1)-calc(r-p,r));
	}
	return f[p][id][l][abs(r-l)];
}
int main(){
//	freopen("shenzhebei.in","r",stdin);
	n=read();
	For(i,1,n)	sum[i]=sum[i-1]+read();
	writeln(work(1,n,1,0));
}
// 12kkk+1IZ