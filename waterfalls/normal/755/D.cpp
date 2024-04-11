#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,k;

ll ft[1000013];
void update(int x, ll v) { while (x<=n) ft[x]+=v, x+=x&-x; }
ll query(int x) { return x>0 ? ft[x]+query(x-(x&-x)) : 0; }

int main() {
	scanf("%d%d",&n,&k);
	k = min(k,n-k);
	ll ans = 1;
	for (int i=0;i<n;i++) {
		int l = ((ll) k*i)%n;
		int r = (l+k)%n;
		int a = l+1;
		int b = r-1;
		if (b>=a) ans+=query(b+1)-query(a-1+1);
		else ans+=query(n-1+1)-query(a-1+1)+query(b+1);
		ans+=1;
		printf("%lld ",ans);
		update(l+1,1);
		update(r+1,1);
	}
	printf("\n");

	return 0;
}