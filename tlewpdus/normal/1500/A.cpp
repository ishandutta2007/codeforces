#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;

int N;
pii A[200100];
int C[5000100];
vector<pii> p[5000100];

const int MAX = 2500010;

bool distinct(pii a, pii b) {
	return (a.first!=b.first)&&(a.first!=b.second)&&(a.second!=b.first)&&(a.second!=b.second);
}

int main() {
	scanf("%d",&N);
	for (int i=0;i<N;i++) {
		scanf("%d",&A[i].first);
		A[i].second = i;
		C[A[i].first]++;
	}
	for (int i=0;i<MAX;i++) {
		if (C[i]>=4) {
			vector<int> v;
			for (int j=0;j<N;j++) {
				if (A[j].first==i) v.push_back(j);
			}
			assert(v.size()>=4);
			puts("YES");
			for (int j=0;j<4;j++) {
				printf("%d ",v[j]+1);
			}
			puts("");
			exit(0);
		}
		C[i] = 0;
	}
	for (int i=0;i<N;i++) {
		for (int j=i+1;j<N;j++) {
			int t = A[i].first+A[j].first;
			pii q = {i,j};
			for (pii &v : p[t]) {
				if (distinct(v,q)) {
					puts("YES");
					printf("%d %d %d %d\n",v.first+1,v.second+1,q.first+1,q.second+1);
					exit(0);
				}
			}
			p[t].push_back(q);
		}
	}
	puts("NO");

	return 0;
}