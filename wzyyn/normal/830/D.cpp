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
const int N=405;
int f[N][N*2],n;
int main(){
	scanf("%d",&n);
	f[1][0]=f[1][1]=1;
	For(i,2,n) For(j,0,n) For(k,0,n+1-j){
		f[i][j+k+1]=(f[i][j+k+1]+1ll*f[i-1][j]*f[i-1][k])%mo;
		f[i][j+k]=(f[i][j+k]+1ll*f[i-1][j]*f[i-1][k]%mo*(2*j+2*k+1))%mo;
		if (j+k) f[i][j+k-1]=(f[i][j+k-1]+1ll*f[i-1][j]*f[i-1][k]%mo*(j+k)*(j+k-1))%mo;
	}
	printf("%d\n",f[n][1])%mo;
}