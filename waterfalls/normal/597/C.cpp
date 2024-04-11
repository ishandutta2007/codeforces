#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,k;

ll ft[13][100013];
void update(int i, int j, ll v) { while (i<=n+1) ft[j][i]+=v, i+=i&(-i); }
ll query(int i, int j) { return i>0 ? ft[j][i]+query(i-(i&(-i)),j) : 0; }

int main() {
	scanf("%d%d",&n,&k);
	update(1,0,1);
	for (int i=1;i<=n;i++) {
		int a;
		scanf("%d",&a);
		a+=1;
		for (int j=k+1;j>0;j--) update(a,j,query(a,j-1));
	}
	printf("%lld\n",query(n+1,k+1));

	return 0;
}