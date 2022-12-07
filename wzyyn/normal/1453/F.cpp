#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define pii pair<int,int>
#define fi first
#define se second
#define PB push_back
#define ll long long
using namespace std;
const int N=3005;
int n,a[N],S[N];
int f[N][N],g[N][N];
void solve(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,1,n) S[i]=S[i-1]+(a[i]!=0);
	For(i,0,n+1) For(j,0,n+1) g[i][j]=0;
	For(i,1,n) ++g[i][i+a[i]];
	Rep(j,n,1) For(i,1,n) g[i][j]+=g[i][j+1];
	For(i,1,n) For(j,1,n) g[i][j]+=g[i-1][j];
	For(i,0,n+1) For(j,0,n+1) f[i][j]=1<<30;
	f[1][2]=0;
	For(i,1,n) For(j,i+1,i+a[i]){
		if (j!=i+a[i]) f[i][j+1]=min(f[i][j+1],f[i][j]);
		if (i+a[i]<j+a[j]) f[j][i+a[i]+1]=min(f[j][i+a[i]+1],f[i][j]+g[j-1][j]-g[i][j]);
	}
	int ans=1<<30;
	For(i,1,n) ans=min(ans,f[i][n]+g[n-1][n]-g[i][n]);
	cout<<ans<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}