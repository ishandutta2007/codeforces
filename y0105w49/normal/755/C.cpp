#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef complex<ld> pt;
typedef long long ll;
#define fi first
#define se second
#define pb push_back



const int N=10<<10;
int rk[N],da[N],sz[N];
int djrt(int u) {
	if(da[u]==u) return u;
	return da[u]=djrt(da[u]);
}
int djun(int u,int v) {
	// cerr<<"un "<<u<<","<<v<<endl;
	u=djrt(u), v=djrt(v);
	if(u==v) return 0;
	if(rk[u]>rk[v]) swap(u,v);
	if(rk[u]==rk[v]) ++rk[v];
	da[u]=v;
	sz[v]+=sz[u];
	return 1;
}




int _main() {
	int n,p; cin>>n;
	for(int i=1;i<=n;i++) da[i]=i, sz[i]=1;
	for(int i=1;i<=n;i++) cin>>p, djun(i,p);
	int Z=0;
	for(int i=1;i<=n;i++) if(djrt(i)==i) ++Z;
	return Z;
}
int main() {
	cout<<_main()<<endl;
}