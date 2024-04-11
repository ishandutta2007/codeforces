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
const int N=600005;
vector<int> e[N];
int n,m,A,B,C;
int q[N],dA[N],dB[N],dC[N];
ll v[N];
void SSSP(int S,int *dis){
	For(i,1,n) dis[i]=-1;
	int h=0,t=1;
	q[++t]=S; dis[S]=0;
	while (h!=t){
		int x=q[++h];
		for (auto i:e[x])
			if (dis[i]==-1){
				dis[i]=dis[x]+1;
				q[++t]=i;
			}
	}
}
void solve(){
	scanf("%d%d%d%d%d",&n,&m,&A,&B,&C);
	For(i,1,n) e[i].resize(0);
	For(i,1,m) scanf("%lld",&v[i]);
	sort(v+1,v+m+1);
	For(i,1,m) v[i]+=v[i-1];
	For(i,1,m){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].PB(y); e[y].PB(x);
	}
	SSSP(A,dA);
	SSSP(B,dB); 
	SSSP(C,dC);
	ll ans=1ll<<60; 
	For(i,1,n)
		if (dA[i]+dB[i]+dC[i]<=m)
			ans=min(ans,v[dA[i]+dB[i]+dC[i]]+v[dB[i]]);
	printf("%lld\n",ans);
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}