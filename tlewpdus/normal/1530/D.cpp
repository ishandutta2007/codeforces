#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int N;
int P[200100];
int V[200100];
int C[200100];

int main() {
	int tt;

	scanf("%d",&tt);
	while(tt--) {
		scanf("%d",&N);
		for (int i=0;i<N;i++) C[i] = 0;
		for (int i=0;i<N;i++) {
			scanf("%d",&P[i]); P[i]--;
			C[P[i]]++;
			V[i] = 0;
		}
		int c = 0;
		int pst = -1, fst = -1;
		for (int i=0;i<N;i++) {
			if (C[i]||V[i]) continue;
			if (fst==-1) fst = i;
			P[pst] = i;
			int p = i;
			V[p] = 1;
			while(V[P[p]]==0) {
				p = P[p];
				V[p] = 1;
			}
			pst = p;
			c++;
		}
		if (pst!=-1) P[pst] = fst;
		printf("%d\n",N-c);
		for (int i=0;i<N;i++) printf("%d ",P[i]+1);
		puts("");
	}

	return 0;
}