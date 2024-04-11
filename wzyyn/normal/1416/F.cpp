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
const int dx[]={0,0,1,-1};
const int dy[]={1,-1,0,0};
const char ans_chr[]={'R','L','D','U'};
const int N=300005;
struct edge{
	int to,next,f;
}e[N*10];
vector<int> v[N];
int ans[N],dif[N],a[N],eid[N];
int dis[N],q[N],head[N],deg[N];
int id,cnt,tot,nd,S,T,SS,TT,n,m;
void add(int x,int y,int f){
	e[++tot]=(edge){y,head[x],f};
	head[x]=tot;
	e[++tot]=(edge){x,head[y],0};
	head[y]=tot;
}
void add(int x,int y,int l,int h){
	if (l==h){
		deg[x]-=l;
		deg[y]+=l;
	}
	else{
		add(x,y,h);
	}
}
bool bfs(int S,int T){
	int h=0,t=1;
	For(i,1,nd) dis[i]=-1;
	q[1]=S; dis[S]=0;
	while (h!=t){
		int x=q[++h];
		for (int i=head[x];i;i=e[i].next)
			if (dis[e[i].to]==-1&&e[i].f){
				dis[e[i].to]=dis[x]+1;
				if (e[i].to==T) return 1;
				q[++t]=e[i].to;
			}
	}
	return 0;
}
int dfs(int x,int T,int flow){
	if (x==T) return flow;
	int k,rest=flow;
	for (int i=head[x];i&&rest;i=e[i].next)
		if (dis[e[i].to]==dis[x]+1&&e[i].f){
			k=dfs(e[i].to,T,min(rest,e[i].f));
			e[i].f-=k; e[i^1].f+=k; rest-=k;
		}
	if (rest) dis[x]=-1;
	return flow-rest;
}
int check(){
	int sum=0;
	For(i,1,T) if (deg[i]<0) sum-=deg[i];
	//sum/=2;
	//cout<<sum<<endl;
	for (;bfs(SS,TT);sum-=dfs(SS,TT,1<<30));
	//cout<<sum<<endl;
	return sum==0;
}
void solve(){
	nd=0; cnt=0; tot=1;
	scanf("%d%d",&n,&m);
	For(i,1,n) v[i].resize(m+2);
	For(i,1,n) For(j,1,m) v[i][j]=++nd;
	S=++nd; T=++nd; SS=++nd; TT=++nd;
	For(i,1,nd) deg[i]=head[i]=0;
	For(i,1,n) For(j,1,m) scanf("%d",&a[v[i][j]]);
	For(i,1,n) For(j,1,m){
		int flag=1;
		For(k,0,3){
			int x=i+dx[k],y=j+dy[k];
			if (x<1||x>n||y<1||y>m) continue;
			if (a[v[x][y]]<a[v[i][j]]) flag=0;
			if (a[v[x][y]]==a[v[i][j]]&&(i+j)%2==1)	
				add(v[i][j],v[x][y],0,1);
		}
		//cout<<
		if ((i+j)%2==1)
			add(S,v[i][j],flag,1);
		else
			add(v[i][j],T,flag,1);
		if (flag==1)
			eid[v[i][j]]=0;
		else eid[v[i][j]]=tot-1;
		//cout<<i<<' '<<j<<' '<<flag<<endl;
	}
	add(T,S,1<<30);
	For(i,1,T)
		if (deg[i]>0)
			add(SS,i,deg[i]);
		else add(i,TT,-deg[i]);
	if (!check())
		return puts("NO"),void(0);
	For(i,1,n) For(j,1,m)
		if (e[eid[v[i][j]]].f){
			//cout<<i<<' '<<j<<' '<<v[i][j]<<endl; 
			For(k,0,3){
				int x=i+dx[k],y=j+dy[k];
				if (x<1||x>n||y<1||y>m) continue;
				if (a[v[x][y]]<a[v[i][j]]){
					ans[v[i][j]]=k;
					dif[v[i][j]]=a[v[i][j]]-a[v[x][y]];
				}
			}
		}
		else{
			int mat=-1;
			for (int ii=head[v[i][j]];ii;ii=e[ii].next)
				if (e[ii].to!=T&&e[ii].to!=S&&(e[ii].f+i+j+1)%2==0)
					mat=e[ii].to;
			//cout<<i<<' '<<j<<' '<<mat<<endl;
			For(k,0,3){
				int x=i+dx[k],y=j+dy[k];
				if (x<1||x>n||y<1||y>m) continue;
				if (v[x][y]==mat) ans[v[i][j]]=k;
			}
			dif[v[i][j]]=((i+j)%2==1?1:a[v[i][j]]-1);
		}
	puts("YES");
	For(i,1,n){
		For(j,1,m) printf("%d ",dif[v[i][j]]);
		puts("");
	}
	For(i,1,n){
		For(j,1,m)
			printf("%c ",ans_chr[ans[v[i][j]]]);
		puts("");
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}