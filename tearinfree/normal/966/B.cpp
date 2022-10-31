#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <utility>
#include <queue>
#include <functional>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <iostream>

using namespace std;
typedef long long lli;
typedef pair<int,int> pii;
typedef pair<lli,int> pli;
typedef pair<lli,lli> pll;

int _abs_int(int a) {
	return a<0 ? -a : a;
}
lli _abs_lli(lli a) {
	return a<0 ? -a : a;
}

int n,r1,r2;

pli ps[300001];
int r1_nxt[300001],r2_nxt[300001];

int main() {
	scanf("%d%d%d",&n,&r1,&r2);
	for(int i=1;i<=n;i++) {
		scanf("%lld",&ps[i].first); ps[i].second = i;
	}

	int swap_flag = 0;

	sort(ps+1,ps+n+1);
	for(int i=1;i<=n;i++) {
		lli val = (r1 + ps[i].first - 1) / ps[i].first;
		r1_nxt[i] = min(val, n+1ll);
		
		val = (r2 + ps[i].first - 1) / ps[i].first;
		r2_nxt[i] = min(val, n+1ll);
	}
	
	int mx = 0;
	for(int i=n;i;i--) {
		if(mx!=0 && i + r1_nxt[i] - 1 < mx) {
			puts("Yes");
			printf("%d %d\n",r1_nxt[i], n-mx+1);
			
			for(int j=i;j<i+r1_nxt[i]; j++) printf("%d ",ps[j].second);
			puts("");
			for(int j=mx;j<=n;j++) printf("%d ",ps[j].second);

			return 0;
		}
		if(i+r2_nxt[i]-1 <= n) mx = max(mx,i);
	}
	mx=0;
	for(int i=n;i;i--) {
		if(mx!=0 && i + r2_nxt[i] - 1 < mx) {
			puts("Yes");
			printf("%d %d\n",n-mx+1, r2_nxt[i]);
			
			for(int j=mx;j<=n;j++) printf("%d ",ps[j].second);
			puts("");
			for(int j=i;j<i+r2_nxt[i]; j++) printf("%d ",ps[j].second);

			return 0;
		}
		if(i+r1_nxt[i]-1 <= n) mx = max(mx,i);
	}
	puts("No");
	
	return 0;
}