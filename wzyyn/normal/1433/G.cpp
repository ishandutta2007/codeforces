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
const int N=1005;
int n,m,K;
int ex[N],ey[N],ev[N];
vector<pii> e[N];
int px[N],py[N];
int vis[N],dis[N][N];
priority_queue<pii> Q;
void SSSP(int S,int *d){
	For(i,1,n) d[i]=1<<30,vis[i]=0;
	Q.push(pii(d[S]=0,S));
	while (!Q.empty()){
		int x=Q.top().se; Q.pop();
		if (vis[x]) continue;
		vis[x]=1;
		for (auto i:e[x])
			if (d[i.fi]>d[x]+i.se){
				d[i.fi]=d[x]+i.se;
				Q.push(pii(-d[i.fi],i.fi));
			}
	}
}
int main(){
	scanf("%d%d%d",&n,&m,&K);
	For(i,1,m){
		scanf("%d%d%d",&ex[i],&ey[i],&ev[i]);
		e[ex[i]].PB(pii(ey[i],ev[i]));
		e[ey[i]].PB(pii(ex[i],ev[i]));
	}
	For(i,1,K)
		scanf("%d%d",&px[i],&py[i]);
	For(i,1,n) SSSP(i,dis[i]);
	int ans=1<<30;
	For(i,1,m){
		int sum=0;
		For(j,1,K){
			int v=dis[px[j]][py[j]];
			v=min(v,dis[px[j]][ex[i]]+dis[ey[i]][py[j]]);
			v=min(v,dis[px[j]][ey[i]]+dis[ex[i]][py[j]]);
			sum+=v;
		}
		ans=min(ans,sum); 
		//cout<<sum<<endl;
	}
	cout<<ans<<endl;
}