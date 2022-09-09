#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;

int n, m;
int ans[5010];

int main() {
	scanf("%d%d",&n,&m);
	if (n/2*((n-1)/2)<m) {
		puts("-1");
		return 0;
	}
	int cnt = n/2*((n-1)/2);
	for (int i=0;i<n;i++) ans[i] = i+1;
	int p = n-1, rem = ((n-1)/2)-1;
	for (;cnt>m;cnt--) {
		if (rem==0) {
			ans[p] = (int)(1e9)-(n-p)*100000;
			p--;
			rem = p/2-1;
		}
		else {
			ans[p] += 2;
			rem--;
		}
	}
	for (int i=0;i<n;i++) printf("%d ",ans[i]);puts("");

	return 0;
}