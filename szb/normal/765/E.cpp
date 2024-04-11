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
set<ll>s[N];
ll vis[N],dfn[N],head[N],nxt[N],vet[N],q[N],he,ta,n,tot,ans;
void insert(ll x,ll y){	nxt[++tot]=head[x];	head[x]=tot;	vet[tot]=y;	++dfn[x];	}
int main(){
	n=read();
	For(i,2,n){
		ll x=read(),y=read();
		insert(x,y);	insert(y,x);
	}
	For(i,1,n)	if (1==dfn[i])	q[++ta]=i,s[i].insert(0);
	while(he!=ta){
		ll x=q[++he];	vis[x]=1;
		for(ll i=head[x];i;i=nxt[i])
		if (!vis[vet[i]]){
			--dfn[vet[i]];
			s[vet[i]].insert(*s[x].begin()+1);
			if (dfn[vet[i]]==1&&s[vet[i]].size()==1)	q[++ta]=vet[i];
		}
	}ll sz=0;
	For(i,1,n){
		if (s[i].size()==0||s[i].size()>2)	return puts("-1"),0;
		if (s[i].size()==1)	ans=max(ans,*s[i].begin());
		if (s[i].size()==2)	ans=max(ans,*s[i].begin()+*s[i].rbegin()),++sz;
	}
	if (sz>1)	return puts("-1"),0;
	while(!(ans&1))	ans>>=1;
	writeln(ans);
}