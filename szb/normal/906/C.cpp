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
inline ll read(){  ll x=0; char ch=getchar();  while(ch<'0'||ch>'9') ch=getchar();  while(ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0', ch=getchar(); return x;}
void write(ll x){   if (x<0) x=-x,putchar('-');  if (x>=10)   write(x/10);    putchar(x%10+'0');}
inline void writeln(ll x)  {   write(x);   puts("");   }
ll f[100],g[1<<22|111],n,m,pre[1<<22|111],cho[1<<22|111],q[100],top;
int main(){
	n=read();	m=read();
	For(i,1,n)	f[i]|=1<<i-1;
	For(i,1,m){
		ll x=read(),y=read();
		f[x]|=1<<y-1;	f[y]|=1<<x-1;
	}ll all=(1<<n)-1;
	For(i,1,all){
		bool fl=1;
		For(j,1,n)
			fl&=!(i>>(j-1)&1)||((f[j]&i)==i);
		g[i]=fl?0:1e9+7;
	}
	For(i,1,all)	For(j,1,n)	if ((i>>(j-1)&1)&&(g[i|f[j]]>g[i]+1))	g[i|f[j]]=g[i]+1,pre[i|f[j]]=i,cho[i|f[j]]=j;
	writeln(g[all]);
	while(cho[all])	q[++top]=cho[all],all=pre[all];
	while(top)	printf("%I64d ",q[top--]);
}