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
int vis[205],n,T,x;
void solve(){
	scanf("%d%d",&n,&T);
	memset(vis,0,sizeof(vis));
	For(i,1,n) scanf("%d",&x),vis[x]=1;
	for (x=1;T>=0;T-=1-vis[x],x++);
	printf("%d\n",x-2);
}
int main(){
	#ifdef zyy
		freopen("1.in","r",stdin);
	#endif
	int T;
	scanf("%d",&T);
	while (T--) solve(); 
}