/*
------------
|SHENZHEBEI|
------------
------------
|SHENZHEBEI|
------------
------------
|SHENZHEBEI|
------------
*/
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#include<ctime>
#include<map>
using namespace std;
#define ll int
#define For(i,x,y)  for(ll i=x;i<=y;++i)
#define FOr(i,x,y)  for(ll i=x;i>=y;--i)
ll read(){  ll x=0,f=0; char ch=getchar();  while(ch<'0'||ch>'9'){ if(ch=='-') f=1; ch=getchar(); }   while(ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0', ch=getchar(); return f?-x:x;}
void write(ll x){   if (x<0) x=-x,putchar('-');  if (x>=10)   write(x/10);    putchar(x%10+'0');}
void writeln(ll x)  {   write(x);   puts("");   }
const ll N=200010;
ll d[N],g[N],n,a,b,c,del[N],sz[10],ans;
void clear(){
	ll nn=0;
	For(i,1,n)	if (!del[i])	g[++nn]=d[i];
	n=nn;	memcpy(d,g,sizeof g);
	memset(del,0,sizeof del);
}
bool calc(ll x){
	memset(del,0,sizeof del);
	ll tim=x+sz[3];
	FOr(i,n,1)	if (tim&&(d[i]<=c))	del[i]=1,tim--;
	x=x+sz[4];
	FOr(i,n,1)	if (!del[i]&&(d[i]>b)){
		if (d[i]>a+b)	return 0;
		del[i]=1;
		x--;
	}if (x<0)	return 0;
	ll A=x+sz[1],B=x+sz[2];
	For(i,1,n)	if (!del[i]){
		if (d[i]<=a&&A)	--A;
		else	--B;
	}return B>=0;
}
int main(){
//	freopen("applese.in","r",stdin);
	n=read();
	a=read();	b=read();	c=read();
	if (a>b)	swap(a,b);
	if (a>c)	swap(a,c);
	if (b>c)	swap(b,c);
	For(i,1,n){
		d[i]=read();
		if (d[i]>a+b+c)	return puts("-1"),0;
		if (d[i]>b+c){
			--i,--n,++ans;
			continue;
		}
		if (d[i]>c+a){
			sz[1]++;
			--i,--n,++ans;
			continue;
		}
		if (d[i]>a+b){
			if (d[i]<=c){
				sz[3]--;
				--i,--n;
				continue;
			}
			sz[2]++;
			--i,--n,++ans;
			continue;
		}
		if (d[i]>c){
			sz[3]++;
			--i,--n,++ans;
		}
	}
//	For(i,1,n)	writeln(d[i]);
	sort(d+1,d+n+1);
	while((sz[3]<0))	ans++,sz[4]++,sz[3]++;
	clear();
	ll l=0,r=n,now=0;
	while(l<=r){
		ll mid=(l+r)>>1;
		if (calc(mid))	now=mid,r=mid-1;
		else	l=mid+1;
	}writeln(now+ans);
}
//,ab,a,b,c
//,c,ab,a,b,
//