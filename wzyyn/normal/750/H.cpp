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
const int dx[]={-1,-1,-1,0,0,1,1,1};
const int dy[]={-1,0,1,-1,1,-1,0,1};
const int N=1005,M=1010000;
int n,m,Q,nd,id[N][N];
int fa[M],flg[M];
int vis[M],axib[M],T;
vector<int> e[M];
set<int> S[M],adj[N][N];
char s[N][N];
void init(int x){
	if (vis[x]==T) return;
	vis[x]=T; e[x].resize(0);
}
void add_edge(int x,int y){
	init(x); init(y);
	e[x].PB(y); e[y].PB(x);
}
void bfs(int S,int *q){
	axib[S]=++*axib;
	int h=0,t=1; q[1]=S;
	while (h!=t){
		int x=q[++h];
		for (auto i:e[x])
			if (axib[i]!=*axib){
				q[++t]=i;
				axib[i]=*axib;
			}
	}
	*q=t;
}
int get(int x){
	return x==fa[x]?x:fa[x]=get(fa[x]);
}
int main(){
	scanf("%d%d%d",&n,&m,&Q);
	For(i,0,n+1) For(j,0,m+1) s[i][j]='#';
	For(i,1,n) scanf("%s",s[i]+1);
	For(i,1,n) s[i][m+1]='#';
	For(i,0,1) For(j,0,1) s[i][j]=s[i+n][j+m]='.';
	For(i,0,n+1) For(j,0,m+1) id[i][j]=++nd,fa[nd]=nd;
	For(i,0,n+1) For(j,0,m+1) For(d,0,7){
		if (s[i][j]!='#') continue;
		int ni=i+dx[d],nj=j+dy[d];
		if (i<0||i>n+1||j<0||j>m+1||s[ni][nj]!='#') continue;
		fa[get(id[i][j])]=get(id[ni][nj]);
	}
	//For(i,0,n+1)
	//	printf("%s\n",s[i]);
	int SS=get(id[0][m+1]);
	int TT=get(id[n+1][0]);
	assert(SS!=TT);
	For(i,1,n) For(j,1,m){
		set<int> &tmp=adj[i][j];
		if (s[i][j]=='#'||(i==1&&j==1)||(i==n&&j==m)) continue;
		For(d,0,7){
			int ni=i+dx[d],nj=j+dy[d];
			if (i<0||i>n+1||j<0||j>m+1||s[ni][nj]!='#') continue;
			tmp.insert(get(id[ni][nj]));
		}
		for (auto p1:tmp) for (auto p2:tmp){
			assert(p1!=SS||p2!=TT);
			if (p1!=p2) S[p1].insert(p2);
		}
		//cout<<i<<' '<<j<<' '<<adj[i][j].size()<<endl;
	}
	while (Q--){
		++T;
		int k,X[15],Y[15];
		scanf("%d",&k);
		For(i,1,k){
			int x,y;
			scanf("%d%d",&x,&y);
			s[X[i]=x][Y[i]=y]='#';
			For(d,0,7){
				int nx=x+dx[d],ny=y+dy[d];
				if (nx<0||nx>n+1||ny<0||ny>m+1) continue;
				if (s[nx][ny]=='#')
					add_edge(get(id[x][y]),get(id[nx][ny]));
				else{
					for (auto k:adj[nx][ny]){
						S[k].insert(id[x][y]);
						S[id[x][y]].insert(k);			
					}
					adj[nx][ny].insert(id[x][y]);
				}
			}
		}
		static int qs[105],qt[105];
		init(SS); init(TT);
		bfs(SS,qs); bfs(TT,qt);
		bool flag=0;
		For(i,1,*qs) if (qs[i]==TT) flag=1;
		For(i,1,*qs) For(j,1,*qt)
			if (S[qs[i]].find(qt[j])!=S[qs[i]].end())
				flag=1;
		puts(flag?"NO":"YES");
		fflush(stdout);
		For(i,1,k){
			int x=X[i],y=Y[i];
			s[X[i]][Y[i]]='.'; 
			For(d,0,7){
				int nx=x+dx[d],ny=y+dy[d];
				if (nx<0||nx>n+1||ny<0||ny>m+1) continue;
				if (s[nx][ny]=='#'); 
				else{
					for (auto k:adj[nx][ny]){
						S[k].erase(id[x][y]);
						S[id[x][y]].erase(k);			
					}
					adj[nx][ny].erase(id[x][y]);
				}
			}
		} 
	}
}