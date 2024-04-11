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
const int N=55,M=2505;
int c[5],n,T,fac[N];
int f[N][M],g[N][N][M];
int h[N][N][N][3],ans;
void UPD(int &x,int y){
	(x+=y)>=mo?x-=mo:233; 
}
int main(){
	fac[0]=1;
	For(i,1,N-1) fac[i]=1ll*fac[i-1]*i%mo;
	scanf("%d%d",&n,&T);
	f[0][0]=1;
	g[0][0][0]=1;
	For(i,1,n){
		int x,y;
		scanf("%d%d",&y,&x);
		if (x==1)
			Rep(j,c[1],0) For(k,y,T)
				UPD(f[j+1][k],f[j][k-y]);
		else
			Rep(j,c[2],0) Rep(k,c[3],0) For(l,y,T)
				UPD(g[j+(x==2)][k+(x==3)][l],g[j][k][l-y]);
		++c[x];
	}
	h[1][0][0][0]=1;
	h[0][1][0][1]=1;
	h[0][0][1][2]=1;
	For(i,0,c[1]) For(j,0,c[2]) For(k,0,c[3])
		For(la,0,2) For(no,0,2) if (no!=la)
			UPD(h[i+(no==0)][j+(no==1)][k+(no==2)][no],h[i][j][k][la]);
	For(i,0,c[1]) For(j,0,c[2]) For(k,0,c[3]){
		int val=(h[i][j][k][0]+h[i][j][k][1]+1ll*h[i][j][k][2])%mo;
		val=1ll*val*fac[i]%mo*fac[j]%mo*fac[k]%mo;
		//cout<<val<<' '<<i<<' '<<j<<' '<<k<<endl;
		For(L,0,T) ans=(ans+1ll*val*f[i][L]%mo*g[j][k][T-L])%mo;
	}
	printf("%d\n",ans);
}
/*
fac[a]*C[a-1][b-1]*DP; 
*/