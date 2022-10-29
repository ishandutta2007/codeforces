#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
const int N = 105;
const int N2 = 2e4;
 
int inf,nx,ny,n,x[N],x1[N],x2[N],y[N],y1[N],y2[N];
int S,T,tot=1,flow=0,cap[N2],to[N2],nxt[N2],head[N2],dis[N2],vd[N2];
bool v[N][N];
 
void add(int x,int y,int z){
	to[++tot]=y,cap[tot]=z,nxt[tot]=head[x],head[x]=tot;
	to[++tot]=x,cap[tot]=0,nxt[tot]=head[y],head[y]=tot;
}
 
int sap(int u, int flow){
	if(flow==0||u==T) return flow;
	int tmp, delta=0;
	for(int i=head[u];i;i=nxt[i]){
		if(dis[u]==dis[to[i]]+1 && cap[i]>0){
			tmp = sap(to[i], min(cap[i],flow-delta));
			delta+=tmp, cap[i]-=tmp, cap[i^1]+=tmp;
			if(delta==flow||dis[S]>T+1) return delta;
		}
	}
	vd[dis[u]]--;
	if(vd[dis[u]]==0)dis[S]=T+2;
	vd[++dis[u]]++;
	return delta;
}
 
int main(){
	cin>>inf>>n;
	rep(i,1,n){
		cin>>x1[i]>>y1[i]>>x2[i]>>y2[i];
		++x2[i], ++y2[i];
		x[i*2-1] = x1[i], x[i*2] = x2[i];
		y[i*2-1] = y1[i], y[i*2] = y2[i];
	}
	sort(x+1,x+2*n+1); nx = unique(x+1,x+2*n+1) - x - 1;
	sort(y+1,y+2*n+1); ny = unique(y+1,y+2*n+1) - y - 1;
	unordered_map<int, int> idx,idy;
	rep(i,1,nx) idx[x[i]] = i;
	rep(i,1,ny) idy[y[i]] = i;
	memset(v,0,sizeof v);
	rep(k,1,n){
		rep(i,idx[x1[k]],idx[x2[k]]-1)
			rep(j,idy[y1[k]],idy[y2[k]]-1)
				v[i][j] = true;
	}
	S = 0, T = nx + ny - 1;
	rep(i,1,nx-1) add(S,i,x[i+1]-x[i]);
	rep(i,1,ny-1) add(i+nx-1,T,y[i+1]-y[i]);
	rep(i,1,nx-1)rep(j,1,ny-1)if(v[i][j]){
		add(i,j+nx-1,inf);
	}
	while(dis[S]<=T) flow+=sap(S,inf);
	cout<<flow<<endl;
	return 0;
}