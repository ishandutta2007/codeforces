#include<queue>
#include<ctime>
#include<vector>
#include<cstdio>
#include<cstring>
#include<memory.h>
#include<algorithm>
#define ll int
#define For(i,j,k)  for(ll i=j;i<=k;++i)
#define FOr(i,j,k)  for(ll i=j;i>=k;--i)
#define F first
#define S second
using namespace std;
inline ll read(){   ll x=0,f=1;char ch=getchar();   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}  while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  return x*f; }
inline void wrote(ll x){    if (x<0) putchar('-'),x=-x; if (x>=10) wrote(x/10);   putchar(x%10+'0');  }
inline void writeln(ll x){ wrote(x);   puts("");   }
const ll N=400;
vector<ll>g[N];
ll h,n,sz,vis[N],dep[N];
void query(ll x){	printf("? %d\n",x);	fflush(stdout);	++sz;	}
void print(ll x){	printf("! %d\n",x);	fflush(stdout);	}
ll input(ll x){
	ll k=read();
	For(i,1,k){
		ll y=read();
		if (!vis[y])	g[x].push_back(y),g[y].push_back(x);
	}vis[x]=1;	return k;
}
ll dfs(ll x){
	while(1){
		ll pre=x;
		for(ll i=0;i<g[x].size();i++)
		if (!vis[g[x][i]]){	x=g[x][i];	break;	}
		if (x==pre)	return 0;
		query(x);	ll now=input(x);	if (now==2)	return x;
		if (now==1)	return dep[x]=h,0;
	}
}
ll change_dep(){
	ll q[N],nn[N];
	ll l=0,r=0;	memset(nn,0,sizeof nn);	ll tim=0;
	For(i,1,n)	if (dep[i]==h)	nn[q[++r]=i]=1;
	while(l!=r){
		ll x=q[++l];
		for(ll i=0;i<g[x].size();i++)
		if (!nn[g[x][i]]&&vis[g[x][i]]){
			nn[g[x][i]]=1;
			dep[g[x][i]]=dep[x]-1;
			q[++r]=g[x][i];
		}
	}return q[r];
}
ll end(ll x){
	ll q[N];
	ll l=0,r=0;	q[++r]=x;
	while(l!=r){
		ll x=q[++l];
		for(ll i=0;i<g[x].size();i++)
		if (!vis[g[x][i]]){
			if (sz==16)	return g[x][i];
			query(q[++r]=g[x][i]);	if (input(q[r])==2)	return q[r];
		}
	}
}
ll work(){
	h=read();	n=(1<<h)-1;	query(1);	ll tt=input(1);	if (tt==2)	return 1;
	if (tt==3){
		ll a=dfs(1);	if (a)	return a;
		a=dfs(1);		if (a)	return a;
	}else	dep[1]=h;	ll tim=0;
	while(1){
		ll mn=change_dep();
		if (dep[mn]==1)	return mn;
		if (dep[mn]<=4)	return end(mn);
		else{	ll hh=(dfs(mn));	if (hh)	return hh;	}
	}
}
int main(){
	ll T=read();
	while(T--){
		print(work());
		//writeln(work());
		For(i,0,N-1)	g[i].clear();	sz=0;
		memset(vis,0,sizeof vis);
		memset(dep,0,sizeof dep);
//		if (T==5)	return 0;
	}
}