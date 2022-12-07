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
int n,a[N],f[N][N],g[N];
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	memset(f,-1,sizeof(f));
	For(i,1,n) f[i][i]=a[i];
	Rep(i,n,1) For(j,i,n) For(k,i,j-1)
		if (f[i][k]==f[k+1][j]&&f[i][k]!=-1)
			f[i][j]=f[i][k]+1;
	memset(g,30,sizeof(g));
	g[0]=0;
	For(i,1,n) For(j,i,n)
		if (f[i][j]!=-1) g[j]=min(g[j],g[i-1]+1);
	printf("%d\n",g[n]);
}