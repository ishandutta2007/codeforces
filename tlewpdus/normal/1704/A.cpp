#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;

int N, M;
char S[110], T[110];

int main() {
	int TT;

	scanf("%d",&TT);
	while(TT--) {
		scanf("%d%d",&N,&M);
		scanf(" %s",S);
		scanf(" %s",T);
		bool good = true;
		for (int i=1;i<M;i++) {
			if (S[N-M+i]!=T[i]) good = false;
		}
		bool exi = false;
		for (int i=0;i<=N-M;i++) {
			if (S[i]==T[0]) exi = true;
		}
		if (exi&&good) puts("YES");
		else puts("NO");
	}

	return 0;
}