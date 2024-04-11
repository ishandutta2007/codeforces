#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;

int gcd(int a, int b) {
	return a?gcd(b%a,a):b;
}

int N;
int nxt[100100];
int fast[100100];
int A[100100];

pii fin(int a, int dep = 0) {
	if (dep==N+1) {
		return {-1,-1};
	}
	if (gcd(A[a],A[nxt[a]])==1) {
		int b = nxt[a];
		nxt[a] = nxt[b];
		return {a,b};
	}
	pii t = fin(fast[a]==a?nxt[a]:fast[a], dep+1);
	fast[a] = t.first;
	return t;
}

int main() {
	int tt;

	scanf("%d",&tt);
	while(tt--) {
		scanf("%d",&N);
		for (int i=0;i<N;i++) {
			scanf("%d",&A[i]);
			fast[i] = i;
			nxt[i] = (i+1)%N;
		}
		int cur = 0;
		vector<int> lis;
		while(lis.size()<N) {
			pii t = fin(cur);
			if (t.first==-1) break;
			cur = nxt[t.first];
			lis.push_back(t.second);
		}
		printf("%d ",lis.size());
		for (int &v : lis) printf("%d ",v+1);
		puts("");
	}

	return 0;
}