#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;

int N, M;
char S[1010];

int main () {
	int tt;

	scanf("%d",&tt);
	while(tt--) {
		scanf("%d%d",&N,&M);
		scanf(" %s",S+1);
		S[0] = S[N+1] = '0';
		for (int i=0;i<M;i++) {
			vector<int> loc;
			for (int j=1;j<=N;j++) {
				if (S[j]=='0'&&(S[j-1]-'0')+(S[j+1]-'0')==1) loc.push_back(j);
			}
			for (int &v : loc) {
				S[v] = '1';
			}
			if (loc.empty()) break;
		}
		for (int i=1;i<=N;i++) printf("%c",S[i]); puts("");
	}

	return 0;
}