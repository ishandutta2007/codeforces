#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;

struct edg {
	int j, x, y;
};

int gcd(int a, int b) {
	if (!a) return b;
	return gcd(b%a,a);
}

ll ipow(ll a, ll n) {
	if (!n) return 1;
	ll t = ipow(a,n/2);
	return t*t%MOD*(n%2?a:1)%MOD;
}

int N;
vector<edg> lis[200100];
int H[200100];
int sve[200100];

int A[200100], B[200100];
ll ans;
void dfs(int here, int par, ll t) {
	ans = (ans+t)%MOD;
	for (edg &e : lis[here]) {
		if (e.j==par) continue;
		int x = e.x;
		int y = e.y;
		while(x>1) {
			int p = sve[x];
			if (B[p]>0) B[p]--;
			else A[p]++;
			x/=p;
		}
		while(y>1) {
			int p = sve[y];
			if (A[p]>0) A[p]--;
			else B[p]++;
			H[p] = max(H[p],B[p]);
			y/=p;
		}
		dfs(e.j,here,t*e.x%MOD*ipow(e.y,MOD-2)%MOD);
		x = e.x;
		y = e.y;
		while(x>1) {
			int p = sve[x];
			if (A[p]>0) A[p]--;
			else B[p]++;
			x/=p;
		}
		while(y>1) {
			int p = sve[y];
			if (B[p]>0) B[p]--;
			else A[p]++;
			y/=p;
		}
	}
}

int main() {
	int T;
	scanf("%d",&T);
	for (int i=2;i<=200000;i++) {
		if (sve[i]) continue;
		for (int j=i;j<=200000;j+=i) {
			sve[j] = i;
		}
	}
	while(T--) {
		scanf("%d",&N);
		for (int i=0;i<N-1;i++) {
			int a, b, c, d;
			scanf("%d%d%d%d",&a,&b,&c,&d); --a; --b;
			int g = gcd(c,d);
			c/=g;
			d/=g;
			lis[a].push_back({b,d,c});
			lis[b].push_back({a,c,d});
		}
		ans = 0;
		for (int i=0;i<=N;i++) {
			A[i]=B[i]=H[i]=0;
		}
		dfs(0,-1,1);
		for (int i=0;i<=N;i++) {
			for (int j=0;j<H[i];j++) {
				ans = ans*i%MOD;
			}
		}
		printf("%lld\n",ans%MOD);
		for (int i=0;i<N;i++) lis[i].clear();
	}

	return 0;
}