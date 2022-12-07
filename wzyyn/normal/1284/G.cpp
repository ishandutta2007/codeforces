#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
using namespace std;
const int N=45,M=1605;
char mp[N][N],ans[N][N];
int id[N][N],dn[N][N],ri[N][N];
int n,m,nd,top,X[M],Y[M],q[M];
int vis[M],in[M],from[M],f[M];
vector<int> e[M];
struct TR1{
	int lim[M];
	void init(){
		For(i,1,n) For(j,1,m)
			if (id[i][j])
				if (i==1&&j==1) lim[id[i][j]]=0;
				else lim[id[i][j]]=((i+j)&1?1<<30:2);
	}
	void insert(int x,int y){
		assert(lim[x]&&lim[y]);
		--lim[x]; --lim[y];
	}
	bool check(int x,int y){
		return lim[x]&&lim[y];
	}
}T1;
struct TR2{
	int f[M];
	int get(int x){
		return x==f[x]?x:f[x]=get(f[x]);
	}
	void init(){
		For(i,1,nd) f[i]=i;
	}
	void insert(int x,int y){
		x=get(x); y=get(y);
		assert(x!=y);
		f[x]=y;
	}
	bool check(int x,int y){
		return get(x)!=get(y);
	}
}T2;
void build(int ban){
	T1.init();
	T2.init();
	For(i,1,top) if (vis[i]&&i!=ban){
		T1.insert(X[i],Y[i]);
		T2.insert(X[i],Y[i]);
	}
}
int getans(){
	int ans=0;
	memset(vis,0,sizeof(vis));
	for (;;){
		For(i,0,top+1) e[i].resize(0);
		For(i,1,top) if (vis[i]){
			build(i);
			For(j,1,top) if (!vis[j]){
				if (T1.check(X[j],Y[j])) e[j].PB(i);
				if (T2.check(X[j],Y[j])) e[i].PB(j);
			}
		}
		build(0);
		For(i,1,top) if (!vis[i]){
			if (T1.check(X[i],Y[i])) e[i].PB(top+1);
			if (T2.check(X[i],Y[i])) e[0].PB(i);
		}
		int h=0,t=1;
		memset(in,0,sizeof(in));
		memset(from,0,sizeof(from));
		q[1]=0; in[0]=1;
		while (h!=t){
			int x=q[++h];
			for (auto i:e[x]) if (!in[i])
				in[i]=1,from[i]=x,q[++t]=i;
		}
		if (!in[top+1]) break;
		for (int i=top+1;i;i=from[i]) vis[i]^=1;
	}
	int sum=0;
	For(i,1,top) sum+=vis[i];
	//For(i,1,top) if (vis[i]) printf("%d %d\n",X[i],Y[i]);
	return sum;
}
int get(int x){
	return x==f[x]?x:f[x]=get(f[x]);
}
bool merge(int x,int y){
	x=get(x); y=get(y);
	if (x==y) return 0;
	f[x]=y;
	return 1;
}
void solve(){
	scanf("%d%d",&n,&m);
	int sum=0; nd=0; top=0;
	For(i,1,n) scanf("%s",mp[i]+1);
	memset(id,0,sizeof(id));
	memset(dn,0,sizeof(dn));
	memset(ri,0,sizeof(ri));
	For(i,1,n) For(j,1,m)
		if (mp[i][j]=='O') id[i][j]=++nd;
	For(i,1,n) For(j,1,m)
		if ((i+j)%2==0&&(i!=1||j!=1)&&id[i][j])
			++sum;
	For(i,1,n) For(j,1,m){
		if (id[i][j]&&id[i+1][j]){
			X[++top]=id[i][j];
			Y[top]=id[i+1][j];
			dn[i][j]=top;
		}
		if (id[i][j]&&id[i][j+1]){
			X[++top]=id[i][j];
			Y[top]=id[i][j+1];
			ri[i][j]=top;
		}
	}
	//For(i,1,top)
	//	printf("%d %d\n",X[i],Y[i]);
	int tmp=getans();
	//cout<<tmp<<' '<<sum<<endl;
	if (tmp!=2*sum) return puts("NO"),void(0);
	memset(ans,0,sizeof(ans));
	For(i,1,2*n-1) For(j,1,2*m-1) ans[i][j]=' ';
	For(i,1,n) For(j,1,m) ans[2*i-1][2*j-1]=mp[i][j];
	For(i,1,nd) f[i]=i;
	For(i,1,n) For(j,1,m){
		if (vis[dn[i][j]]){
			ans[2*i][2*j-1]='O';
			merge(id[i][j],id[i+1][j]);
		}
		if (vis[ri[i][j]]){
			ans[2*i-1][2*j]='O';
			merge(id[i][j],id[i][j+1]);
		}
	}
	For(i,1,n) For(j,1,m){
		if (id[i][j]&&id[i+1][j]&&!vis[dn[i][j]])
			if (merge(id[i][j],id[i+1][j]))
				ans[2*i][2*j-1]='O';
		if (id[i][j]&&id[i][j+1]&&!vis[ri[i][j]])
			if (merge(id[i][j],id[i][j+1]))
				ans[2*i-1][2*j]='O';
	}
	puts("YES");
	For(i,1,2*n-1)
		printf("%s\n",ans[i]+1);
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}