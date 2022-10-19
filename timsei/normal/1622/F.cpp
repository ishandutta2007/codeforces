#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int n, m, x, y, pr[N], cnt = 0;

#define u unsigned long long

const u MAX1 = 32768;
const u MAX2 = MAX1 * MAX1;

u All[N], who[N], it[N];

u Rnd2() {
	return 1llu * rand() * MAX1 + rand();
}

u Rand() {
	return 1llu * Rnd2() * MAX2 + Rnd2();
}

bool isp[N];

void prework(int n) {
	for(int i = 2; i <= n; ++ i) isp[i] = 1;
	for(int i = 2; i <= n; ++ i) {
		if(isp[i]) {
			pr[++ cnt] = i, All[i] = who[i] = Rand();
			for(int j = 2; j * i <= n; ++ j) {
				int now = j * i; isp[now] = 0;
				while(now % i == 0) {
					who[j * i] ^= All[i];
					now /= i;
				}
			}
		}
	}
}

map < u, int> Map;

int ans = 0;

bool vis[N];

void print() {
	cout << ans << endl;
	for(int i = 1; i <= n; ++ i) if(!vis[i]) printf("%d ", i);
	puts("");
}

int main() {
	scanf("%d", &n);
	prework(n);
	u now = 0, cur = 0;
	for(int i = 1; i <= n; ++ i) {
		now = now ^ who[i];
		Map[now] = i;
		it[i] = now;
		cur = cur ^ now;
	}
	
	if(!cur) {
		ans = n;
		print();
		return 0;
	} else {
		if(Map.count(cur)) {
			vis[Map[cur]] = 1;
			ans = n - 1;
			print();
			return 0;
		} else {
			for(int i = 1; i <= n; ++ i) {
				if(Map.count(cur ^ it[i])) {
					vis[i] = 1;
					vis[Map[cur ^ it[i]]] = 1;
					ans = n - 2; print();
					return 0;
				}
			}
		}
	}
	vis[n] = vis[n / 2] = vis[2] = 1;
	ans = n - 3;
	print();
}