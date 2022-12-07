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
int lx[55],ly[55],rx[55],ry[55];
int v[55],vis[55][2][2][2][2][2];
pii f[55][2][2][2][2][2];
pii F(int d,int v1,int v2,int v3,int v4,int v5){
	if (d==-1) return pii(0,1);
	if (vis[d][v1][v2][v3][v4][v5])
		return f[d][v1][v2][v3][v4][v5];
	pii ans(0,0);
	For(vx,v1?lx[d]:0,v2?rx[d]:1)
		For(vy,v3?ly[d]:0,v4?ry[d]:1)
			if (!v5||((vx^vy)<=v[d])){
				pii tmp=F(d-1,v1&(vx==lx[d]),v2&(vx==rx[d]),
							  v3&(vy==ly[d]),v4&(vy==ry[d]),
							  v5&((vx^vy)==v[d]));
				if (vx^vy) tmp.fi=(tmp.fi+(1ll<<d)*tmp.se)%mo;
				ans.fi=(ans.fi+tmp.fi)%mo;
				ans.se=(ans.se+tmp.se)%mo;
			}
	vis[d][v1][v2][v3][v4][v5]=1;
	return f[d][v1][v2][v3][v4][v5]=ans;
}
void decode(int *a,int d){
	For(i,0,29)
		a[i]=(d>>i)&1;
}
void solve(){
	int a,b,c,d,e;
	scanf("%d%d%d%d%d",&a,&c,&b,&d,&e);
	decode(lx,a-1); decode(rx,b-1);
	decode(ly,c-1); decode(ry,d-1);
	decode(v,min(e,1<<30)-1);
	memset(f,0,sizeof(f));
	memset(vis,0,sizeof(vis));
	pii ans=F(29,1,1,1,1,1);
	printf("%d\n",(ans.fi+ans.se)%mo);
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}