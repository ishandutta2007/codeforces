#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<queue>
#include<map>
#include<set>
#include<queue>
#include<cmath>
#include<memory.h>
#include<bitset>
#define ll int
//using namespace std;
inline ll read(){
	ll x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
inline void write(ll x){
	if (x<0) putchar('-'),x=-x;
    if (x>=10) write(x/10);
    putchar(x%10+'0');
}
void writeln(ll x){
	write(x);
	printf("\n");
}
ll next[600010],head[300010],vet[600010],tot,ans[300010],size[300010],fa[300010],n,q;
void insert(ll x,ll y){
	next[++tot]=head[x];	head[x]=tot;	vet[tot]=y;
}
void dfs(ll x){
	size[x]=1;
	ans[x]=x;
	for (ll i=head[x];i;i=next[i]){
		ll v=vet[i];
		dfs(v);
		size[x]+=size[v];
	}
	for (ll i=head[x];i;i=next[i]){
		ll v=vet[i];
		if (size[v]*2>size[x])	ans[x]=ans[v];
	}
	while ((size[x]-size[ans[x]])*2>size[x])	ans[x]=fa[ans[x]];
}
int main(){
	n=read(),q=read();
	for (ll i=2;i<=n;i++){
		fa[i]=read();
		insert(fa[i],i);
	}
	dfs(1);
	while (q--){
		ll x=read();
		writeln(ans[x]);
	}
}