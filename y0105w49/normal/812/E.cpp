// ayy
// ' lamo
#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld; //CARE
typedef complex<ld> pt;
#define fi first
#define se second
#define pb push_back
const ld eps=1e-8;
const int inf=1e9+99;
const ll linf=1e18+99;
const int P=1e9+7;

const int N=100<<10;
int n,a[N],p[N];
bool leaf[N];
vector<int> ch[N];

bool dfs(int u) {
	if(!ch[u].size()) {
		return leaf[u]=1;
	}
	leaf[u]=!dfs(ch[u][0]);
	for(int v:ch[u]) if(v!=ch[u][0]) assert(dfs(v)==!leaf[u]);
	return leaf[u];
}








ll C2(int x) {
	assert(x);
	return 1LL*x*(x-1)/2;
}


int32_t main() {
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",a+i);
	for(int i=2;i<=n;i++) scanf("%d",p+i);
	for(int i=1;i<=n;i++) ch[p[i]].pb(i);
	dfs(1);

	int A=0;
	vector<int> V1,V2;
	for(int i=1;i<=n;i++) if(leaf[i]) A^=a[i];
	for(int i=1;i<=n;i++) (leaf[i] ? V1 : V2).pb(a[i]);

	ll Z=0;
	if(!A) Z+=C2((int)V1.size()) + C2((int)V2.size());
	sort(V2.begin(),V2.end());
	for(int x:V1) {
		int tg=A^x;
		auto P=equal_range(V2.begin(),V2.end(),tg);
		Z+=int(P.se-P.fi);
	}
	cout<<Z<<endl;
}