#include<bits/stdc++.h>

const int N = 100010;
const int M = 30;

std::map <std::string, int> Hash;
int fa[N << 1], n, m, q;
char s[M];

int find(int u){
	return fa[u] == u ? u : fa[u] = find(fa[u]);
}

void unite(int u, int v){
	int _u = find(u), _v = find(v);
	fa[_u] = _v;
	find(u);
}

int main(){
	for (int i = 0; i < N << 1; ++ i){
		fa[i] = i;
	}
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 0; i < n; ++ i){
		scanf("%s", s);
		std::string str = s;
		Hash[str] = i;
	}
	for (int i = 0, type; i < m; ++ i){
		scanf("%d%s", &type, s);
		std::string str = s;
		int u = Hash[str];
		scanf("%s", s);
		str = s;
		int v = Hash[str];
		find(u), find(v), find(v + n), find(u + n);
		if (type == 1){
			if (fa[u] == fa[v + n] || fa[v] == fa[u + n]){
				printf("NO\n");
				continue;
			}
			printf("YES\n");
			unite(u, v);
			unite(u + n, v + n);
			continue;
		}
		if (type == 2){
			if (fa[u] == fa[v] || fa[u + n] == fa[v + n]){
				printf("NO\n");
				continue;
			}
			printf("YES\n");
			unite(u, v + n);
			unite(u + n, v);
		}
	}
	for (int i = 0; i < q; ++ i){
		scanf("%s", s);
		std::string str = s;
		int u = Hash[str];
		scanf("%s", s);
		str = s;
		int v = Hash[str];
		find(u), find(v), find(u + n), find(v + n);
		if (fa[u] == fa[v] || fa[u + n] == fa[v + n]){
			printf("1\n");
		}
		else if (fa[u] == fa[v + n] || fa[u + n] == fa[v]){
			printf("2\n");
		}
		else{
			printf("3\n");
		}
	}
	return 0;
}