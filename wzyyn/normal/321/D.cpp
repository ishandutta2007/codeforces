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
const int N=35;
int n,m,ans;
int a[N][N],f[N][N];
void solve(){
	int sum=0;
	For(i,1,m-1) f[m][i+m]=f[m][i]*f[m][m];
	For(i,1,n) sum+=f[m][i]*a[m][i];
	For(i,1,m-1){
		int v0=0,v1=0;
		v0+=a[i][m]+f[m][m]*a[i+m][m];
		v1-=a[i][m]+f[m][m]*a[i+m][m];
		For(j,1,m-1){
			int val=0;
			val+=a[i][j];
			val+=a[i][j+m];
			val+=a[i+m][j]*f[m][j];
			val+=a[i+m][j+m]*f[m][j+m];
			v0+=abs(val);
			val=0;
			val+=a[i][j];
			val-=a[i][j+m];
			val+=a[i+m][j]*f[m][j];
			val-=a[i+m][j+m]*f[m][j+m];
			v1+=abs(val);
		}
		sum+=max(v0,v1);
	}
	ans=max(ans,sum);
}
void dfs(int x){
	if (x>m) return solve();
	f[m][x]=1;  dfs(x+1);
	f[m][x]=-1; dfs(x+1);
}
int main(){
	scanf("%d",&n);
	m=(n+1)/2;
	ans=-(1<<30);
	For(i,1,n) For(j,1,n)
		scanf("%d",&a[i][j]);
	dfs(1);
	printf("%d\n",ans);
}