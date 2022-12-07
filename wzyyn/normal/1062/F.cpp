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
const int N=300005;
int n,m,ans,x[N],y[N];
int q[N],deg[N],cnt[N];
vector<int> e[N];
void topo_sort(){
	int h=0,t=0;
	For(i,1,n) if (!deg[i]) q[++t]=i;
	while (h!=t){
		int x=q[++h];
		if (h==t) cnt[x]+=n-t;
		else if (h+1==t){
			bool flg=0;
			for (auto i:e[q[t]])
				if (deg[i]==1) flg=1;
			cnt[x]+=(flg?-n:n-t);
		}
		else cnt[x]-=n;
		for (auto i:e[x])
			if (!--deg[i]) q[++t]=i;
	}
}
int main(){
	scanf("%d%d",&n,&m);
	For(i,1,m) scanf("%d%d",&x[i],&y[i]);
	For(i,1,m) e[x[i]].PB(y[i]),++deg[y[i]];
	topo_sort();
	For(i,1,n) e[i].resize(0);
	For(i,1,m) e[y[i]].PB(x[i]),++deg[x[i]];
	topo_sort();
	For(i,1,n) if (cnt[i]>=n-2) ++ans;
	printf("%d\n",ans);
}