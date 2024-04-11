#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;

char S[200100];

int main() {
	int T;

	scanf("%d",&T);
	while(T--) {
		scanf(" %s",S);
		int sum = 0;
		int N = strlen(S);
		bool mang = false;
		for (int i=0;i<N;i++) {
			if (S[i]=='A') sum++;
			else sum--;
			if (sum<0) {
				mang = true;
			}
		}
		if (S[N-1]!='B') mang = true;
		puts(mang?"NO":"YES");
	}

	return 0;
}