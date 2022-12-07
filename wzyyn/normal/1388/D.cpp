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
int n,b[N],q[N],deg[N];
vector<int> e[N],f[N];
ll a[N],ans;
void add(int x,int y){
	deg[y]++;
	f[x].PB(y);
}
void dfs(int x){
	for (auto i:e[x]){
		dfs(i);
		if (a[i]>0)
			add(i,x),a[x]+=a[i];
		else add(x,i);
	}
	ans+=a[x];
}
void topo(){
	int h=0,t=0;
	For(i,1,n)
		if (deg[i]==0)
			q[++t]=i;
	while (h!=t){
		int x=q[++h];
		printf("%d ",x);
		for (auto i:f[x])
			if (!--deg[i]) q[++t]=i;
	}	
}
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%lld",&a[i]);
	For(i,1,n) scanf("%d",&b[i]);
	For(i,1,n) if (b[i]!=-1) e[b[i]].PB(i);
	For(i,1,n) if (b[i]==-1) dfs(i);
	printf("%lld\n",ans);
	topo();
}