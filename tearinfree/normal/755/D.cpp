#include <stdio.h>

typedef long long lli;

int n,k;
long long tree[1000001];

void Update(int node)
{
	while(node<=n) {
		tree[node]++;
		node+=node&(-node);
	}
}

lli Sum(int node)
{
	lli res=0;
	while(node) {
		res+=tree[node];
		node-=node&(-node);
	}
	return res;
}

int main()
{
	scanf("%d %d",&n,&k);

	if(k>n/2) k=(n-k);
	int x=1;
	long long res=1;
	for(int t=0;t<n;t++) {
		if(x+k>n) {
			int next=(x+k)%n;
			res+=Sum(n)-Sum(x);
			res+=Sum(next-1);
		}
		else {
			res+=Sum(x+k-1)-Sum(x);
		}
		res++;
		Update(x);
		x=(x+k);
		while(x>n) x-=n;
		Update(x);

		printf("%lld ",res);
	}

	return 0;
}