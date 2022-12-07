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

int dx[]={1,0,-1,-1,0 ,1};
int dy[]={1,1,0 ,-1,-1,0};
int c[10];
ll F(int p1,int p2,int x,int y){
	//cout<<p1<<' '<<p2<<' '<<x<<' '<<y<<' '<<dy[p2]*dx[p1]-dy[p1]-dx[p2]<<endl;
	int r2=1ll*(dy[p1]*x-dx[p1]*y)/(dx[p2]*dy[p1]-dx[p1]*dy[p2]);
	int r1=1ll*(dy[p2]*x-dx[p2]*y)/(dx[p1]*dy[p2]-dx[p2]*dy[p1]);
	//cout<<dx[p1]*r1+dx[p2]*r2-x<<' '<<dy[p1]*r1+dy[p2]*r2-y<<endl;
	if (r1<0||r2<0)
		return 1ll<<61;
	return 1ll*r1*c[p1]+1ll*r2*c[p2];
}
/*
dx[p1]*r1+dx[p2]*r2
dy[p1]*r1+dy[p2]*r2
*/
void solve(){
	int x,y;
	scanf("%d%d",&x,&y);
	For(i,0,5) scanf("%d",&c[i]);
	ll ans=1ll<<61;
	For(i,0,5){
		int T=(dx[i]?x/dx[i]:y/dy[i]);
		if (dx[i]*T==x&&dy[i]*T==y&&T>=0) ans=min(ans,1ll*c[i]*T);
	}
	//cout<<233<<endl;
	For(i,0,5) For(j,i+1,5)
		if (dx[i]+dx[j]||dy[i]+dy[j])
			ans=min(ans,F(i,j,x,y));
	cout<<ans<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}