#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;

const int N=55;
int n,k,ans,dlim[N],e[N][N];
int ex[N*6],ey[N*6],vi[N][N];
struct NI1{
	int fa[N];
	int get(int x){
		return x==fa[x]?x:fa[x]=get(fa[x]);
	}
	bool init(){
		for (int i=1;i<=n;i++) fa[i]=i;
		for (int i=1;i<=k;i++)
			for (int j=i+1;j<=k;j++)
				if (vi[i][j]){
					int x=get(i),y=get(j);
					if (x==y) return 0;
					fa[x]=y;
				}
		return 1;
	}
	void add(int x,int y){
		fa[get(x)]=get(y);
	}
	bool chk(int x,int y){
		return get(x)!=get(y);
	}
}T1;
struct NI2{
	int deg[N];
	bool init(){
		memset(deg,0,sizeof(deg));
		for (int i=1;i<=k;i++)
			for (int j=i+1;j<=k;j++){
				if (!vi[i][j]) continue;
				if ((++deg[i])>dlim[i]) return 0;
				if ((++deg[j])>dlim[j]) return 0;
			}
		return 1;
	}
	void add(int x,int y){
		++deg[x]; ++deg[y];
	}
	bool chk(int x,int y){
		return (x>k||deg[x]!=dlim[x])&&(y>k||deg[y]!=dlim[y]);
	}
}T2;
int vis[N*6],inq[N*6];
int dis[N*6],q[N*666],fr[N*6];
vector<int> E[N*6];
void build(int id){
	T1.init();
	T2.init();
	for (int i=1;i<=*ex;i++)
		if (i!=id&&vis[i]){
			if (T1.chk(ex[i],ey[i])) T1.add(ex[i],ey[i]);
			if (T2.chk(ex[i],ey[i])) T2.add(ex[i],ey[i]);
		}
}
void Check(int S){
	int m=*ex+1;
	if (!T1.init()||!T2.init()) return;
	memset(vis,0,sizeof(vis));
	int sum=S;
	for (;;){
		for (int i=0;i<=m+1;i++)
			E[i].resize(0),dis[i]=-1e9;
		for (int i=1;i<=m;i++) if (vis[i]){
			build(i);
			for (int j=1;j<=m;j++) if (!vis[j]){
				if (T1.chk(ex[j],ey[j])) E[j].push_back(i);
				if (T2.chk(ex[j],ey[j])) E[i].push_back(j);
			}
		}
		build(0);
		for (int i=1;i<=m;i++)
			if (!vis[i]){
				if (T1.chk(ex[i],ey[i])) E[i].push_back(m+1);
				if (T2.chk(ex[i],ey[i])) E[0].push_back(i);
			}
		
		memset(inq,0,sizeof(inq));
		memset(fr,0,sizeof(fr));
		int h=0,t=1;
		q[1]=0; dis[0]=0;
		while (h!=t){
			int x=q[++h]; inq[x]=0;
			for (int i=0;i<E[x].size();i++){
				int to=E[x][i];
				int nv=dis[x]+e[ex[to]][ey[to]]*(vis[to]?-1:1);
				if (nv>dis[to]){
					dis[to]=nv;	fr[to]=x;
					if (!inq[to]){
						inq[to]=1;
						q[++t]=to;
					}
				}
			}
		}
		if (dis[m+1]<-1e8) return;
		sum+=dis[m+1]; ans=max(ans,sum);
		for (int i=fr[m+1];i;i=fr[i]) vis[i]^=1;
	}
}
void dfs(int x,int y,int S){
	if (y>k) x++,y=x+1;
	if (x>=k) return Check(S);
	vi[x][y]=0; dfs(x,y+1,S);
	vi[x][y]=1; dfs(x,y+1,S+e[x][y]);
	vi[x][y]=0;
}
void PRIM(){
	static int fr[N],d[N],vis[N];
	memset(fr,0,sizeof(fr));
	memset(d,233,sizeof(d));
	memset(vis,0,sizeof(vis));
	d[k]=0;
	for (int i=k+1;i<=n;i++){
		int p=-1;
		for (int j=k+1;j<=n;j++)
			if (!vis[j]&&(p==-1||d[j]>d[p]))
				p=j;
		vis[p]=1;
		if (fr[p]) ex[++*ex]=p,ey[*ex]=fr[p];//cout<<"EDGE "<<p<<' '<<fr[p]<<' '<<e[p][fr[p]]<<endl;
		for (int j=k+1;j<=n;j++)
			if (!vis[j]&&d[j]<e[p][j])
				d[j]=e[p][j],fr[j]=p;
	}
}
int main(){
	scanf("%d%d",&n,&k);
	for (int i=1;i<=k;i++)
		scanf("%d",&dlim[i]);
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++){
			scanf("%d",&e[i][j]);
			e[j][i]=e[i][j]=-e[i][j]+100000;
		}
	PRIM();
	for (int i=1;i<=k;i++)
		for (int j=k+1;j<=n;j++)
			ex[++*ex]=i,ey[*ex]=j;
	ans=-(1<<30);
	dfs(1,2,0);
	printf("%d\n",(n-1)*100000-ans);
}