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
int n,m,x[N],y[N];
int q[N],deg[N],rk[N];
vector<int> e[N];
bool topo(){
	int h=0,t=0;
	For(i,1,n) deg[i]=0;
	For(i,1,n) for (auto j:e[i]) ++deg[j];
	For(i,1,n) if (!deg[i]) q[++t]=i;
	while (h!=t){
		int x=q[++h]; rk[x]=h;
		for (auto i:e[x])
			if (!--deg[i]) q[++t]=i;
	}
	return t==n;
}
void solve(){
	scanf("%d%d",&n,&m);
	For(i,1,n) e[i].resize(0);
	For(i,1,m){
		int tp;
		scanf("%d%d%d",&tp,&x[i],&y[i]);
		if (tp) e[x[i]].PB(y[i]);
	}
	if (!topo())
		puts("NO");
	else{
		puts("YES");
		For(i,1,m){
			if (rk[x[i]]>rk[y[i]])
				swap(x[i],y[i]);
			printf("%d %d\n",x[i],y[i]);
		}
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}