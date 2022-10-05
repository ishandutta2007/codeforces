#include<bits/stdc++.h>

const int N = 1000010;
const int H = 100;

std::bitset <N> set;
int p[N];
bool vis[N];
int cnt[N];

int main(){
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++ i){
		scanf("%d", &p[i]);
	}
	std::vector <int> vec;
	for (int i = 1; i <= n; ++ i){
		if (vis[i]) continue;
		int x = i, cnt = 0;
		while (!vis[x]){
			vis[x] = true;
			++ cnt;
			x = p[x];
		}
		vec.push_back(cnt);
	}
	for (auto u : vec){
		++ cnt[u];
	}
	set.set(0);
	for (int i = 2; i <= H; ++ i){
		if (!cnt[i]) continue;
		std::bitset <N> _set = set;
		for (int j = 0; j < i; ++ j){
			int front = 0, tail = 0, one = 0;
			while (true){
				int sit = front * i + j;
				if (sit >= N) break;
				one += set.test(sit);
				if (front - tail > cnt[i]){
					one -= set.test(tail * i + j);
					++ tail;
				}
				if (one){
					_set.set(sit);
				}
				++ front;
			}
		}
		set = _set;
	}
	for (int i = H + 1; i < N; ++ i){
		for (int j = 0; j < cnt[i]; ++ j){
			set |= set << i;
		}
	}
	printf("%d ", set.test(k) ? k : k + 1);
	int x = n;
	for (auto u : vec){
		x -= u & 1;
	}
	printf("%d\n", std::min(std::min(k << 1, x + k - (x >> 1)), n));
}