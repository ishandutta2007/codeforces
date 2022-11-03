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
#include<set>
#define ll int
#define For(i,j,k)  for(ll i=j;i<=k;++i)
#define FOr(i,j,k)  for(ll i=j;i>=k;--i)
#define ld double
using namespace std;
inline ll read(){   ll x=0,f=1;char ch=getchar();   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}  while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  return x*f; }
inline void wrote(ll x){    if (x<0) putchar('-'),x=-x; if (x>=10) wrote(x/10);   putchar(x%10+'0');  }
inline void writeln(ll x){ wrote(x);   puts("");   }
const ll N=400010;
vector<pair<ll,ll> >g[N];
priority_queue<pair<ll,ll> >Q;
ll head[N],nxt[N],vet[N],dfn[N],q[N],rk[N],mx[N],mn[N],n,m,k,top,tot=1;
inline void insert(ll x,ll y){	nxt[++tot]=head[x];	head[x]=tot;	vet[tot]=y;	}
int main(){
	n=read();	m=read();	k=read();
	For(i,1,n)	rk[i]=read(),mx[i]=rk[i]?rk[i]:k,mn[i]=rk[i]?rk[i]:1;
	For(i,1,m){	ll x=read(),y=read();	insert(x,y);	insert(y,x);	++dfn[y];	}
	For(i,1,n)	if (!dfn[i])	q[++top]=i;
	For(now,1,top)	for(ll i=head[q[now]];i;i=nxt[i])	if (i%2==0)	if (!--dfn[vet[i]])	q[++top]=vet[i];
	if (top!=n)	return puts("-1"),0;
	For(now,1,top)	for(ll i=head[q[now]];i;i=nxt[i])	if (i%2==0)	mx[vet[i]]=min(mx[vet[i]],mx[q[now]]-1);
	FOr(now,top,1)	for(ll i=head[q[now]];i;i=nxt[i])	if (i%2==1)	mn[vet[i]]=max(mn[vet[i]],mn[q[now]]+1);
	For(i,1,n)	if (mx[i]<mn[i])	return puts("-1"),0;	else	g[mx[i]].push_back(make_pair(mn[i],i));
	FOr(i,k,1){
		for(ll j=0;j<g[i].size();j++)	Q.push(g[i][j]);
		if (Q.empty())	return puts("-1"),0;
		rk[Q.top().second]=i;	Q.pop();
		while(!Q.empty()&&Q.top().first==i)	rk[Q.top().second]=i,Q.pop();
	}
	For(i,1,n)	printf("%d ",rk[i]);
}