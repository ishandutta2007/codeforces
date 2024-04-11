#include<bits/stdc++.h>

const int N = 1000010;

struct edge{
	int next, to;
};

char s[N];
std::string str[N];
edge e[N];
int first[N], dep[N], siz[N], fa[N], now_edge[N], e_cnt, max_dep = 0, max_p = 0;

void addedge(int u, int v){
	e[++ e_cnt] = {first[u], v};
	first[u] = e_cnt;
	fa[v] = u;
	dep[v] = dep[u] + 1;
	max_dep = std::max(max_dep, dep[v]);
}

std::queue <int> q;

void bfs(int s){
	q.push(s);
	int now_dep = dep[s];
	while (!q.empty()){
		int i = q.front();
		q.pop();
		if (dep[i] != now_dep){
			printf("\n");
			now_dep = dep[i];
		}
		std::cout << str[i] << ' ';
		for (int j = first[i]; j; j = e[j].next){
			int x = e[j].to;
			q.push(x);
		}
	}
}

std::vector <int> vec;

int main(){
	scanf("%s", s);
	int len = strlen(s);
	int p_cnt = 1, now_p = 0;
	for (int i = 0; i < len;){
		if (!now_p){
			now_p = max_p + 1;
			max_p = std::max(max_p, now_p);
			p_cnt = now_p + 1;
			vec.push_back(now_p);
			dep[now_p] = 1;
		}
		now_edge[fa[now_p]] = e[now_edge[fa[now_p]]].next;
		while (s[i] != ',' && i < len){
			str[now_p] += s[i ++];
		}
		++ i;
		while (s[i] != ',' && i < len){
			siz[now_p] = siz[now_p] * 10 + s[i ++] - '0';
		}
		++ i;
		for (int j = 0; j < siz[now_p]; ++ j){
			addedge(now_p, ++ p_cnt);
			max_p = std::max(max_p, p_cnt);
		}
		now_edge[now_p] = first[now_p];
		while (!now_edge[now_p] && now_p){
			now_p = fa[now_p];
		}
		now_p = e[now_edge[now_p]].to;
	}
	for (int i = vec.size() - 1; ~i; -- i){
		addedge(0, vec[i]);
	}
	printf("%d", max_dep);
	bfs(0);
	return 0;
}