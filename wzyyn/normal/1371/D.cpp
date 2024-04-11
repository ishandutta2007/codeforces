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
#define all(v) v.begin(),v.end()
using namespace std;
const int N=305;
int n,m,k,vis[N];
int v[N],a[N],ans[N][N];
void solve(){
	scanf("%d%d",&n,&k);
	printf("%d\n",(k%n!=0)*2);
	For(i,1,n) v[i]=k/n+(k%n>=i),a[i]=v[i];
	For(i,1,n) For(j,1,n) ans[i][j]=0;
	For(i,1,n){
		memset(vis,0,sizeof(vis));
		For(j,1,v[i]){
			int p=0;
			For(k,1,n) if (!vis[k]&&a[k]>a[p]) p=k;
			vis[p]=1; ans[i][p]=1; --a[p];
		}
	}
	For(i,1,n){
		For(j,1,n) printf("%d",ans[i][j]);
		puts("");
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}