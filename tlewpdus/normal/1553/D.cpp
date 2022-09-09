#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

char S[100100], T[100100];

int main() {
	int tt;
	scanf("%d",&tt);
	while(tt--) {
		scanf(" %s",S);
		scanf(" %s",T);
		int N = strlen(S);
		int M = strlen(T);
		reverse(S,S+N);
		reverse(T,T+M);
		int curp = 0;
		int p = 0;
		for (int i=0;i<N;i++) {
			if (p<M&&i%2==curp&&S[i]==T[p]) {
				curp^=1;
				p++;
			}
		}
		puts(p==M?"YES":"NO");
	}

	return 0;
}