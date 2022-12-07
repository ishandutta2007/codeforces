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
const int N=2005;
int n,h,l,r;
int f[N][N];
void solve(){
	scanf("%d%d%d%d",&n,&h,&l,&r);
	memset(f,233,sizeof(f));
	f[0][0]=0;
	For(i,1,n){
		int x;
		scanf("%d",&x);
		For(j,0,h-1){
			f[i][(j+x)%h]=max(f[i][(j+x)%h],f[i-1][j]);
			f[i][(j+x-1)%h]=max(f[i][(j+x-1)%h],f[i-1][j]);
		}
		For(j,l,r) f[i][j]++;
	}
	int ans=0;
	For(i,0,h-1) ans=max(ans,f[n][i]);
	printf("%d\n",ans);
}
int main(){
	solve();
}