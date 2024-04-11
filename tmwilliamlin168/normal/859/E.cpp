#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
typedef long long ll;
const ll mod=1000000007;

const int N=201000;
int n,f[N],sz[N],u,v,cyc[N];
ll ret=1;

int find(int u) { return f[u]==u?u:f[u]=find(f[u]); }
int main() {
	scanf("%d",&n);
	rep(i,1,2*n+1) f[i]=i,sz[i]=1;
	rep(i,0,n) {
		scanf("%d%d",&u,&v);
		if (u==v) {
			u=find(u);
			cyc[u]=2;
			continue;
		}
		u=find(u); v=find(v);
		if (find(u)!=find(v)) {
			f[u]=v;
			sz[v]+=sz[u];
			cyc[v]|=cyc[u];
		} else {
			cyc[u]=1;
		}
	}
	rep(i,1,2*n+1) if (find(i)==i) {
		if (cyc[i]==1) ret=ret*2%mod;
		else if (cyc[i]==0) ret=ret*sz[i]%mod;
	}
	printf("%lld\n",ret);
}