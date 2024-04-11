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
const int mo=1000000007;
const int N=205;
const int dx[]={-2,-2,-1,-1,1,1,2,2};
const int dy[]={-1,1,-2,2,-2,2,-1,1};
int vis[N][N],n;
int dis[N][N],cnt[N];
pii q[N*N];
ll T;
int main(){
	scanf("%lld%d",&T,&n);
	For(i,1,n){
		int x,y;
		scanf("%d%d",&x,&y);
		vis[x+100][y+100]=1;
	}
	int h=0,t=1; cnt[1]=1;
	q[1]=pii(100,100);
	vis[100][100]=1;
	while (h!=t){
		int x=q[++h].fi,y=q[h].se;
		if (dis[x][y]==min(40ll,T)) continue;
		For(d,0,7){
			int nx=x+dx[d],ny=y+dy[d];
			if (vis[nx][ny]) continue;
			vis[nx][ny]=1;
			dis[nx][ny]=dis[x][y]+1;
			++cnt[dis[nx][ny]];
			q[++t]=pii(nx,ny);
		}
	}
	int ans=t;
	if (T>40){
		int delta=cnt[40]-cnt[39];
		ans=(ans+1ll*(cnt[40]+cnt[40]+1ll*(T-39)%mo*delta%mo)*((T-40)%mo)%mo*(mo+1)/2%mo)%mo;
	}
	printf("%d\n",ans);
}