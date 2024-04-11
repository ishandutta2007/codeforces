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
const int N=5005;
const int mo=1000000007;
int n,a[N],ans[N*2];
int f[N][N*2];
int main(){
	scanf("%d",&n);
	For(i,1,n-1) scanf("%d",&a[i]);
	For(i,1,n){
		For(j,1,n*2) f[i][j]=f[i-1][j-1];
		int t=1,tt=1;
		For(j,1,i-1) t=1ll*t*a[j]%mo;
		For(j,i,n){
			ans[j-i]=(ans[j-i]+1ll*t*tt)%mo;
			tt=1ll*tt*a[j]%mo;
		}
		For(j,0,n*2) ans[j]=(ans[j]+1ll*t*f[i][j])%mo;
		int tms=1;
		For(j,i,n){
			f[i][j-i]=(f[i][j-i]+tms)%mo;
			tms=1ll*tms*(i==j?a[j]-1:a[j])%mo; 
		}
	}
	For(i,1,2*n-2)
		printf("%d ",(ans[i]+ans[i]%2*mo)/2);
}