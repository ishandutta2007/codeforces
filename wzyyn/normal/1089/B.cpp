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
const int N=305;
bool e[N][N],vis[N];
int id[N][N],mat[N],n,m;
bool dfs(int x,int n){
	vis[x]=1;
	random_shuffle(id[x]+1,id[x]+n+1);
	For(i,1,n) if (id[x][i]!=x&&e[x][id[x][i]]){
		int y=id[x][i],z=mat[y];
		if (vis[z]) continue;
		mat[x]=y; mat[y]=x; mat[z]=0;
		if (!z||dfs(z,n)) return 1;
		mat[x]=0; mat[y]=z; mat[z]=y;
	}
	return 0;
}
int HeiHei(int n){
	int ans=0;
	memset(mat,0,sizeof(mat));
	For(i,1,n) For(j,1,n) id[i][j]=j;
	For(i,1,5){
		For(x,1,n)
			if (!mat[x]){
				memset(vis,0,sizeof(vis));
				dfs(x,n);
			}
		int now=0;
		For(x,1,n) now+=(mat[x]!=0);
		ans=max(ans,now); 
	}
	return ans/2;
}
//traditional art
//: 
void solve(){
	scanf("%d%d",&n,&m);
	memset(e,0,sizeof(e));
	For(i,1,n){
		char s[N]; 
		scanf("%s",s+1);
		e[i][i+n]=e[i+n][i]=1;
		For(j,1,m) if (s[j]=='1'){
			e[i][j+n+n]=e[i+n][j+n+n]=1;
			e[j+n+n][i]=e[j+n+n][i+n]=1;
		}
	}
	printf("%d\n",HeiHei(n+n+m)-n);
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}