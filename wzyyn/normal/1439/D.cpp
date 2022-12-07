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
int f[N],f1[N],n,m,mo;
int g[N][N],g1[N][N];
int C[N][N];
int S(int x){
	return x*(x+1)/2;
}
int main(){
	scanf("%d%d%d",&n,&m,&mo);
	For(i,0,N-1) C[i][0]=1;
	For(i,1,N-1) For(j,1,i) C[i][j]=(C[i-1][j]+C[i-1][j-1])%mo;
	f[0]=1; f1[0]=0;
	For(i,1,n) For(j,0,i-1){
		int tr=1ll*C[i-1][j]*(i+1)%mo;
		f[i]=(f[i]+1ll*tr*f[j]%mo*f[i-j-1])%mo;
		f1[i]=(f1[i]+1ll*tr*f1[j]%mo*f[i-j-1])%mo;
		f1[i]=(f1[i]+1ll*tr*f[j]%mo*f1[i-j-1])%mo;
		f1[i]=(f1[i]+1ll*C[i-1][j]*f[j]%mo*f[i-j-1]%mo*(S(j)+S(i-j-1)))%mo;
	}
	//For(i,0,n) cout<<f[i]<<' '<<f1[i]<<endl;
	g[0][0]=1;
	For(i,0,n) For(j,0,min(m,i)) For(k,0,min(m-j,n-i)){
		int tr=C[j+k][k];
		g[i+k+1][j+k]=(g[i+k+1][j+k]+1ll*tr*g[i][j]%mo*f[k])%mo;
		g1[i+k+1][j+k]=(g1[i+k+1][j+k]+1ll*tr*g[i][j]%mo*f1[k])%mo;
		g1[i+k+1][j+k]=(g1[i+k+1][j+k]+1ll*tr*g1[i][j]%mo*f[k])%mo;
	}
	cout<<g1[n+1][m]<<endl;
}