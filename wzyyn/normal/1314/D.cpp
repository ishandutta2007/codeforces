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
const int N=85;
int n,K,ans,fl[N];
int f[2][N],a[N][N];
void solve(){
	For(i,1,n) fl[i]=rand()&1;
	Rep(i,n,1) fl[i]^=fl[1];
	memset(f,100,sizeof(f));
	f[0][1]=0;
	For(i,1,K){
		memset(f[i&1],100,sizeof(f[i&1]));
		For(j,1,n) if ((fl[j]+i+1)&1)
			For(k,1,n) if ((fl[k]+i)&1)
				f[i&1][j]=min(f[i&1][j],f[(i&1)^1][k]+a[k][j]);
	}
	ans=min(ans,f[0][1]);
}
int main(){
	srand(time(NULL));
	ans=1<<30;
	scanf("%d%d",&n,&K);
	For(i,1,n) For(j,1,n) scanf("%d",&a[i][j]);
	for (;1.0*clock()/CLOCKS_PER_SEC<=1.0;solve());
	printf("%d\n",ans);
}
/*
+dp? 
! 
*/