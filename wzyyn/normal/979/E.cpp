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
const int N=55;
int n,p,a[N],P[N];
int f[N][N][N][2];
int main(){
	scanf("%d%d",&n,&p);
	For(i,1,n) scanf("%d",&a[i]);
	f[0][0][0][0]=P[0]=1;
	For(i,1,N-1) P[i]=2ll*P[i-1]%mo;
	For(i,1,n) For(j,0,i) For(k,0,i) For(fl,0,1){
		if (a[i]!=0){
			int f1=P[i-1-(j!=0)],f0=(P[i-1]+mo-f1)%mo;
			f[i][j][k+1][fl^1]=(f[i][j][k+1][fl^1]+1ll*f[i-1][j][k][fl]*f1)%mo;
			f[i][j][k  ][fl  ]=(f[i][j][k  ][fl  ]+1ll*f[i-1][j][k][fl]*f0)%mo;
		}
		if (a[i]!=1){
			int f1=P[i-1-(k!=0)],f0=(P[i-1]+mo-f1)%mo;
			f[i][j+1][k][fl^1]=(f[i][j+1][k][fl^1]+1ll*f[i-1][j][k][fl]*f1)%mo;
			f[i][j  ][k][fl  ]=(f[i][j  ][k][fl  ]+1ll*f[i-1][j][k][fl]*f0)%mo;
		}
	}
	int ans=0;
	For(i,0,n) For(j,0,n)
		ans=(ans+f[n][i][j][p])%mo;
	printf("%d\n",ans);
}