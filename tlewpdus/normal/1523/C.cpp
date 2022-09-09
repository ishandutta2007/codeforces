#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;

int N;
int par[1010];
int key[1010];
int A[1010];

int main () {
	int tt;

	scanf("%d",&tt);
	while(tt--) {
		scanf("%d",&N);
		A[0] = 0;
		key[0] = 1;
		for (int i=1;i<=N;i++) {
			scanf("%d",&A[i]);
			int j = i-1;
			while(j>=0) {
				if (key[j]==A[i]) {
					key[j]++;
					par[i] = j;
					key[i] = 1;
					break;
				}
				j = par[j];
			}
			int p = i;
			vector<int> v;
			while(p) {
				v.push_back(p);
				p = par[p];
			}
			for (int j=(int)v.size()-1;j>=0;j--) {
				printf("%d",A[v[j]]);
				if (j!=0) printf(".");
			}
			puts("");
		}
	}

	return 0;
}