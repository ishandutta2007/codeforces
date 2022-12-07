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
const int mo=998244353;
const int N=200005;
int n,m;
vector<pii> e[N];
pii dis[N][2];
int vis[N][2];
struct node{
	int x,y,d1,d2;
	bool operator <(const node &a)const{
		if (d1!=a.d1) return d1>a.d1;
		return d2>a.d2;
	}
};
priority_queue<node> Q;
void solve1(){
	memset(dis,60,sizeof(dis));
	dis[1][0]=pii(0,0);
	Q.push((node){1,0,0,0});
	while (!Q.empty()){
		int x=Q.top().x,y=Q.top().y;
		Q.pop();
		if (vis[x][y]) continue;
		vis[x][y]=1;
		if (pii(dis[x][y].fi+1,dis[x][y].se)<dis[x][y^1]){
			dis[x][y^1]=pii(dis[x][y].fi+1,dis[x][y].se);
			Q.push((node){x,y^1,dis[x][y].fi+1,dis[x][y].se});
		}
		for (auto i:e[x])
			if (i.se==y&&dis[i.fi][y]>pii(dis[x][y].fi,dis[x][y].se+1)){
				dis[i.fi][y]=pii(dis[x][y].fi,dis[x][y].se+1);
				Q.push((node){i.fi,y,dis[x][y].fi,dis[x][y].se+1});
			}
	}
	pii re=min(dis[n][0],dis[n][1]);
	if (re.fi>20){
		int ans=1;
		For(i,1,re.fi) ans=2ll*ans%mo;
		ans=(ans+re.se+1ll*mo-1)%mo;
		cout<<ans<<endl;
		exit(0);
	}
}
int Dis[N][20];
pii q[N*20];
void solve2(){
	memset(Dis,-1,sizeof(Dis));
	int h=0,t=1;
	Dis[1][0]=0;
	q[1]=pii(1,0);
	while (h!=t){
		pii x=q[++h];
		if (x.se!=18&&Dis[x.fi][x.se+1]<0){
			Dis[x.fi][x.se+1]=Dis[x.fi][x.se]+1;
			q[++t]=pii(x.fi,x.se+1);
		}
		for (auto i:e[x.fi])
			if ((i.se+x.se)%2==0)
				if (Dis[i.fi][x.se]==-1){
					Dis[i.fi][x.se]=Dis[x.fi][x.se]+1;
					q[++t]=pii(i.fi,x.se);
				}
	}
	int ans=1<<30;
	For(i,0,18)
		if (Dis[n][i]!=-1)
			//cout<<i<<' '<<Dis[n][i]<<endl;
			ans=min(ans,Dis[n][i]-i-1+(1<<i));
	cout<<ans<<endl;
}
int main(){
	scanf("%d%d",&n,&m);
	For(i,1,m){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].PB(pii(y,0));
		e[y].PB(pii(x,1));
	}
	solve1();
	solve2();
}