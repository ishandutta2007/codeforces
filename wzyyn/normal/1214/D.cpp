#include<bits/stdc++.h>
#define ll long long
#define uint unsigned
#define ull unsigned ll
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
using namespace std;
const int N=1000005;
int n,m,vis[N],cnt[N];
char s[N],mp[N];
int id(int x,int y){
	return (x-1)*m+y;
}
bool dfs(int x,int y){
	if (x>n||y>m) return 0;
	if (mp[id(x,y)]=='#') return 0;
	if (x==n&&y==m) return 1;
	if (vis[id(x,y)]) return vis[id(x,y)]==2;
	vis[id(x,y)]=(dfs(x+1,y)|dfs(x,y+1))+1;
	if (vis[id(x,y)]==2) ++cnt[x+y];
	return vis[id(x,y)]==2;
}
int main(){
	scanf("%d%d",&n,&m);
	For(i,1,n){
		scanf("%s",s+1);
		For(j,1,m) mp[id(i,j)]=s[j];
	}
	dfs(1,1);
	int ans=2;
	For(i,3,n+m-1) ans=min(ans,cnt[i]);
	printf("%d\n",ans);
}