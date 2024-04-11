#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;

int N, L;
char S[300100];
int rnk[300100];
pii item[300100];
int perm[300100];

int main() {
	scanf("%d",&N);
	scanf(" %s",&S);
	L = (1<<N);
	iota(perm,perm+L,0);
	for (int b=0;b<=N;b++) {
		if (b==0) {
			for (int i = 0; i < L; i++) {
				item[i] = {S[i], 0};
			}
		}else {
			for (int i=0;i<L;i++) {
				item[i] = {rnk[i], rnk[i^(1<<(b-1))]};
			}
		}
		sort(perm,perm+L,[](int a, int b){
			return item[a]<item[b];
		});
		int p = 0;
		for (int id=0;id<L;id++) {
			int i = perm[id];
			if (id && item[perm[id-1]]!=item[i]) p++;
			rnk[i] = p;
		}
	}
	int mini = INF, mint = 0;
	for (int i=0;i<L;i++) {
		if (mini>rnk[i]) {
			mini=rnk[i];
			mint=i;
		}
	}
	for (int i=0;i<L;i++) {
		printf("%c",S[mint^i]);
	}
	puts("");


	return 0;
}