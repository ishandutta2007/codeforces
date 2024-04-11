#include<bits/stdc++.h>
using namespace std;
const int N = 22;
typedef long long LL;
void no() {
	printf("NO\n");
	exit(0);
}
map<int, int> blg, vst;
LL s[N];
int inf = 1e9 + 7;
int ans[N], go[N];
const int K = 1 << 15;
vector<int> cyc[K];
int dp[K];
int main() {
	int n;
	scanf("%d", &n);
	LL sum = 0;
	for(int i(0); i < n; i++) {
		int k;
		scanf("%d", &k);
		for(int j(0); j < k; j++) {
			int x;
			scanf("%d", &x);
			sum += x;
			blg[x] = i;
			s[i] += x;
		}
	}
	if(sum % n) {
		no();
	}
	sum /= n;
	map<int, int> vst;
	int tim = 0;
	for(auto tmp : blg) {
		int x = tmp.first;
		int b = tmp.second;
		if(vst.count(x)) continue;
		++tim;
		bool flag = true;
		static vector<int> vec;
		vec.clear();
		while(!vst.count(x)) {
			vst[x] = tim;
			vec.push_back(x);
			x = sum - (s[b] - x);
			if(x <= -inf || x >= inf) {
				flag = false;
				break;
			}
			if(blg.count(x) == 0) {
				flag = false;
				break;
			}else {
				b = blg[x];
			}
		}
		if(!flag) continue;
		if(vst[x] == tim) {
			vector<int> v1;
			int msk = 0;
			for(;;) {
				v1.push_back(vec.back());
				int m1 = 1 << blg[vec.back()];
				if(msk & m1) {
					flag = false;
					break;
				}
				msk |= m1;
				vec.pop_back();
				if(v1.back() == x) break;
			}
			if(flag) cyc[msk] = v1;
		}
	}
	memset(dp, -1, sizeof(dp));
	dp[0] = 0;
	for(int i(1); i < (1 << n); i++) {
		for(int j(i); j; j = (j - 1) & i) {
			if(!cyc[j].empty() && dp[i - j] != -1) {
				dp[i] = j;
				break;
			}
		}
	}
	if(dp[(1 << n) - 1] == -1) no();
	int i = (1 << n) - 1;
	printf("YES\n");
	while(i) {
		for(int x(0); x < (int)cyc[dp[i]].size(); x++) {
			int v = cyc[dp[i]][x];
			ans[blg[v]] = v;
			go[blg[v]] = blg[cyc[dp[i]][(x + 1) % (int)cyc[dp[i]].size()]];
		}
		i -= dp[i];
	}
	for(int i(0); i < n; i++) printf("%d %d\n", ans[i], go[i] + 1);
}