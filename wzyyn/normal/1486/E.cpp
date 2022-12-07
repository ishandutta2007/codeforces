#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define pii pair<int,int>
#define fi first
#define se second
#define PB push_back
#define ll long long
#define ull unsigned long long
#define pll pair<ll,ll> 
#define y1 orzkcz
using namespace std;

const int N=100005;
const int M=500005;
int n,m,nd;
int vi[N][52];
pii be[M];
int dis[M],vis[M];
vector<int> e[N];
priority_queue<pii> Q;
int main(){
	scanf("%d%d",&n,&m);
	nd=n;
	For(i,1,m){
		int x,y,v;
		scanf("%d%d%d",&x,&y,&v);
		if (!vi[x][v]) vi[x][v]=++nd,be[nd]=pii(x,v);
		if (!vi[y][v]) vi[y][v]=++nd,be[nd]=pii(y,v);
		e[x].PB(vi[y][v]);
		e[y].PB(vi[x][v]);
	}
	For(i,1,nd) dis[i]=1<<30,vis[i]=0;
	dis[1]=0; Q.push(pii(dis[1],1));
	while (!Q.empty()){
		int x=Q.top().se; Q.pop();
		if (vis[x]) continue;
		vis[x]=1;
		if (!be[x].fi){
			for (auto i:e[x])
				if (dis[i]>dis[x]){
					dis[i]=dis[x];
					Q.push(pii(-dis[i],i));
				}
		}
		else{
			int px=be[x].fi,py=be[x].se;
			for (auto i:e[px]){
				int qx=be[i].fi,qy=be[i].se;
				if (dis[qx]>dis[x]+(py+qy)*(py+qy)){
					dis[qx]=dis[x]+(py+qy)*(py+qy);
					Q.push(pii(-dis[qx],qx));
				}
			}
		}
	}
	For(i,1,n)
		printf("%d ",dis[i]==(1<<30)?-1:dis[i]);
}