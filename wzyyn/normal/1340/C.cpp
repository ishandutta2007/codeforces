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
const int N=10005,M=1005;
int n,m,h,t;
int d[N],G,R;
int dis[N][M];
pii q[N*M];
void UPD(int x,int y,int z){
	if (dis[x][y]<=z) return;//continue;
	dis[x][y]=z;
	if (h==t) q[++t]=pii(x,y);
	else if (z==dis[q[h+1].fi][q[h+1].se]) q[h--]=pii(x,y);
	else q[++t]=pii(x,y);
}
int main(){
	scanf("%d%d",&n,&m);
	For(i,1,m) scanf("%d",&d[i]);
	scanf("%d%d",&G,&R);
	sort(d+1,d+m+1);
	m=unique(d+1,d+m+1)-d-1;
	For(i,1,m) For(j,0,G) dis[i][j]=1<<30;
	h=10000000,t=h+1;
	q[t]=pii(1,0); dis[1][0]=0;
	while (h!=t){
		int x=q[++h].fi,y=q[h].se;
		//cout<<x<<' '<<y<<' '<<h<<' '<<t<<endl;
		if (y==G) UPD(x,0,dis[x][y]+1);
		if (x!=1&&y+d[x]-d[x-1]<=G) UPD(x-1,y+d[x]-d[x-1],dis[x][y]);
		if (x!=m&&y+d[x+1]-d[x]<=G) UPD(x+1,y+d[x+1]-d[x],dis[x][y]);
	}
	ll ans=1<<30;
	For(i,0,G) ans=min(ans,dis[m][i]*1ll*(R+G)+i);
	if (ans==(1<<30)) puts("-1");
	else printf("%lld\n",ans);
}