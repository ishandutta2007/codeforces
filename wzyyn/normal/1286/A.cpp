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
int n,a[N],f[N][N][2];
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	memset(f,30,sizeof(f));
	f[0][0][0]=f[0][0][1]=0;
	For(i,1,n) For(j,0,i-1) For(k,0,1) For(l,0,1)
		if (!a[i]||(a[i]+l)%2==0)
			f[i][j+l][l]=min(f[i][j+l][l],f[i-1][j][k]+(k!=l));
	printf("%d\n",min(f[n][n-n/2][0],f[n][n-n/2][1]));
}