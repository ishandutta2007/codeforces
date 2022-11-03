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
	puts("");
}
ll mark[400005],next[400005],n,k,ans,f[400005],tot,vet[400005],head[400005];
ll min(ll x,ll y){
	return x<y?x:y;
} 
void insert(ll x,ll y){
	next[++tot]=head[x];	head[x]=tot;	vet[tot]=y;
}
void dfs(ll x,ll pre){
	f[x]+=mark[x];
	for (ll i=head[x];i;i=next[i]){
		ll v=vet[i];
		if (v==pre)	continue;
		dfs(v,x);
		f[x]+=f[v];
	}
	ans+=min(f[x],k*2-f[x]);
}
int main(){
	n=read();	k=read();
	for (ll i=1;i<=2*k;i++){
		ll x=read();
		mark[x]++;
	}
	for (ll i=1;i<n;i++){
		ll x=read(),y=read();
		insert(x,y);	insert(y,x);
	}
	dfs(1,-1);
	writeln(ans);
}