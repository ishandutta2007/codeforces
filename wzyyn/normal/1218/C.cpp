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
const int N=505;
const int M=500005;
int n,m,K,v[M],d[M];
vector<int> v1[N][N],v2[N][N];
ll f[2][N][N][2];
ll sum[N][N],sx[N],sy[N];
void UPD(ll &x,ll y){
	x>y?x=y:233; 
}
bool ins(int x,int y,int T,int v){
	if (x+y<T) return 0;
	if ((x+y)%4!=T%4) return 0;
	sum[x][y]+=v; return 1;
}
int main(){
	//freopen("1.in","r",stdin);
	scanf("%d%d%d",&n,&m,&K);
	For(i,1,K){
		int x,y,d,T;
		scanf("%d%d%d%d%d",&x,&y,&d,&T,&v[i]);
		bool fl0=ins(x+0,y+0,T+0,v[i]);
		bool fl1=ins(x+d,y-d,T+1,v[i]);
		bool fl2=ins(x+d,y+0,T+2,v[i]);
		bool fl3=ins(x+0,y+d,T+3,v[i]);
		//printf("%c %c %c %c\n",fl0?'Y':'N',fl1?'Y':'N',fl2?'Y':'N',fl3?'Y':'N');
		if (fl1&&fl2) v2[x+d][y].PB(i);
		if (fl3&&fl0) v2[x][y+d].PB(i);
		if (fl0&&fl2) v1[x+d][y].PB(i);
		::d[i]=d;
	}
	memset(f,70,sizeof(f));
	f[0][0][0][0]=f[0][0][0][1]=sum[0][0];
	For(i,1,n+m-2){
		int now=(i&1),pre=now^1;
		For(py,0,m-1){
			int px=i-py;
			if (px<0||px>=n) continue;
			memset(sx,0,sizeof(sx));
			memset(sy,0,sizeof(sy));
			for (auto j:v2[px][py]) sy[py-d[j]]+=v[j];
			for (auto j:v1[px][py]) sx[px-d[j]]+=v[j];
			Rep(j,px,0) sx[j]+=sx[j+1];
			Rep(j,py,0) sy[j]+=sy[j+1];
			//cout<<px<<' '<<py<<' '<<sum[px][py]<<' '<<sy[0]<<' '<<sx[0]<<endl;
			if (px!=0){
				For(j,0,px-1) UPD(f[now][px][j][0],f[pre][px-1][j][0]);
				For(j,0,py) UPD(f[now][px][px-1][0],f[pre][px-1][j][1]);
				For(j,0,px) f[now][px][j][0]+=sum[px][py]-sx[j];
			}
			if (py!=0){
				For(j,0,py-1) UPD(f[now][px][j][1],f[pre][px][j][1]);
				For(j,0,px) UPD(f[now][px][py-1][1],f[pre][px][j][0]);
				For(j,0,py) f[now][px][j][1]+=sum[px][py]-sy[j];
			}
		}
		memset(f[pre],70,sizeof(f[pre]));
	}
	ll ans=1ll<<60;
	For(i,0,n-1) UPD(ans,f[(n+m-2)&1][n-1][i][0]);
	For(i,0,m-1) UPD(ans,f[(n+m-2)&1][n-1][i][1]);
	printf("%lld\n",ans);
}
/*
4 6 2
0 2 2 2 10
1 3 2 0 11
*/