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
int n=read();
vector<pii> g[100005];
int deg[100005],u[100005],v[100005];
int ans[100005],dep1[100005],dep2[100005];
inline void dfs1(int x,int fa){
	foreach(it,g[x]){
		int y=it->first;
		if(y==fa)	continue;
		dep1[y]=dep1[x]+1;
		dfs1(y,x);
	}
}
inline void dfs2(int x,int fa){
	foreach(it,g[x]){
		int y=it->first;
		if(y==fa)	continue;
		dep2[y]=dep2[x]+1;
		dfs2(y,x);
	}
}
int pth[100005],cnt;
inline bool dfs3(int x,int z,int fa){
	if(x==z)	return 1;
	foreach(it,g[x]){
		int y=it->first;
		if(y==fa)	continue;
		pth[++cnt]=it->second;
		if(dfs3(y,z,x)){
			return 1;
		}
		else{
			cnt--;
		}
	}
	return 0;
}
set<int> st;
signed main(){
	fz(i,1,n-1){
		u[i]=read(),v[i]=read();
		g[u[i]].push_back({v[i],i});
		g[v[i]].push_back({u[i],i});
		deg[u[i]]++;deg[v[i]]++;
	}
	fz(i,1,n){
		if(deg[i]==n-1){
			fz(i,1,n-1)	cout<<i-1<<endl;
			return 0;
		}
	}
	dfs1(1,0);
	int mx=-1,rt=0;
	fz(i,1,n)	if(dep1[i]>mx)	mx=dep1[i],rt=i;
	dfs2(rt,0);
	mx=-1;int rt2=0;
	fz(i,1,n)	if(dep2[i]>mx)	mx=dep2[i],rt2=i;
	fill1(ans);
	ans[g[rt][0].se]=0;
	ans[g[rt2][0].se]=1;
	int t1=g[rt][0].fi,t2=g[rt2][0].fi;
	dfs3(t1,t2,0);
	fz(i,2,n-2)	st.insert(i);
	fz(i,1,cnt)	ans[pth[i]]=*st.rbegin(),st.erase(st.find(ans[pth[i]]));
	fz(i,1,n-1)	if(ans[i]==-1)	ans[i]=*st.begin(),st.erase(st.find(ans[i]));
	fz(i,1,n-1)	cout<<ans[i]<<endl;
	return 0;
}