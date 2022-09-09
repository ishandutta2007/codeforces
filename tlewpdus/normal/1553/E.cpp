#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int N;
int bit[300100];
void init() {
	for (int i=0;i<=N;i++) bit[i] = 0;
}
void upd(int idx, int val) {
	idx++;
	while(idx) {
		bit[idx] += val;
		idx -= idx&-idx;
	}
}
int getv(int idx) {
	idx++;
	int ans = 0;
	while(idx<=N) {
		ans += bit[idx];
		idx += idx&-idx;
	}
	return ans;
}

ll M;
int P[300100];
int Q[300100];
int cnt[300100];

int vis[300100];
bool chk(int off) {
	for (int i=0;i<N;i++) vis[i] = 0;
	int moong = 0;
	for (int i=0;i<N;i++) {
		if (vis[i]) continue;
		int p = i;
		do {
			vis[p] = 1;
			p = (P[p]+off)%N;
		} while(p!=i);
		moong++;
	}
	return N-moong<=M;
}

int main() {
	int tt;
	scanf("%d",&tt);
	while(tt--) {
		scanf("%d%lld",&N,&M);
		for (int i=0;i<N;i++) cnt[i] = 0;
		for (int i=0;i<N;i++) {
			scanf("%d",&P[i]); P[i]--;
			cnt[(i-P[i]+N)%N]++;
			Q[P[i]] = i;
		}
		vector<int> ans;
		for (int i=0;i<N;i++) {
			if (cnt[i]>=N/3-2) {
				if (chk(i)) ans.push_back(i);
			}
		}
		printf("%d ",ans.size());
		for (int &v : ans) printf("%d ",v); puts("");
	}

	return 0;
}