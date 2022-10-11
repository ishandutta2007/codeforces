#include <iostream>
#include <cstdio>
#include <vector>

const int ms = 200200;

int u[ms], v[ms];
int par[ms];
int min[ms], sum[ms], size[ms];

int get_par(int x) {
	if(x == par[x]) return x;
	else return par[x] = get_par(par[x]);
}

void make_union(int a, int b) {
	a = get_par(a);
	b = get_par(b);
	sum[a]++;
	if(a == b) return;
	sum[a] += sum[b];
	size[a] += size[b];
	min[a] = std::min(min[a], min[b]);
	par[b] = a;
}

int main() {
	int n, m;
	std::cin >> n >> m;
	for(int i = 0; i < m; i++) {
		scanf("%d %d", u + i, v + i);
		u[i]--;
		v[i]--;
		min[u[i]]++;
		min[v[i]]++;
	}
	for(int i = 0; i < n; i++) {
		par[i] = i;
		size[i] = 1;
	}
	for(int i = 0; i < m; i++) {
		make_union(u[i], v[i]);
	}
	int ans = 0;
	for(int i = 0; i < n; i++) {
		if(get_par(i) == i && size[i] == sum[i] && min[i] == 2) {
			ans++;
		}
	}
	std::cout << ans << std::endl;
}