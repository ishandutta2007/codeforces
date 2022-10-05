#include<bits/stdc++.h>

const int N = 1010;
typedef std::pair <int, int> pii;

char s[N];
std::vector <pii> e[N];
int dis[N];
bool inque[N];

void spfa(int s){
	memset(dis, 0x80, sizeof(dis));
	memset(inque, 0, sizeof(inque));
	dis[s] = 0;
	std::queue <int> queue;
	queue.push(s);
	inque[s] = true;
	while (!queue.empty()){
		int u = queue.front();
		queue.pop();
		inque[u] = false;
		for (auto v : e[u]){
			if (dis[u] + v.second > dis[v.first]){
				dis[v.first] = dis[u] + v.second;
				if (!inque[v.first]){
					queue.push(v.first);
					inque[v.first] = true;
				}
			}
		}
	}
}

int main(){
	int n;
	scanf("%d%s", &n, s);
	for (int i = 0; i < n - 1; ++ i){
		if (s[i] == 'L'){
			e[i + 2].push_back({i + 1, 1});
		}
		else if (s[i] == 'R'){
			e[i + 1].push_back({i + 2, 1});
		}
		else{
			e[i + 1].push_back({i + 2, 0});
			e[i + 2].push_back({i + 1, 0});
		}
	}
	for (int i = 1; i <= n; ++ i){
		e[0].push_back({i, 0});
	}
	spfa(0);
	int min = INT_MAX;
	for (int i = 1; i <= n; ++ i){
		min = std::min(dis[i], min);
	}
	for (int i = 1; i <= n; ++ i){
		printf("%d%c", dis[i] + min + 1, " \n"[i == n]);
	}
	return 0;
}