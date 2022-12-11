#include <bits/stdc++.h>

using namespace std;

#define X first 
#define Y second 
#define FOR(i,L,R) for(auto i=(L);i<=(R);i++)
#define REP(i,L,R) for(auto i=(L);i<(R);i++)

typedef pair<int,int> ii;
typedef long long ll;

const int inf=1e9;
const int MOD=1e9+7;
const int N=4e5+10;

vector <int> v[N];
int n;
int pa[N][20],sub[N],lv[N];

int q[N];
int f[N],ans[N];
int g[N];
void BFS(){
	int top=1,bot=1;
	q[1]=1;
	while (top<=bot){
		int x=q[top++];
		for(auto y:v[x]) if (y!=pa[x][0]){
			pa[y][0]=x;
			q[++bot]=y;
			lv[y]=lv[x]+1;
		}
	}
}
void prepare(){
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	BFS();
	for(int lay=1;lay<20;lay++)
		for(int i=1;i<=n;i++) pa[i][lay]=pa[pa[i][lay-1]][lay-1];
	fill(sub+1,sub+n+1,1);
	for(int j=n;j>=1;j--){
		int x=q[j];
		for(auto y:v[x]) if (y!=pa[x][0])
			sub[x]+=sub[y];
	}
	sub[0]=inf;
}
void DFS(int x,int val){
	if (n-sub[x]>n/2)
		ans[x]=n-sub[x]-val<=n/2;
	///get from son
	int cval=-inf;
	int sel=0;
	for(auto y:v[x]) if (y!=pa[x][0]){
		if (cval<g[y]) sel=y;
		cval=max(cval,g[y]);
	}
	for(auto y:v[x]) if (y!=pa[x][0]){
		int fval=val;
		if (y!=sel) fval=max(fval,cval);
		else {
			for(auto z:v[x]) 
				if (z!=pa[x][0]&&z!=y) fval=max(fval,g[z]);
		}
		if (n-sub[y]<=n/2) fval=max(fval,n-sub[y]);
		DFS(y,fval);
		//from par and itself
	}
}
void solve(){
	for(int j=n;j>=1;j--){
		int x=q[j];
		if (sub[x]<=n/2){
			int cur=x;
			for(int i=int(log2(lv[x]));i>=0;i--){
				int z=pa[cur][i];
				if (sub[z]-sub[x]<=n/2) cur=z;
			}
			f[pa[x][0]]++;
			f[pa[cur][0]]--;
		}
	}
	for(int j=n;j>=1;j--){
		int x=q[j];
		for(auto y:v[x]) if (y!=pa[x][0])
			f[x]+=f[y];
	}
	for(int j=n;j>=1;j--){
		int x=q[j];
		int val=0;
		for(auto y:v[x]) if (y!=pa[x][0])
			val=max(val,sub[y]);
		if (val<=n/2) {
			///centroid initialy 
			if (n-sub[x]<=n/2) ans[x]=1;
		}else {
			///cut from a son 
			for(auto y:v[x]) 
				if (y!=pa[x][0]&&sub[y]>n/2&&f[y]) ans[x]=1;
		}
	}
	for(int j=n;j>=1;j--){
		int x=q[j];
		for(auto y:v[x]) if (y!=pa[x][0])
			g[x]=max(g[x],g[y]);
		if (sub[x]<=n/2) g[x]=sub[x];
	}
	DFS(1,-inf);
	for(int i=1;i<=n;i++) printf("%d ",ans[i]);
}
int main(){
	prepare();
	solve();
}