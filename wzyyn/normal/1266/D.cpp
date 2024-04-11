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
#define y1 ysghysgsygshc
using namespace std;
const int N=500005;
int n,m,ans,top,q[N];
ll deg[N],qv[N];
int qx[N],qy[N];
int op(ll x){
	assert(x!=0);
	return x<0?-1:1;
}
int main(){
	scanf("%d%d",&n,&m);
	For(i,1,m){
		int x,y,v;
		scanf("%d%d%d",&x,&y,&v);
		deg[x]+=v; deg[y]-=v;
	}
	For(i,1,n){
		if (!deg[i]) continue;
		for (;top&&deg[i]&&op(deg[q[top]])!=op(deg[i]);){
			ll val=min(abs(deg[q[top]]),abs(deg[i]));
			qx[++ans]=q[top]; qy[ans]=i; qv[ans]=val;
			if (deg[q[top]]<0) swap(qx[ans],qy[ans]);
			deg[q[top]]+=(deg[q[top]]<0?val:-val);
			deg[i]+=(deg[i]<0?val:-val);
			if (!deg[q[top]]) --top;
		}
		if (deg[i]) q[++top]=i;
	}
	printf("%d\n",ans);
	For(i,1,ans) printf("%d %d %lld\n",qx[i],qy[i],qv[i]);
}