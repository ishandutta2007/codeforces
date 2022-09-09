#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;

int N;
vector<int> lis[210];
ll inv[210];
ll D[210][210];

ll ipow(ll a, ll n) {
	if (!n) return 1;
	ll t = ipow(a,n/2);
	return t*t%MOD*(n%2?a:1)%MOD;
}

vector<int> path;
bool pdfs(int here, int p, int tar) {
	path.push_back(here);
	if (here==tar) return true;
	for (int &there : lis[here]) {
		if (there==p) continue;
		if (pdfs(there,here,tar)) return true;
	}
	path.pop_back();
	return false;
}
int sdfs(int here, int p) {
	int sz = 1;
	for (int &there : lis[here]) {
		if (there!=p) sz += sdfs(there,here);
	}
	return sz;
}

int main () {
	for (int i=1;i<=205;i++) inv[i] = ipow(i,MOD-2);
	scanf("%d",&N);
	for (int i=0;i<N-1;i++) {
		int a, b;
		scanf("%d%d",&a,&b); --a; --b;
		lis[a].push_back(b);
		lis[b].push_back(a);
	}
	for (int i=0;i<=N;i++) D[0][i] = 1;
	for (int i=1;i<=N;i++) {
		for (int j=1;j<=N;j++) {
			D[i][j] = (D[i-1][j]+D[i][j-1])*inv[2]%MOD;
		}
	}
	ll ans = 0;
	for (int i=0;i<N;i++) {
		for (int j=i+1;j<N;j++) {
			path.clear();
			pdfs(i, -1, j);
//			for (int &v : path) printf("%d ",v+1); puts("");
			for (int k=0;k<path.size();k++) {
				int v1 = (k?path[k-1]:-1);
				int v2 = (k+1==path.size()?-1:path[k+1]);
				int s = 1;
				for (int &w : lis[path[k]]) {
					if (w==v1||w==v2) continue;
					s += sdfs(w, path[k]);
				}
//				printf("(%d, %d) : %d / %d * %d\n",i+1,j+1,k,(int)path.size()-1,s);
				ans = (ans+D[(int)path.size()-1-k][k]*s)%MOD;
			}
		}
	}
	printf("%lld\n",ans%MOD*inv[N]%MOD);

	return 0;
}