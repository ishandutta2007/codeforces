#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;

char S[200100];
bool exi[30];

int main() {
	int T;
	scanf("%d",&T);
	while(T--) {
		scanf(" %s",S);
		int N = strlen(S);
		for (int i=0;i<26;i++) exi[i] = 0;
		int ans = N-1;
		for (int i=N-1;i>=0;i--) {
			if (!exi[S[i]-'a']) {
				exi[S[i]-'a'] = true;
				ans = i;
			}
		}
		printf("%s\n",S+ans);
	}

	return 0;
}