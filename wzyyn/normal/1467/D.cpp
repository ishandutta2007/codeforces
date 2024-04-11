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

const int N=5005;
const int mo=1000000007;
int n,k,Q;
int a[N],f[N][N],F[N];
int main(){
	scanf("%d%d%d",&n,&k,&Q);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,1,n) f[0][i]=1;
	For(i,1,k) For(j,1,n) f[i][j]=(f[i-1][j-1]+f[i-1][j+1])%mo;
	For(i,1,n) For(j,0,k) F[i]=(F[i]+1ll*f[j][i]*f[k-j][i])%mo;
	int ans=0;
	For(i,1,n) ans=(ans+1ll*F[i]*a[i])%mo;
	while (Q--){
		int x;
		scanf("%d",&x);
		ans=(ans+mo-1ll*F[x]*a[x]%mo)%mo;
		scanf("%d",&a[x]);
		ans=(ans+1ll*F[x]*a[x])%mo;
		printf("%d\n",ans);
	}
}