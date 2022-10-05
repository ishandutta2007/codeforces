//Coded by tzc_wk
/*




D P 




 l l
*/
#include <bits/stdc++.h>
using namespace std;
#define fi			first
#define se			second
#define fz(i,a,b)	for(int i=a;i<=b;i++)
#define fd(i,a,b)	for(int i=a;i>=b;i--)
#define foreach(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define all(a)		a.begin(),a.end()
#define giveup(...) return printf(__VA_ARGS__),0;
#define fill0(a)	memset(a,0,sizeof(a))
#define fill1(a)	memset(a,-1,sizeof(a))
#define fillbig(a)	memset(a,0x3f,sizeof(a))
#define fillsmall(a) memset(a,0xcf,sizeof(a))
#define mask(a)		(1ll<<(a))
#define maskx(a,x)	((a)<<(x))
#define _bit(a,x)	(((a)>>(x))&1)
#define _sz(a)		((int)(a).size())
#define filei(a)	freopen(a,"r",stdin);
#define fileo(a)	freopen(a,"w",stdout);
#define fileio(a) 	freopen(a".in","r",stdin);freopen(a".out","w",stdout)
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#define put(x)		putchar(x)
#define eoln        put('\n')
#define space		put(' ')
#define y1			y_chenxiaoyan_1
#define y0			y_chenxiaoyan_0
#define int long long
typedef pair<int,int> pii;
inline int read(){
	int x=0,neg=1;char c=getchar();
	while(!isdigit(c)){
		if(c=='-')	neg=-1;
		c=getchar();
	}
	while(isdigit(c))	x=x*10+c-'0',c=getchar();
	return x*neg;
}
inline void print(int x){
	if(x<0){
		putchar('-');
		print(abs(x));
		return;
	}
	if(x<=9)	putchar(x+'0');
	else{
		print(x/10);
		putchar(x%10+'0');
	}
}
inline int qpow(int x,int e,int _MOD){
	int ans=1;
	while(e){
		if(e&1)	ans=ans*x%_MOD;
		x=x*x%_MOD;
		e>>=1;
	}
	return ans;
}
int n=read(),k=read();
vector<int> g[50005];
int sz[50005],mx[50005],sum=0,rt=0;
bool vis[50005];
int cnt=0,dist[50005],mem[50005];
int num[505],ans=0;
inline void centroid(int x,int fa){
	sz[x]=1;
	mx[x]=0;
    for(int i=0;i<g[x].size();i++){
		int y=g[x][i];
		if(y==fa||vis[y])	continue;
		centroid(y,x);
		sz[x]+=sz[y];
		mx[x]=max(mx[x],sz[y]);
	}
	mx[x]=max(mx[x],sum-sz[x]);
	if(mx[x]<mx[rt])	rt=x;
}
inline void getdist(int x,int fa){
	mem[++cnt]=dist[x];
	for(int i=0;i<g[x].size();i++){
		int y=g[x][i];
		if(y==fa||vis[y])	continue;
		dist[y]=dist[x]+1;
		getdist(y,x);
	}
}
inline void getans(int x){
	for(int i=0;i<g[x].size();i++){
		int y=g[x][i];
		if(vis[y])	continue;
		dist[y]=1;cnt=0;
		getdist(y,0);
		for(int j=1;j<=cnt;j++){
			if(k-mem[j]>=0){
				ans+=num[k-mem[j]];
			}
		}
		for(int j=1;j<=cnt;j++){
			num[mem[j]]++;
		}
	}
	memset(num,0,sizeof(num));
}
inline void conquer(int x){
	vis[x]=1;num[0]++;
	getans(x);
	for(int i=0;i<g[x].size();i++){
		int y=g[x][i];
		if(vis[y])	continue;
		sum=sz[y];
		rt=0;mx[rt]=0x3f3f3f3f;
		centroid(y,0);
		conquer(rt);
	}
}
inline void solve(){
	sum=n;
	rt=0;mx[rt]=0x3f3f3f3f;
	centroid(1,0);
	conquer(rt);
}
signed main(){
	fz(i,1,n-1){
		int u=read(),v=read();
		g[u].push_back(v);
		g[v].push_back(u);
	}
	solve();
	cout<<ans<<endl;
	return 0;
}