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
#define y1 fdhjksa
using namespace std;
int n,m,x,vis[1005];
void solve(){
	int ans=-1;
	scanf("%d%d",&n,&m);
	memset(vis,0,sizeof(vis));
	For(i,1,n) scanf("%d",&x),vis[x]=1;
	For(i,1,m) scanf("%d",&x),ans=(vis[x]?x:ans);
	if (ans==-1) puts("NO");
	else printf("YES\n1 %d\n",ans);
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}