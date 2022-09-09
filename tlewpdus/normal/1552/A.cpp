#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1000000007;

int N;
char S[50];
char T[50];

int main() {
	int tt;

	scanf("%d",&tt);
	while(tt--) {
		scanf("%d",&N);
		scanf(" %s",S);
		for (int i=0;i<N;i++) T[i] = S[i];
		sort(T,T+N);
		int ans = 0;
		for (int i=0;i<N;i++) ans += (S[i]!=T[i]);
		printf("%d\n",ans);
	}

	return 0;
}