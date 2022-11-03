#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define ll int
#define ld long double
#define For(i,x,y)	for(ll i=(x);i<=(y);++i)
#define FOr(i,x,y)	for(ll i=(x);i>=(y);--i)
#define rep(i,x,y)	for(ll i=(x);i<(y);++i)
#define clr(a,v)	memset(a,v,sizeof(a))
#define cpy(a,b)	memcpy(a,b,sizeof(a))
#define fi	first
#define se	second
#define	pb	push_back
#define mk	make_pair
#define pa	pair<ll,ll>
#define y1	y11111111111111
#define debug	puts("@@@@@@@@@@@@@@@@@@@@@@@")
ll read(){
	ll x=0,f=1;	char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar())	if (ch=='-')	f=-1;
	for(;ch>='0'&&ch<='9';ch=getchar())	x=x*10+ch-'0';
	return x*f;
}
void write(ll x){
	if (x<0)	putchar('-'),write(-x);
	else{
		if (x>=10)	write(x/10);
		putchar(x%10+'0');
	}
}
const ll N=500010;
vector<ll>g[N],q[N];
ll lba,lbb,now,n,res,cnt,mark[N],fib[N],siz[N],vis[N];
void dfs(ll x,ll fa){
	siz[x]=1;
	rep(i,0,g[x].size()){
		ll to=g[x][i];
		if ((vis[to]!=now)||(to==fa))continue;
		dfs(to,x);
		siz[x]+=siz[to];
	}
	if ((fa!=-1)&&(mark[siz[x]])&&(mark[q[now].size()-siz[x]])){
		lba=fa;lbb=x;
		res=1;
	}
}
void color(ll x,ll fa){
	vis[x]=cnt;q[cnt].pb(x);
	rep(i,0,g[x].size()){
		ll to=g[x][i];
		if ((vis[to]!=now)||(to==fa))continue;
		color(to,x);
	}
}
int main(){
	n=read();
	fib[0]=fib[1]=1;
	For(i,2,26)fib[i]=fib[i-1]+fib[i-2];
	For(i,1,26)mark[fib[i]]=i;
	For(i,2,n){
		ll u=read(),v=read();
		g[u].pb(v);
		g[v].pb(u);
	}
	bool fl=0;
	if(!mark[n]){
		puts("NO");
		return 0;
	}
	For(i,1,n)q[1].pb(i),vis[i]=1;
	cnt=1;
	for(now=1;now<=cnt;++now){
		if(q[now].size()>1){
			res=0;
			dfs(q[now][0],-1);
			++cnt;
			color(lba,lbb);
			++cnt;
			color(lbb,lba);
			if (!res){
				puts("NO");
				return 0;
			}
		}
	}
	puts("YES");
}