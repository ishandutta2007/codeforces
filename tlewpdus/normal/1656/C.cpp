#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;

int N;
int A[100100];

int main() {
	int T;

	scanf("%d",&T);
	while(T--) {
		scanf("%d",&N);
		for (int i=0;i<N;i++)scanf("%d",&A[i]);
		int t = 0;
		for (int i=0;i<N;i++) {
			if (A[i]<=1) t |= (1<<(A[i]));
		}
		if (t==3) puts("NO");
		else if (t==0 || t==1) puts("YES");
		else {
			sort(A,A+N);
			bool mang = false;
			for (int i=0;i+1<N;i++) {
				if (A[i]+1==A[i+1]) mang = true;
			}
			if (mang) puts("NO");
			else puts("YES");
		}
	}

	return 0;
}