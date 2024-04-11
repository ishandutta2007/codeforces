#include<bits/stdc++.h>

typedef long long ll;
typedef std::pair <int, int> pii;

const int N = 1000010;
const int INF = 0x7f7f7f7f;
const ll LINF = 0x1f1f1f1f1f1f1f1f;

int n, m, k;
int d[N], f[N], t[N], c[N];
std::pair <int, pii> arr[N], leave[N];
ll pre[N], suf[N];
bool preflag[N], sufflag[N];
int min[N];

int main(){
	scanf("%d%d%d", &n, &m, &k);
	int cnta = 0, cntl = 0;
	for (int i = 0; i < m; ++ i){
		scanf("%d%d%d%d", &d[i], &f[i], &t[i], &c[i]);
		if (f[i]){
			arr[cnta ++] = {d[i], {f[i], c[i]}};
		}
		else{
			leave[cntl ++] = {d[i], {t[i], c[i]}};
		}
	}
	std::sort(arr, arr + cnta);
	std::sort(leave, leave + cntl, std::greater <std::pair <int, pii>>());
	memset(min, 0x7f, sizeof(min));
	for (int i = 1; i <= n; ++ i){
		pre[0] += min[i];
	}
	int cnt = n;
	for (int i = 1, j = 0; i < N; ++ i){
		pre[i] = pre[i - 1];
		while (j < cnta && arr[j].first <= i){
			int sit = arr[j].second.first;
			if (min[sit] == INF){
				-- cnt;
			}
			pre[i] -= min[sit];
			min[sit] = std::min(min[sit], arr[j].second.second);
			pre[i] += min[sit];
			++ j;
		}
		if (!cnt){
			preflag[i] = true;
		}
	}
	memset(min, 0x7f, sizeof(min));
	for (int i = 1; i <= n; ++ i){
		suf[N - 1] += min[i];
	}
	cnt = n;
	for (int i = N - 2, j = 0; i >= 0; -- i){
		suf[i] = suf[i + 1];
		while (j < cntl && leave[j].first >= i){
			int sit = leave[j].second.first;
			if (min[sit] == INF){
				-- cnt;
			}
			suf[i] -= min[sit];
			min[sit] = std::min(min[sit], leave[j].second.second);
			suf[i] += min[sit];
			++ j;
		}
		if (!cnt){
			sufflag[i] = true;
		}
	}
	ll ans = LLONG_MAX;
	for (int i = 1; i < N; ++ i){
		if (i + k + 1 >= N){
			break;
		}
		if (preflag[i] && sufflag[i + k + 1]){
			ans = std::min(ans, pre[i] + suf[i + k + 1]);
		}
	}
	return printf("%I64d\n", ans == LLONG_MAX ? -1ll : ans), 0;
}