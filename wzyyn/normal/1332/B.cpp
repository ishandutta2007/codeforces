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
const int pri[]={0,2,3,5,7,11,13,17,19,23,29,31};
int co[1005];
void solve(){
	static int vis[20],n;
	memset(vis,0,sizeof(vis));
	scanf("%d",&n);
	For(i,1,n){
		int x;
		scanf("%d",&x);
		For(j,1,11) if (x%pri[j]==0) co[i]=j;
		vis[co[i]]=1;
	}
	For(i,1,11) vis[i]+=vis[i-1];
	printf("%d\n",vis[11]);
	For(i,1,n) printf("%d ",vis[co[i]]);
	puts("");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}