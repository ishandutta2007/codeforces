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
char A[100100], B[100100];

int main() {
	int t;
	scanf("%d",&t);

	while(t--) {
		scanf("%d",&N);
		scanf(" %s",A);
		scanf(" %s",B);
		int n[2] = {0,0}, m[2] = {0,0};
		for (int i=0;i<N;i++) {
			n[A[i]-'0']++;
			m[B[i]-'0']++;
		}
		int ans = INF;
		if (n[0]==m[0]&&n[1]==m[1]) {
			int c = 0;
			for (int i=0;i<N;i++) {
				c += (A[i]!=B[i]);
			}
			ans = min(ans,c);
		}
		if (n[0]+1==m[1]&&n[1]-1==m[0]) {
			int c = 0;
			for (int i=0;i<N;i++) {
				c += (A[i]==B[i]);
			}
			ans = min(ans,c);
		}
		if (ans==INF) puts("-1");
		else printf("%d\n",ans);
	}

	return 0;
}