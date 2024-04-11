#include<bits/stdc++.h>
#define ll long long

const int N = 100;

struct edge{
	int next, to;
};

edge e[N << 1];

ll first[N], dep[N], n, e_cnt = 0, cor_x[N], cor_y[N], exi[N][4];

ll power(int a, int index){
	ll ret = 1;
	while (index){
		if (index & 1){
			ret *= a;
		}
		a *= a;
		index >>= 1;
	}
	return ret;
}

void addedge(int u, int v){
	e[++ e_cnt] = {first[u], v};
	first[u] = e_cnt;
	e[++ e_cnt] = {first[v], u};
	first[v] = e_cnt;
}

void dfs(int i, int fa){
	bool flag = false;
	for (int j = first[i]; j; j = e[j].next){
		int x = e[j].to;
		if (x == fa){
			continue;
		}
		bool flag = false;
		for (int k = 0; k < 4; ++ k){
			if (!exi[i][k]){
				flag = true;
				exi[i][k] = exi[x][(k + 2) % 4] = true;
				dep[x] = dep[i] + 1;
				ll length = power(2, n - dep[x]);
				switch (k){
					case 0: cor_x[x] = cor_x[i]; cor_y[x] = cor_y[i] + length; break;
					case 1: cor_x[x] = cor_x[i] + length; cor_y[x] = cor_y[i]; break;
					case 2: cor_x[x] = cor_x[i]; cor_y[x] = cor_y[i] - length; break;
					case 3: cor_x[x] = cor_x[i] - length; cor_y[x] = cor_y[i]; break;
				}
				dfs(x, i);
				break;
			}
		}
		if (!flag){
			printf("NO\n");
			exit(0);
		}
	}
}
	
int main(){
	scanf("%d", &n);
	for (int i = 0, u, v; i < n - 1; ++ i){
		scanf("%d%d", &u, &v);
		addedge(u, v);
	}
	dfs(1, 0);
	printf("YES\n"), 0;
	for (int i = 1; i <= n; ++ i){
		printf("%I64d %I64d\n", cor_x[i], cor_y[i]);
	}
	return 0;
}