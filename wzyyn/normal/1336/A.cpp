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
const int N=200005;
int n,k,a[N],sz[N];
vector<int> e[N];
void dfs(int x,int y){
	sz[x]=1;
	for (auto i:e[x]) if (i!=y)
		a[i]=a[x]+1,dfs(i,x),sz[x]+=sz[i];
}
int main(){
	scanf("%d%d",&n,&k);
	For(i,1,n-1){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].PB(y); e[y].PB(x);
	} 
	dfs(1,0);
	For(i,1,n) a[i]=a[i]-sz[i]+1;
	sort(a+1,a+n+1,greater<int>());
	ll ans=0;
	For(i,1,k) ans+=a[i];
	printf("%lld\n",ans);
}