#include<ctime>
#include<algorithm>
#include<cstdio>
#include<set>
#include<memory.h>
#include<queue>
#include<cmath>
using namespace std;
#define ll long long
#define For(i,x,y)  for(int i=x;i<=y;++i)
#define FOr(i,x,y)  for(int i=x;i>=y;--i)
inline ll read(){  ll x=0,f=0; char ch=getchar();  while(ch<'0'||ch>'9'){ if(ch=='-') f=1; ch=getchar(); }   while(ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0', ch=getchar(); return f?-x:x;}
void write(ll x){   if (x<0) x=-x,putchar('-');  if (x>=10)   write(x/10);    putchar(x%10+'0');}
inline void writeln(ll x)  {   write(x);   puts("");   }
const ll N=200010;
ll s[N],g[N],answ[N],n,mn[N],mx[N],sum;
int main(){
	n=read();
	For(i,1,n)	s[i]=read(),g[i]=read();
	mn[0]=-1;	mx[0]=2000010;
	For(i,1,n){
		mn[i]=max(mn[i-1]-1,s[i]);
		mx[i]=min(mx[i-1]+1,s[i]+g[i]);
		sum-=s[i];
		if (mn[i]>mx[i])	return puts("-1"),0;
	}answ[n]=mx[n];	sum+=mx[n];
	FOr(i,n-1,1){
		answ[i]=min(answ[i+1]+1,mx[i]);
		sum+=answ[i];
	}
	writeln(sum);
	For(i,1,n)	printf("%lld ",answ[i]);
}