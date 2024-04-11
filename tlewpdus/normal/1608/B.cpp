#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;

void print(int k) {
	printf("%d ",k);
}

int main() {
	int t;

	scanf("%d",&t);
	while(t--) {
		int N, A, B;
		scanf("%d%d%d",&N,&A,&B);
		if (A+B>N-2||abs(A-B)>1) {
			puts("-1");
			continue;
		}
		if (A>=B) {
			int l = 1, r = N;
			print(l++);
			int s = 1;
			for (int i=0;i<A+B;i++,s=1-s) {
				if (s==1) print(r--);
				else print(l++);
			}
			if (s==1) {
				while(l<=r) print(l++);
			}
			else {
				while(l<=r) print(r--);
			}
		}
		else {
			int l = 1, r = N;
			print(r--);
			int s = 0;
			for (int i=0;i<A+B;i++,s=1-s) {
				if (s==1) print(r--);
				else print(l++);
			}
			if (s==1) {
				while(l<=r) print(l++);
			}
			else {
				while(l<=r) print(r--);
			}
		}
		puts("");
	}

	return 0;
}