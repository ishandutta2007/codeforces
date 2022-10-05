#include<bits/stdc++.h>
#define ll long long
#define lowbit(x) ((x) & (-(x)))

const int N = 2010;

ll c[N][N];

ll query(int i, int j){
	ll ret = 0;
	while (i){
		int x = j;
		while (x){
			ret += c[i][x];
			x -= lowbit(x);
		}
		i -= lowbit(i);
	}
	return ret;
}

void add(int i, int j, int value){
	while (i < N){
		int x = j;
		while (x < N){
			c[i][x] += value;
			x += lowbit(x);
		}
		i += lowbit(i);
	}
}

int state[N], pre[N];
std::vector <std::pair <std::pair <int, int>, int>> gar[N];
int n, m, k;
char s[N];

int main(){
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= k; ++ i){
		int len;
		scanf("%d", &len);
		for (int j = 0, u, v, w; j < len; ++ j){
			scanf("%d%d%d", &u, &v, &w);
			gar[i].push_back({{u, v}, w});
			add(u, v, w);
		}
	}
	memset(state, -1, sizeof(state));
	memset(pre, -1, sizeof(pre));
	int q;
	scanf("%d", &q);
	while (q --){
		scanf("%s", s);
		if (s[0] == 'S'){
			int x;
			scanf("%d", &x);
			state[x] = -state[x];
			continue;
		}
		int x1, y1, x2, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		for (int i = 1; i <= k; ++ i){
			if (pre[i] == state[i]){
				continue;
			}
			for (auto u : gar[i]){
				add(u.first.first, u.first.second, u.second * pre[i]);
			}
		}
		printf("%I64d\n", query(x2, y2) - query(x1 - 1, y2) - query(x2, y1 - 1) + query(x1 - 1, y1 - 1)), 0;
		memcpy(pre, state, sizeof(state));
	}
	return 0;
}