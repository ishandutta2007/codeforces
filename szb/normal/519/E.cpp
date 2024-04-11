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
#define ll long long
#define inf 1000000000
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
void swap(ll &x,ll &y){
	ll t=x;	x=y;	y=t;
} 
ll next[200005],fa[100005][22],head[100005],vet[200005],val[200005],deep[100005],size[100005],tot,n,m;
void insert(ll x,ll y){
	next[++tot]=head[x];
	head[x]=tot;
	vet[tot]=y;
}
ll get(ll x,ll k){
	for (ll i=0;i<=21;i++)
	if ((1<<i)&k)	x=fa[x][i];
	return x;
}
void dfs(ll x){
	deep[x]=deep[fa[x][0]]+1;
	for (ll i=1;i<=21;i++){
		if ((1<<i)>=deep[x])	break;
		fa[x][i]=fa[fa[x][i-1]][i-1];
	}
	size[x]=1;
	for (ll i=head[x];i;i=next[i]){
		ll v=vet[i];
		if (v==fa[x][0])	continue;
		fa[v][0]=x;
		dfs(v);
		size[x]+=size[v];
	}
}
ll query(ll x,ll y){
	ll t=deep[x]-deep[y];
	for (ll i=0;i<=21;i++)
	if ((1<<i)&t)	x=fa[x][i];
	for (ll i=21;i>=0;i--)
	if (fa[x][i]!=fa[y][i])	x=fa[x][i],y=fa[y][i];
	if (x==y)	return x;
	return fa[x][0];
}
int main(){
	n=read();
	for (ll i=1;i<n;i++){
		ll x=read(),y=read();
		insert(x,y);
		insert(y,x);
	}
	dfs(1);
	m=read();
	while (m--){
		ll x=read(),y=read();
		if ((deep[x]+deep[y])%2)	writeln(0);
		else	if (x==y)			writeln(n);
		else{
			if (deep[x]<deep[y])	swap(x,y);
			ll p=query(x,y);
			if (deep[x]==deep[y])	writeln(n-size[get(x,deep[x]-deep[p]-1)]-size[get(y,deep[y]-deep[p]-1)]);
			else	writeln(size[get(x,(deep[x]+deep[y]-2*deep[p])/2)]-size[get(x,(deep[x]+deep[y]-2*deep[p])/2-1)]);
		}
	}
}