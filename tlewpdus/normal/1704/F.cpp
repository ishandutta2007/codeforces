#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;

int G[1100];
int N;
char S[500100];

int getg(int x) {
	if (x<100) return G[x];
	return G[(x-100)%34+100];
}

int main() {
	int TT;

	for (int i=2;i<=500;i++) {
		vector<int> vec;
		for (int j=0;j<=i-2;j++) {
			vec.push_back(G[j]^G[i-2-j]);
		}
		sort(vec.begin(),vec.end());
		int past = -1;
		for (int &v : vec) {
			if (past+1<v) {
				break;
			}
			past = v;
		}
		G[i] = past+1;
	}

	scanf("%d",&TT);
	while(TT--) {
		scanf("%d",&N);
		scanf(" %s",S);
		int past = 0;
		int x = 0, c = 0;
		for (int i=0;i<N;i++) {
			c += (S[i]=='R'?1:-1);
			if (i+1==N || S[i]==S[i+1]) {
				x ^= getg(i-past+1);
				past = i+1;
			}
		}
		if (c!=0) {
			puts(c>0?"Alice":"Bob");
		}
		else {
			puts(x?"Alice":"Bob");
		}
	}

	return 0;
}