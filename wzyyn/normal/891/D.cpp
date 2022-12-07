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
const int N=500005;
int n,sz[N],fa[N];
vector<int> e[N];
ll ans;
void dfs(int x){
	sz[x]=1;
	for (auto i:e[x])
		if (i!=fa[x]){
			fa[i]=x;
			dfs(i);
			sz[x]+=sz[i];
		}
}
void count(){
	int sum=0;
	For(i,1,n){
		int sum=0;
		for (auto j:e[i])
			if (j!=fa[i])
				sum+=sz[j]&1;
		//cout<<
		if (sum!=(sz[i]-1)%2)
			return;
	}
	For(i,1,n) if (sz[i]%2==0)
		ans+=1ll*(n-sz[i])*sz[i];
}
ll f[N][3][2][2];
ll tmp[3][2][2];
void dp(int x){
	f[x][0][0][0]=f[x][1][0][1]=1;
	for (auto i:e[x]) if (i!=fa[x]){
		dp(i);
		memset(tmp,0,sizeof(tmp));
		For(j,0,2) For(k,0,2-j) For(jj,0,1) For(kk,0,1-jj) tmp[j+k][jj+kk][0]+=f[x][j][jj][0]*f[i][k][kk][1];
		For(j,0,2) For(k,0,2-j) For(jj,0,1) For(kk,0,1-jj) tmp[j+k][jj+kk][1]+=f[x][j][jj][1]*f[i][k][kk][1];
		For(j,0,2) For(k,0,2-j) For(jj,0,1) For(kk,0,1-jj) tmp[j+k][jj+kk][1]+=f[x][j][jj][0]*f[i][k][kk][0];
		For(j,0,2) For(k,0,2-j) if (k==1) tmp[j+k][1][0]+=f[x][j][0][0]*f[i][k][0][1];
		For(j,0,2) For(k,0,2-j) if (k==1) tmp[j+k][1][1]+=f[x][j][0][1]*f[i][k][0][1];
		memcpy(f[x],tmp,sizeof(f[x]));
	}
}
int main(){
	scanf("%d",&n);
	if (n&1) return puts("0"),0;
	For(i,1,n-1){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].PB(y); e[y].PB(x);
	}
	dfs(1);
	count();
	//cout<<ans<<endl;
	dp(1);
	printf("%lld\n",ans+f[1][2][1][1]);
}