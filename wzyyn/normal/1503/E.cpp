#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define pii pair<int,int>
#define fi first
#define se second
#define PB push_back
#define ll long long
#define ull unsigned long long
#define pll pair<ll,ll> 
#define y1 orzkcz
using namespace std;

const int N=4055;
const int mo=998244353;
int C[N][N],n,m;
int f[N],g[N],ans;
void init(){
	for (int i=0;i<N;i++) C[i][0]=1;
	for (int i=1;i<N;i++)
		for (int j=1;j<=i;j++)
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%mo;
}

int PTH(int sx,int sy,int tx,int ty){
	sx=abs(sx-tx);
	sy=abs(sy-ty);
	return C[sx+sy][sx];
}
int main(){
	init();
	scanf("%d%d",&n,&m);
	for (int i=1;i<n;i++){
		int s=0;
		for (int j=1;j<m;j++){
			s=(s+1ll*PTH(0,0,i,j-1)*PTH(0,m,i-1,j))%mo;
			ans=(ans+1ll*s*PTH(n,0,i+1,j)%mo*PTH(n,m,i,j+1))%mo;
		}
		s=0;
		for (int j=1;j<m;j++){
			s=(s+1ll*PTH(n,0,i,j-1)*PTH(n,m,i+1,j))%mo;
			ans=(ans+1ll*s*PTH(0,0,i-1,j)%mo*PTH(0,m,i,j+1))%mo;
		}
	}
	swap(n,m);
	for (int i=1;i<n;i++){
		int s=0;
		for (int j=1;j<m;j++){
			ans=(ans+1ll*s*PTH(n,0,i+1,j)%mo*PTH(n,m,i,j+1))%mo;
			s=(s+1ll*PTH(0,0,i,j-1)*PTH(0,m,i-1,j))%mo;
		}
		s=0;
		for (int j=1;j<m;j++){
			ans=(ans+1ll*s*PTH(0,0,i-1,j)%mo*PTH(0,m,i,j+1))%mo;
			s=(s+1ll*PTH(n,0,i,j-1)*PTH(n,m,i+1,j))%mo;
		}
	}
	cout<<ans<<endl;
}
/*

1.  
2.  
3.  
4.  
l,r

l- 
*/