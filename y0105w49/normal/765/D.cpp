#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
const ld eps=1e-11;
typedef complex<int> pt;
const int inf=1e9+99;
#define fi first
#define se second
#define pb push_back

int fail() {
	printf("-1\n");
	return 0;
}
int main() {
	const int N=100<<10;
	int n;
	scanf("%d",&n);
	static int f[N];
	for(int i=1;i<=n;i++) scanf("%d",f+i);
	vector<int> fixed;
	for(int i=1;i<=n;i++) if(f[f[i]]!=f[i]) return fail();
	for(int i=1;i<=n;i++) if(f[i]==i) fixed.pb(i);
	int m=(int)fixed.size();
	static int g[N],h[N],ih[N];
	for(int i=1;i<=m;i++) h[i]=fixed[i-1];
	for(int i=1;i<=m;i++) ih[h[i]]=i;
	for(int i=1;i<=n;i++) g[i]=ih[f[i]];

	printf("%d\n",m);
	for(int i=1;i<=n;i++) printf("%d%c",g[i]," \n"[i==n]);
	for(int i=1;i<=m;i++) printf("%d%c",h[i]," \n"[i==m]);
}