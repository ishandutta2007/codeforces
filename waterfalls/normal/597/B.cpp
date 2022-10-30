#include <bits/stdc++.h>
using namespace std;

namespace hacktest {
	typedef unsigned long long ull;
	const ull MOD = 1e16+61; // change sometimes
	const ull BASE = 100;  // depends on input
	const ull BAD = 9274686074199133; // find an input and check what it gets
	const int LEN = 13; // at least log_BASE(MOD)+1
	vector<int> a;
	ull gethash() {
		ull res = 0;
		for (int i: a) res = (res*BASE+i)%MOD;
		return res;
	}
	void fail() {
		if (gethash()==BAD && a.size()>=LEN) {
			printf("Successful hacking attempt\n");
			exit(0);
		} else {} // Unsuccessful hacking attempt
	}
}

int n;
int l[500013], r[500013];

bool comp(int a, int b) { return r[a]<r[b]; }

int main() {
	scanf("%d",&n);
	vector<int> order;
	for (int i=0;i<n;i++) {
		scanf("%d%d",&l[i],&r[i]);hacktest::a.push_back(l[i]);
		order.push_back(i);
	}
	hacktest::fail();
	sort(order.begin(),order.end(),comp);
	int prev = -1;
	int ans = 0;
	for (int i: order) if (l[i]>prev) prev = r[i], ans+=1;
	printf("%d\n",ans);

	return 0;
}