#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;
typedef complex<ld> pt;
#define fi first
#define se second
#define pb push_back
const ld TAU=2*acos(-1);


const int N=1<<20;
int p[N],b[N];
bool seen[N];

void dfs(int u) {
	if(seen[u]) return;
	seen[u]=1;
	dfs(p[u]);
}

int main() {
	int n; scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",p+i), --p[i];
	for(int i=0;i<n;i++) scanf("%d",b+i);

	int bb=accumulate(b,b+n,0);
	int ex=(bb+1)%2;
	int cycs=0;
	for(int i=0;i<n;i++) if(!seen[i]) dfs(i), ++cycs;
	if(cycs==1) cycs=0;

	cout<<cycs+ex<<endl;
}