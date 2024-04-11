#include<bits/stdc++.h>

const int N = 110;
const int INF = 0x7f7f7f7f;

char s[N][N];
bool ud, lr;
int n, m;
std::queue <std::pair <int, int>> q;
std::pair <int, int> pre[N][N];
int dis[N][N];
std::vector <std::pair <int, int>> ans;

std::pair <int, int> ask(char ch){
	putchar(ch);
	putchar('\n');
	fflush(stdout);
	int x, y;
	scanf("%d%d", &x, &y);
	if (s[x][y] == 'F'){
		exit(0);
	}
	return {x, y};
}

void bfs(std::pair <int, int> ss){
	memset(dis, 0x7f, sizeof(dis));
	dis[ss.first][ss.second] = 0;
	q.push(ss);
	while (!q.empty()){
		std::pair <int, int> u = q.front();
		q.pop();
		if (u.first + 1 <= n && dis[u.first + 1][u.second] == INF && s[u.first + 1][u.second] != '*'){
			dis[u.first + 1][u.second] = 0;
			pre[u.first + 1][u.second] = u;
			q.push({u.first + 1, u.second});
		}
		if (u.first - 1 && dis[u.first - 1][u.second] == INF && s[u.first - 1][u.second] != '*'){
			dis[u.first - 1][u.second] = 0;
			pre[u.first - 1][u.second] = u;
			q.push({u.first - 1, u.second});
		}
		if (u.second + 1 <= m && dis[u.first][u.second + 1] == INF && s[u.first][u.second + 1] != '*'){
			dis[u.first][u.second + 1] = 0;
			pre[u.first][u.second + 1] = u;
			q.push({u.first, u.second + 1});
		}
		if (u.second - 1 && dis[u.first][u.second - 1] == INF && s[u.first][u.second - 1] != '*'){
			dis[u.first][u.second - 1] = 0;
			pre[u.first][u.second - 1] = u;
			q.push({u.first, u.second - 1});
		}
	}
}

int main(){
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++ i){
		scanf("%s", s[i] + 1);
	}
	std::pair <int, int> now = {1, 1};
	if (s[1][2] == '.' || s[1][2] == 'F'){
		std::pair <int, int> p = ask('R');
		if (p == now){
			lr = true;
		}
		else{
			lr = false;
			ask('L');
		}
		for (int i = 1; i <= m; ++ i){
			now = {1, i};
			if (s[2][i] == '.' || s[2][i] == 'F'){
				p = ask('D');
				ud = p == now;
				now = p;
				break;
			}
			ask(lr ? 'L' : 'R');
		}
	}
	else if (s[2][1] == '.' || s[2][1] == 'F'){
		std::pair <int, int> p = ask('D');
		if (p == now){
			ud = true;
		}
		else{
			ud = false;
			ask('U');
		}
		for (int i = 1; i <= n; ++ i){
			now = {i, 1};
			if (s[i][2] == '.' || s[i][2] == 'F'){
				p = ask('R');
				lr = p == now;
				now = p;
				break;
			}
			ask(ud ? 'U' : 'D');
		}
	}
	bfs(now);
	std::pair <int, int> fin;
	for (int i = 1; i <= n; ++ i){
		for (int j = 1; j <= m; ++ j){
			if (s[i][j] == 'F'){
				fin = {i, j};
			}
		}
	}
	int cnt = 0;
	while (fin != now){
		++ cnt;
		if (cnt > 100000) assert(0);
		ans.push_back(fin);
		fin = pre[fin.first][fin.second];
	}
	ans.push_back(now);
	std::reverse(ans.begin(), ans.end());
	for (int i = 0; i < (int) ans.size() - 1; ++ i){
		int type;
		if (ans[i + 1].first - ans[i].first == 1){
			type = 0;
		}
		if (ans[i + 1].first - ans[i].first == -1){
			type = 1;
		}
		if (ans[i + 1].second - ans[i].second == 1){
			type = 2;
		}
		if (ans[i + 1].second - ans[i].second == -1){
			type = 3;
		}
		if (lr && type >= 2){
			type ^= 1;
		}
		if (ud && type <= 1){
			type ^= 1;
		}
		switch (type){
			case 0 : ask('D'); break;
			case 1 : ask('U'); break;
			case 2 : ask('R'); break;
			case 3 : ask('L'); break;
		}
	}
	return 0;
}