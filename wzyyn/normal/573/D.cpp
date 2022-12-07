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
const int N=30005;
int n,Q;
pii a[N],b[N];
int pa[N],pb[N],mat[N];
ll f[N],g[N][4];
void init(int x){
	if (x<1||x>n) return;
	g[x][1]=g[x][2]=g[x][3]=-(1ll<<60);
	if (mat[x]!=x) g[x][1]=1ll*a[x].fi*b[x].fi;
	if (x>1&&mat[x]!=x-1&&mat[x-1]!=x) g[x][2]=1ll*a[x].fi*b[x-1].fi+1ll*a[x-1].fi*b[x].fi;
	if (x>2&&mat[x]!=x-1&&mat[x-1]!=x-2&&mat[x-2]!=x)
		g[x][3]=max(g[x][3],1ll*a[x].fi*b[x-1].fi+1ll*a[x-1].fi*b[x-2].fi+1ll*a[x-2].fi*b[x].fi);
	if (x>2&&mat[x]!=x-2&&mat[x-2]!=x-1&&mat[x-1]!=x)
		g[x][3]=max(g[x][3],1ll*a[x].fi*b[x-2].fi+1ll*a[x-2].fi*b[x-1].fi+1ll*a[x-1].fi*b[x].fi);
}
ll Func(){
	f[0]=0;
	f[1]=f[0]+g[1][1];
	f[2]=max(f[1]+g[2][1],f[0]+g[2][2]);
	For(i,3,n) f[i]=max(max(f[i-1]+g[i][1],f[i-2]+g[i][2]),f[i-3]+g[i][3]);
	return f[n];
}
/*
11*2+7+3*5=22+22
*/
int main(){
	scanf("%d%d",&n,&Q);
	For(i,1,n) scanf("%d",&a[i].fi),a[i].se=i;
	For(i,1,n) scanf("%d",&b[i].fi),b[i].se=i;
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	For(i,1,n) pa[a[i].se]=i;
	For(i,1,n) pb[b[i].se]=i;
	For(i,1,n) mat[i]=pb[a[i].se];
	//For(i,1,n) cout<<mat[i]<<endl;
	For(i,1,n) init(i);
	while (Q--){
		int x,y;
		scanf("%d%d",&x,&y);
		x=pa[x]; y=pa[y];
		swap(mat[x],mat[y]);
		//cout<<x<<' '<<y<<endl;
		init(x); init(x+1); init(x+2);
		init(y); init(y+1); init(y+2);
		printf("%lld\n",Func());
	}
}