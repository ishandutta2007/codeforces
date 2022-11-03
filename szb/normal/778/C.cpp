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
#define ll int
#define For(i,j,k)  for(ll i=j;i<=k;++i)
#define FOr(i,j,k)  for(ll i=j;i>=k;--i)
#define ld double
using namespace std;
inline ll read(){   ll x=0,f=1;char ch=getchar();   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}  while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  return x*f; }
inline void wrote(ll x){    if (x<0) putchar('-'),x=-x; if (x>=10) wrote(x/10);   putchar(x%10+'0');  }
inline void writeln(ll x){ wrote(x);   puts("");   }
const ll N=300010;	char s[10];
struct data{	ll x,y;	}q[N];
ll to[N*2][30];
ll dep[N],pre[N],sz[N],n,clk,del,sum,son[N],answ[N],answ_now,cho,tt;
void merge(ll x,ll y){
	For(i,0,25)	if (to[y][i]){
		if (to[x][i])	++del,merge(to[x][i],to[y][i]);
		else{	to[x][i]=to[y][i];	q[++tt].x=x;	q[tt].y=i;	}
	}
}
void dfs(ll x){
	dep[x]=dep[pre[x]]+1;	sz[x]=1;	sum=max(sum,dep[x]);	answ[dep[x]-1]++;
	For(i,0,25)if (to[x][i]){
		pre[to[x][i]]=x,dfs(to[x][i]),sz[x]+=sz[to[x][i]];
		if (sz[to[x][i]]>sz[son[x]])	son[x]=to[x][i];
	}if (!son[x])	return;
	del=0;	++clk;
	For(i,0,25)	if (to[x][i]&&to[x][i]!=son[x])	merge(son[x],to[x][i]);
	answ[dep[x]]+=del;
	For(i,1,tt)	to[q[i].x][q[i].y]=0;
	tt=0;
}
int main(){
//	freopen("a.in","r",stdin);
	n=read();
	For(i,2,n){
		ll x=read(),y=read();	scanf("%s",s);
		to[x][s[0]-'a']=y;
	}dfs(1);
	For(i,1,sum)	if (answ[i]>answ_now)	answ_now=answ[i],cho=i;
	writeln(n-answ_now);
	writeln(cho);
}