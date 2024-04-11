#include<queue>
#include<stdio.h>
#include<cstring>
#include<algorithm>
#include<vector>
#define ll int
#define maxn 200010
#define pa pair<ll,ll>
#define For(i,x,y)  for(ll i=x;i<=y;++i)
#define FOr(i,x,y)  for(ll i=x;i>=y;--i)
using namespace std;
inline ll read(){   ll x=0,f=1;char ch=getchar();   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}  while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  return x*f; } 
inline void write(ll x){    if (x<0) putchar('-'),x=-x; if (x>=10) write(x/10);   putchar(x%10+'0');  } 
inline void writeln(ll x){ write(x);   puts("");   }
ll head[maxn],nxt[maxn],vet[maxn],n,rt1,rt2,c[maxn],tot;
bool dfs(ll x,ll pre){
	for(ll i=head[x];i;i=nxt[i])
	if (vet[i]!=pre){
		if (dfs(vet[i],x))	return 1;
		if (c[vet[i]]!=c[x])	return 1;
	}return 0;
}
bool work(ll x){
	for(ll i=head[x];i;i=nxt[i])
	if (dfs(vet[i],x))	return 0;
	return 1;
}
void insert(ll x,ll y){	nxt[++tot]=head[x];	head[x]=tot;	vet[tot]=y;	}
int main(){
	n=read();
	For(i,2,n){
		ll x=read(),y=read();
		insert(x,y);	insert(y,x);
	}
	For(i,1,n)	c[i]=read();
	For(x,1,n)	for(ll i=head[x];i;i=nxt[i])if (c[vet[i]]!=c[x])	rt1=x,rt2=vet[i];
	if (!rt1){	puts("YES\n1");}
	else{
		if (work(rt1))	printf("YES\n%d",rt1);
		else if (work(rt2))	printf("YES\n%d",rt2);
		else	puts("NO");
	}
}