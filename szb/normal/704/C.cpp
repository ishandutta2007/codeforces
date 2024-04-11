#include<cstdio>
#include<memory.h>
#include<map>
#include<algorithm>
#include<queue>
#define ll long long
#define For(i,x,y)  for(ll i=x;i<=y;++i)
#define FOr(i,x,y)  for(ll i=x;i>=y;--i)
using namespace std;
inline ll read(){   ll x=0,f=1;char ch=getchar();   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}  while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  return x*f; }
inline void write(ll x){    if (x<0) putchar('-'),x=-x; if (x>=10) write(x/10);   putchar(x%10+'0');  }
void writeln(ll x){ write(x);   puts("");   }
const ll mod=1e9+7,N=100010,M=200010;
struct data{	ll m[2][2];		}f[N],tmp;
struct dt{		ll m[2][2][2];	}g[N],Tmp;
ll jzq[M][2],q1[M],q2[M],cont[M],head[M],sz[M],nxt[M],vet[M],I[M],you[M],fa[M],tot=1,t1,t2,all[2],rt,n,m;	bool vis[M],join[M],in[M],fl;
void insert(ll x,ll y,ll a,ll b){	nxt[++tot]=head[x];	head[x]=tot;	vet[tot]=y;	I[tot]=a;	you[tot]=b;	sz[x]++;	}
void Dfs(ll x){
	//writeln(x);
	vis[x]=1;	bool bl=0;
	if (sz[x]<=1)	q1[++t1]=x;	map<ll,bool>mp;
	for(ll i=head[x];i;){
		if (!bl&&vet[i]==fa[x]){	bl=1;	i=nxt[i];	continue;	}
		if (mp[vet[i]]){	i=nxt[i];	continue;	}	mp[vet[i]]=1;
		if (vis[vet[i]]){
			fl=1;
			for(ll t=x;t!=vet[i];t=fa[t])	q2[++t2]=t,in[t]=1;
			q2[++t2]=vet[i];	in[vet[i]]=1;	fa[vet[i]]=x;
		}else	fa[vet[i]]=x,Dfs(vet[i]);
		i=nxt[i];
	}
}
void add(ll &x,ll y){	x=(x+y)%mod;	}
data merge(data a,data b,ll x,ll y){
	memset(tmp.m,0,sizeof tmp.m);
	For(a1,0,1)	For(a2,0,1)	For(b1,0,1)	For(b2,0,1)
	add(tmp.m[((a2^x)||(b2^y))^a1^b1][a2],a.m[a1][a2]*b.m[b1][b2]);
	return tmp;
}
dt Merge(data a,dt b,ll x,ll y){
	memset(Tmp.m,0,sizeof Tmp.m);
	For(a1,0,1)	For(a2,0,1)	For(b1,0,1)	For(b2,0,1)	For(cur,0,1)
	add(Tmp.m[((a2^x)||(b2^y))^a1^b1][a2][cur],a.m[a1][a2]*b.m[b1][b2][cur]);
	return Tmp;
}
void dfs(ll x,ll pre){////	f[x][a][b]a , b 
	f[x].m[jzq[x][1]][0]=1;
	f[x].m[jzq[x][0]][1]=1;
	for(ll i=head[x];i;i=nxt[i])
	if (!in[vet[i]]&&vet[i]!=pre)
	dfs(vet[i],x),f[x]=merge(f[x],f[vet[i]],I[i],you[i]);
}
void dfs1(ll x,ll pre,ll las){
//	writeln(x);	puts("--");
	for(ll i=head[x];i;)if (in[vet[i]]){
		if ((i^las)==1){	i=nxt[i];	continue;	}
		if (vet[i]==rt){
			g[vet[i]]=Merge(f[vet[i]],g[x],you[i],I[i]);
			return;
		}
		g[vet[i]]=Merge(f[vet[i]],g[x],you[i],I[i]);
		dfs1(vet[i],x,i);
		i=nxt[i];	return;
	}
}
void work(ll x){
	fl=t1=t2=0;	fa[x]=x;
	Dfs(x);	
	if (!fl){
		ll x=q1[1];	dfs(x,x);
		ll a0=all[0],a1=all[1];
		all[0]=((f[x].m[0][0]+f[x].m[0][1])%mod*a0+(f[x].m[1][0]+f[x].m[1][1])%mod*a1)%mod;
		all[1]=((f[x].m[0][0]+f[x].m[0][1])%mod*a1+(f[x].m[1][0]+f[x].m[1][1])%mod*a0)%mod;
	}else{
		For(i,1,t2)	dfs(q2[i],q2[i]);
		ll x=q2[1];	rt=x;
		g[x].m[0][0][0]=f[x].m[0][0];
		g[x].m[0][1][1]=f[x].m[0][1];
		g[x].m[1][0][0]=f[x].m[1][0];
		g[x].m[1][1][1]=f[x].m[1][1];
//		writeln(x);	puts("");
		dfs1(x,fa[x],410000LL);
/*		puts("");
		writeln(f[1].m[0][0]);
		writeln(f[1].m[1][0]);
		writeln(f[1].m[0][1]);
		writeln(f[1].m[1][1]);
		puts("");
		writeln(f[2].m[0][0]);
		writeln(f[2].m[1][0]);
		writeln(f[2].m[0][1]);
		writeln(f[2].m[1][1]);
		puts("");
		writeln(g[1].m[0][0][0]);
		writeln(g[1].m[0][0][1]);
		writeln(g[1].m[1][0][0]);
		writeln(g[1].m[1][0][1]);
		writeln(g[1].m[0][1][0]);
		writeln(g[1].m[0][1][1]);
		writeln(g[1].m[1][1][0]);
		writeln(g[1].m[1][1][1]);
		puts("");*/
		ll a0=all[0],a1=all[1];
 		all[0]=((g[x].m[0][0][0]+g[x].m[0][1][1])%mod*a0+(g[x].m[1][0][0]+g[x].m[1][1][1])%mod*a1)%mod;
		all[1]=((g[x].m[0][0][0]+g[x].m[0][1][1])%mod*a1+(g[x].m[1][0][0]+g[x].m[1][1][1])%mod*a0)%mod;		
	}
}
int main(){
//	freopen("ss.in","r",stdin);
	m=read();	n=read();	ll t=0;
	For(i,1,m){
		ll sz=read();
		if (sz==1){	ll x=read();	join[abs(x)]=1;	jzq[abs(x)][x<0]^=1;	}
		else{
			ll x=read(),y=read();	join[abs(x)]=join[abs(y)]=1;
			if (abs(x)!=abs(y)){
				insert(abs(x),abs(y),x<0,y<0);
				insert(abs(y),abs(x),y<0,x<0);
			}else{
				if ((x>0)^(y>0))	t^=1;
				else	jzq[abs(x)][x<0]^=1;
			}
		}
	}
	For(i,1,n)	if (jzq[i][0]&&jzq[i][1])	t^=1,jzq[i][0]=jzq[i][1]=0;
	all[t]=1;
//	work(1);
//	writeln(all[0]);
//	writeln(all[1]);
	For(i,1,n)	if (!vis[i]){
		if (join[i])	work(i);
		else	all[0]=all[0]*2%mod,all[1]=all[1]*2%mod;
	}
//	writeln(f[1].m[0][0]+f[1].m[0][1]);
//	writeln(f[1].m[1][0]+f[1].m[1][1]);
//	writeln(all[0]);
//	writeln(all[0]);
	writeln(all[1]);
}
/*
2 2
2 1 -2
2 -1 2
*/