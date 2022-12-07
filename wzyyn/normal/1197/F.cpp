#include<bits/stdc++.h>
#define ll long long
#define uint unsigned
#define ull unsigned ll
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
#define y1 hfjskghsdjkfg
using namespace std;
const int mo=998244353;
const int N=1005,M=65;
vector<pii> vec[N];
int n,m,a[N],ava[5][5];
int tr[35][M][M];
int trco[M][5];
int f[2][M],g[2][5];
void work_trans(int dis){
	For(i,0,29) if (dis&(1<<i)){
		For(j,0,63) f[1][j]=0;
		For(j,0,63) For(k,0,63) f[1][k]=(f[1][k]+1ll*f[0][j]*tr[i][j][k])%mo;
		For(j,0,63) f[0][j]=f[1][j];
	}
}
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	scanf("%d",&m);
	For(i,1,m){
		int x,y,c;
		scanf("%d%d%d",&x,&y,&c);
		vec[x].PB(pii(y,c));
	}
	For(i,0,2) For(j,0,2)
		scanf("%d",&ava[i][j]);
	For(i,0,3) For(j,0,3) For(k,0,3) For(c,0,2){
		int sta=0,l=0;
		if (ava[c][0]) sta|=1<<k;
		if (ava[c][1]) sta|=1<<j;
		if (ava[c][2]) sta|=1<<i;
		for (;sta&(1<<l);l++);
		tr[0][i*16+j*4+k][j*16+k*4+l]++;
		trco[i*16+j*4+k][c]=j*16+k*4+l;
	}
	For(T,1,30) For(i,0,63) For(j,0,63) For(k,0,63)
		tr[T][i][k]=(tr[T][i][k]+1ll*tr[T-1][i][j]*tr[T-1][j][k])%mo;
	g[0][0]=1;
	For(i,1,n){
		sort(vec[i].begin(),vec[i].end());
		For(j,0,63) f[0][j]=(j==63);
		int lasp=0;
		For(j,0,vec[i].size()-1){
			int dis=vec[i][j].fi-lasp-1;
			int co=vec[i][j].se-1;
			work_trans(dis);
			For(j,0,63) f[1][j]=0;
			For(j,0,63) f[1][trco[j][co]]=(f[1][trco[j][co]]+f[0][j])%mo;
			For(j,0,63) f[0][j]=f[1][j];
			lasp=vec[i][j].fi;
		}
		work_trans(a[i]-lasp);
		For(j,0,3) g[1][j]=0;
		For(j,0,3) For(k,0,63)
			g[1][j^(k&3)]=(g[1][j^(k&3)]+1ll*g[0][j]*f[0][k])%mo;
		For(j,0,3) g[0][j]=g[1][j];
	}
	printf("%d\n",g[0][0]);
}