#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;

int N;
char A[100100], B[100100];
int tree[100100];

void init() {
	for (int i=0;i<=N;i++) tree[i] = 0;
}
void upd(int idx) {
	idx++;
	while(idx) {
		tree[idx]++;
		idx -= idx&-idx;
	}
}
int getv(int idx) {
	idx++;
	int ans = 0;
	while(idx<=N) {
		ans += tree[idx];
		idx += idx&-idx;
	}
	return ans;
}

char C[100100];
vector<int> locs[26];
bool dead[100100];
int main() {
	int ttt;
	scanf("%d",&ttt);
	while(ttt--) {
		scanf("%d",&N);
		scanf(" %s",A);
		scanf(" %s",B);
		init();
		strcpy(C,A);
		sort(C,C+N);
		if (strcmp(C,B) >= 0) {
			puts("-1");
			continue;
		}
		for (int i=N-1;i>=0;i--) {
			locs[A[i]-'a'].push_back(i);
		}
		int p = 0;
		ll ans = LINF, sum = 0;
		for (int i=0;i<N;i++) {
			while(p<N && (dead[p] || p + getv(p) < i)) p++;
			if (A[p]<B[i]) {
				ans = min(ans,sum);
				break;
			}
			int mini = N;
			for (int j=0;j<(B[i]-'a');j++) {
				if (!locs[j].empty()) {
					mini = min(mini,locs[j].back());
				}
			}
			if (mini<N) {
				ans = min(ans, sum + mini + getv(mini) - i);
			}
			if (locs[B[i]-'a'].empty()) break;
			sum += locs[B[i]-'a'].back()+getv(locs[B[i]-'a'].back())-i;
			dead[locs[B[i]-'a'].back()] = true;
			upd(locs[B[i]-'a'].back());
			locs[B[i]-'a'].pop_back();
		}
		printf("%lld\n",ans);
		for (int i=0;i<N;i++) dead[i] = 0;
		for (int i=0;i<26;i++) locs[i].clear();
	}

	return 0;
}