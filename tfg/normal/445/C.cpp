#include <iostream>
#include <iomanip>

const int ms = 505;

double table[ms][ms];
double val[ms];

int par[ms];
double vert[ms], edge[ms];

int get_par(int x) {
	if(x == par[x]) {
		return x;
	} else {
		return par[x] = get_par(par[x]);
	}
}

void make_union(int a, int b) {
	a = get_par(a);
	b = get_par(b);
	if(a == b)
		return;
	vert[a] += vert[b];
	edge[a] += edge[b];
	par[b] = a;
}

int main() {
	int n, m;
	std::cin >> n >> m;
	if(m == 0) {
		std::cout << "0\n";
		return 0;
	}
	for(int i = 1; i <= n; i++) {
		std::cin >> val[i];
		par[i] = i;
		vert[i] = val[i];
	}
	for(int i = 0; i < m; i++) {
		int u, v;
		std::cin >> u >> v;
		std::cin >> table[u][v];
		make_union(u, v);
		edge[get_par(u)] += table[u][v];
	}
	double ans = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = i + 1; j <= n; j++) {
			if(table[i][j] == 0)
				continue;
			ans = std::max(ans, (val[i] + val[j]) / table[i][j]);
		}
	}
	for(int i = 1; i <= n; i++) {
		if(edge[get_par(i)]) {
			ans = std::max(ans, vert[get_par(i)] / edge[get_par(i)]);
		}
	}
	std::cout << std::fixed << std::setprecision(20) << ans << "\n";
}