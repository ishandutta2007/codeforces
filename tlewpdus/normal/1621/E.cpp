#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;

int N, M;
ll A[100100];
vector<pll> B[100100];
ll sum[100100];
int bord[100100];
int ans[200100];

int main() {
	int ttt;

	scanf("%d",&ttt);
	while(ttt--) {
		scanf("%d%d",&N,&M);
		for (int i=0;i<N;i++) scanf("%lld",&A[i]);
		sort(A,A+N);
		reverse(A,A+N);
		int p = 0;
		for (int i=0;i<M;i++) {
			int k;
			scanf("%d",&k);
			B[i].reserve(k);
			sum[i] = 0;
			for (int j=0;j<k;j++) {
				int a;
				scanf("%d",&a);
				B[i].emplace_back(a,p);
				sum[i] += a;
				p++;
			}
		}
		iota(bord,bord+M,0);
		sort(bord,bord+M,[](int i, int j) {
			return sum[i]*B[j].size() > sum[j]*B[i].size();
		});
		int good_cnt = 0;
		for (int id=0;id<M;id++) {
			int i = bord[id];
			if (sum[i]<=A[id]*B[i].size()) good_cnt++;
		}
		for (int i=0;i<p;i++) ans[i] = 0;
		if (good_cnt==M) {
			int bad = -1;
			for (int id = 0; id < M; id++) {
				int i = bord[id];
				for (int j = 0; j < B[i].size(); j++) {
					ll val = B[i][j].first;
					if (val*B[i].size()>=sum[i]) {
						ans[B[i][j].second] = 1;
						continue;
					}
					int s = 0, e = id - 1;
					while (s <= e) {
						int md = (s + e) / 2;
						int m = bord[md];
						if (sum[m] * (B[i].size() - 1) < (sum[i] - val) * B[m].size()) e = md - 1;
						else s = md + 1;
					}
					if (bad < s && (sum[i]-val) <= A[s]*(B[i].size()-1)) {
						ans[B[i][j].second] = 1;
					}
					else {
						ans[B[i][j].second] = 0;
					}
				}
				if (id < M - 1 && sum[i] > A[id + 1] * B[i].size()) bad = id;
			}
		}
		else {
			int bad_cnt = 0, bad_idx = -1, tot_bad = 0, max_bad = 0;
			for (int id=0;id<M;id++) {
				int i = bord[id];
				if (sum[i]>A[id]*B[i].size()) {
					tot_bad++;
					max_bad = id;
				}
				if (sum[i]>A[id]*B[i].size() && (id==0 || sum[i]>A[id-1]*B[i].size())) {
					bad_cnt++;
					bad_idx = id;
				}
			}
			if (bad_cnt<2) {
				for (int id = 0; id < M; id++) {
					int i = bord[id];
					if (bad_cnt == 0 || id == bad_idx) {
						for (int j = 0; j < B[i].size(); j++) {
							ll val = B[i][j].first;
							if (val * B[i].size() <= sum[i]) {
								ans[B[i][j].second] = 0;
								continue;
							}
							int s = id + 1, e = N - 1;
							while (s <= e) {
								int md = (s + e) / 2;
								int m = bord[md];
								if (sum[m] * (B[i].size() - 1) < (sum[i] - val) * B[m].size()) e = md - 1;
								else s = md + 1;
							}
							if (max_bad <= e && (sum[i] - val) <= A[e] * (B[i].size() - 1)) {
								ans[B[i][j].second] = 1;
							} else {
								ans[B[i][j].second] = 0;
							}
						}
					}
					if (sum[i] > A[id] * B[i].size()) break;
				}
			}
		}

		for (int i=0;i<p;i++) printf("%d",ans[i]);
		puts("");

		for (int i=0;i<M;i++) B[i].clear();
	}

	return 0;
}