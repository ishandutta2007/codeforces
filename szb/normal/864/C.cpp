#include<queue>
#include<stdio.h>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>
#define ll long long
#define maxn 200010
#define pa pair<ll,ll>
#define For(i,x,y)  for(ll i=x;i<=y;++i)
#define FOr(i,x,y)  for(ll i=x;i>=y;--i)
using namespace std;
inline ll read(){   ll x=0,f=1;char ch=getchar();   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}  while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  return x*f; } 
inline void write(ll x){    if (x<0) putchar('-'),x=-x; if (x>=10) write(x/10);   putchar(x%10+'0');  } 
inline void writeln(ll x){ write(x);   puts("");   }
ll a,b,f,k,ans,sum;
void print(){	puts("-1");	exit(0);	}
int main(){
	a=read();	b=read();	f=read();	k=read();	ans=0;	sum=0;
	if (k==1)	if (max(f,a-f)>b)	return puts("-1"),0;
	if (k==2)	if (max(2*(a-f),f)>b)	return puts("-1"),0;
	if (k>=3)	if (max(2*(a-f),2*f)>b)	return puts("-1"),0;
	For(i,1,k){
		if (i&1){
			sum+=f;
			if (sum>b)	sum=f*2,ans++;
			sum+=a-f;
		}else{
			sum+=a-f;
			if (sum>b)	sum=2*(a-f),ans++;
			sum+=f;
		}
	}
	writeln(ans+(sum>b));
}