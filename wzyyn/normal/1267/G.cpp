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
const int N=105,M=10005;
int n,x,S,a[N];
double f[N][M],C[N][N],ans;
int main(){
	f[0][0]=1;
	scanf("%d%d",&n,&x);
	For(i,0,n) C[i][0]=1;
	For(i,1,n) For(j,1,i) C[i][j]=C[i-1][j]+C[i-1][j-1];
	For(i,1,n) scanf("%d",&a[i]),S+=a[i];
	For(i,1,n) Rep(j,i-1,0) For(k,a[i],S) f[j+1][k]+=f[j][k-a[i]];
	For(i,0,n-1) For(j,0,S)	ans+=f[i][j]/C[n][i]*min(1.0*(S-j)/(n-i),(1.0*n/(n-i)+1)*x/2);
	printf("%.10lf\n",ans);
}
/*
4 30
50 60 60 80
*/