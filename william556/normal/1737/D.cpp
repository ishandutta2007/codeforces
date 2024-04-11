#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int in(){
	int x;
	scanf("%d",&x);
	return x;
}
const int N=505;
int n,m;
int dis[N][N];
vector<int> e[N];
int lx[N*N],ly[N*N],lz[N*N]; 
void bfs(int s,int *dis){
	queue<int> q;
	for(int i=1;i<=n;i++)dis[i]=n+1;
	dis[s]=0;q.push(s);
	while(q.size()){
		int x=q.front();q.pop();
		for(int y:e[x]){
			if(dis[y]>dis[x]+1){
				dis[y]=dis[x]+1;
				q.push(y);	
			}
		}
	}	
}
void solve(){
	n=in(),m=in();
	for(int i=1;i<=n;i++)e[i].clear();
	for(int i=1;i<=m;i++){
		lx[i]=in(),ly[i]=in(),lz[i]=in();
		e[lx[i]].push_back(ly[i]);
		e[ly[i]].push_back(lx[i]); 
	}
	for(int i=1;i<=n;i++)bfs(i,dis[i]);
	long long ans=1e18;
	static int q[N];
	for(int i=1;i<=m;i++){
		int x=lx[i],y=ly[i],z=lz[i];
		ans=min(ans,(ll)(dis[1][x]+dis[n][y]+1)*z);
		ans=min(ans,(ll)(dis[1][y]+dis[n][x]+1)*z);
		for(int j=1;j<=n;j++){
			ans=min(ans,(ll)(min(dis[x][j],dis[y][j])+1+dis[1][j]+dis[n][j]+1)*z);
		}
	}
	cout<<ans<<endl;
}
int main(){
//	freopen("D.in","r",stdin); 
	int t=in();
	while(t--)solve();
	return 0;
}