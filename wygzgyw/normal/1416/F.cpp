#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int INF=1e9;
const int maxn=(1e5)+20;
const int maxm=(5e6)+10;
int T,n,m,s,t,nS,nT,cur[maxn];
int level[maxn],tot;
int flow[maxm];
int head[maxn],nxt[maxm];
int to[maxm],Flow[maxm];
queue<int> q;
vector<int> a[maxn],dir[maxn],a1[maxn],a2[maxn];
int fx[4][3]={{-1,0,'U'},{0,-1,'L'},{1,0,'D'},{0,1,'R'}};
int cap[maxn][2],ans;
void Add_edge(int a,int b,int c) {
	tot++; nxt[tot]=head[a];
	head[a]=tot; to[tot]=b; flow[tot]=Flow[tot]=c;
}
void add_edge(int a,int b,int c) {
	//printf("%d %d %d\n",a,b,c);
	Add_edge(a,b,c);
	Add_edge(b,a,0);
}
void add_lim(int a,int b) {
	cap[b][0]++,cap[a][1]++;
}
bool bfs() {
	q=queue<int>();
	for (int i=0;i<=nT;i++) level[i]=-1,cur[i]=head[i];
	q.push(nS);
	level[nS]=0;
	while (!q.empty()) {
		int a=q.front(),b; q.pop();
		for (register int i=head[a];i;i=nxt[i]) {
			b=to[i];
			if (flow[i]>0&&level[b]==-1) {
				level[b]=level[a]+1;
				q.push(b);
			}
		}
	}
	return level[nT]!=-1;
}
int dfs(int x,int rest) {
	if (x==nT) return rest;
	int used=0;
	for (register int i=cur[x];i;i=nxt[i]) {
		cur[x]=i;
		int y=to[i];
		if (flow[i]>0&&level[y]==level[x]+1) {
			int tflow=dfs(y,min(flow[i],rest-used));
			used+=tflow;
			flow[i]-=tflow;
			flow[i^1]+=tflow;
			if (rest-used==0) break;
		}
	}
	if (!used) level[x]=-1;
	return used;
}
int num(int x,int y) {
	return x*m+y;
}
int main() {
	//freopen("1.txt","r",stdin);
	int x,y,x_x,x_y,y_x,y_y;
	read(T);
	while (T--) {
		read(n),read(m);
		for (int i=0;i<=n;i++) dir[i]=a[i]=a1[i]=a2[i]=vector<int>(m+2,0);
		for (int i=0;i<n;i++) for (int j=0;j<m;j++) read(a[i][j]);
		s=n*m,t=s+1,nS=t+1,nT=t+2;
		tot=1;
		for (int i=0;i<=nT;i++) {
			cap[i][0]=cap[i][1]=0;
			head[i]=0;
		}
		for (int i=0;i<n;i++)
		for (int j=0;j<m;j++) {
			dir[i][j]=-1;
			for (int k=0;k<4;k++) {
				x=i+fx[k][0],y=j+fx[k][1];
				if (0<=x&&x<n&&0<=y&&y<m) {
					if (a[x][y]<a[i][j]) dir[i][j]=k;
					else if ((i+j)%2==0&&a[x][y]==a[i][j]) add_edge(num(i,j),num(x,y),1);
				}
			}
			if (dir[i][j]==-1) {
				if ((i+j)%2==1) add_lim(num(i,j),t);
				else add_lim(s,num(i,j));
			} else {
				if ((i+j)%2==1) add_edge(num(i,j),t,1);
				else add_edge(s,num(i,j),1);
			}
		}
		//printf("OK\n");
		for (int i=0;i<=t;i++) {
			if (cap[i][0]>0) add_edge(nS,i,cap[i][0]);
			if (cap[i][1]>0) add_edge(i,nT,cap[i][1]);
		}
		add_edge(t,s,INF);
		ans=0; while (bfs()) ans+=dfs(nS,INF);
		int flag=1;
		for (int i=head[nS];i;i=nxt[i]) {
			if (flow[i]!=0) { flag=0; break; }
		}
		if (!flag) { puts("NO"); continue; }
		for (int i=0;i<n;i++)
		for (int j=0;j<m;j++) {
			if (dir[i][j]!=-1) {
				x=i+fx[dir[i][j]][0],y=j+fx[dir[i][j]][1];
				a1[i][j]=a[i][j]-a[x][y];
				a2[i][j]=dir[i][j];
			}
		}
		for (int i=0;i<=nT;i++) {
			for (int j=head[i];j;j=nxt[j]) {
				x=i,y=to[j];
				if (max(x,y)<n*m&&flow[j]==0&&Flow[j]==1) {
					x_x=x/m,x_y=x%m;
					y_x=y/m,y_y=y%m;
					a1[x_x][x_y]=a[x_x][x_y]-1;
					a1[y_x][y_y]=1;
					for (int k=0;k<4;k++) {
						if (x_x+fx[k][0]==y_x&&x_y+fx[k][1]==y_y) {
							a2[x_x][x_y]=k;
							a2[y_x][y_y]=(k+2)%4;
						}
					}
				}
			}
		}
		puts("YES");
		for (int i=0;i<n;i++) {
			for (int j=0;j<m;j++) printf("%d ",a1[i][j]); puts("");
		}
		for (int i=0;i<n;i++) {
			for (int j=0;j<m;j++) printf("%c ",fx[a2[i][j]][2]); puts("");
		}
	}
	return 0;
}
/*
  0. Enough array size? Enough array size? Enough array size? Interger overflow?
  
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Time complexity? Memory usage? Precision error?
*/