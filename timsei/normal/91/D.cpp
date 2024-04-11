#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int P[N], n, cnt = 0;
vector <int> Cir[N];
bool vis[N];

void doit(int x) {
	Cir[cnt].push_back(x);
	vis[x] = 1;
	if(vis[P[x]]) return;
	doit(P[x]);
}

vector <int> K2, K3;

int main() {
	cin >> n;
	for(int i = 1; i <= n; ++ i) scanf("%d", &P[i]), vis[i] = 0;
	for(int i = 1; i <= n; ++ i) {
		if(!vis[i]) {
			++ cnt;
			doit(i);
		}
	}
	
	int ans = 0, k2 = 0, k3 = 0;
	for(int i = 1; i <= cnt; ++ i) {
		int now = Cir[i].size() % 4; ans += Cir[i].size() / 4;
		if(now == 2) ++ k2;
		if(now == 3) ++ k3;
	}
	while(k2 && k3) {
		++ ans; -- k2; -- k3;
	}
	while(k3 >= 3) {
		ans += 2; k3 -= 3;
	}
	ans += k3;
	while(k2 >= 2) {
		++ ans; k2 -= 2;
	}
	ans += k2;
	printf("%d\n", ans);
	
	for(int i = 1; i <= cnt; ++ i) {
		while(Cir[i].size() >= 4) {
			if(Cir[i].size() == 4) {
				printf("4\n");
				printf("%d %d %d %d\n", Cir[i][0], Cir[i][1], Cir[i][2], Cir[i][3]);
				printf("%d %d %d %d\n", Cir[i][1], Cir[i][2], Cir[i][3], Cir[i][0]);
				while(Cir[i].size() >= 1) Cir[i].pop_back();
				continue;
			}
			printf("5\n");
			if(Cir[i].size() == 5) {
				for(int j = 0; j < 5; ++ j) printf("%d ", Cir[i][j]);
				puts("");
				for(int j = 1; j < 5; ++ j) printf("%d ", Cir[i][j]);
				printf("%d ", Cir[i][0]);
				puts("");
				while(Cir[i].size() >= 1) Cir[i].pop_back();
				continue;
			}
			for(int j = Cir[i].size() - 5; j < (int) Cir[i].size(); ++ j) printf("%d ", Cir[i][j]);
			puts("");
			for(int j = Cir[i].size() - 4; j < (int) Cir[i].size(); ++ j) printf("%d ", Cir[i][j]);
			printf("%d ", Cir[i][Cir[i].size() - 5]);
			puts("");
			for(int j = 0; j < 4; ++ j)  Cir[i].pop_back();
		}
		if(Cir[i].size() == 2) K2.push_back(i);
		if(Cir[i].size() == 3) K3.push_back(i);
	}
	while(K3.size() && K2.size()) {
		int l = K3.back(), r = K2.back();
		K3.pop_back(); K2.pop_back();
		printf("5\n");
		printf("%d %d %d %d %d\n", Cir[l][0], Cir[l][1], Cir[l][2], Cir[r][0], Cir[r][1]);
		printf("%d %d %d %d %d\n", Cir[l][1], Cir[l][2], Cir[l][0], Cir[r][1], Cir[r][0]);
	}
	while(K3.size() >= 3) {
		int a = K3.back(), b = K3[K3.size() - 2], c = K3[K3.size() - 3];
		printf("5\n");
		printf("%d %d %d %d %d\n", Cir[a][0], Cir[a][1], Cir[a][2], Cir[b][0], Cir[b][1]);
		printf("%d %d %d %d %d\n", Cir[a][1], Cir[a][2], Cir[a][0], Cir[b][1], Cir[b][0]);
		printf("5\n");
		printf("%d %d %d %d %d\n", Cir[c][0], Cir[c][1], Cir[c][2], Cir[b][0], Cir[b][2]);
		printf("%d %d %d %d %d\n", Cir[c][1], Cir[c][2], Cir[c][0], Cir[b][2], Cir[b][0]);
		K3.pop_back(); K3.pop_back(); K3.pop_back();			
	}
	for(int i = 0; i < (int) K3.size(); ++ i) {
		int a = K3[i];
		puts("3");
		printf("%d %d %d\n", Cir[a][0], Cir[a][1], Cir[a][2]);
		printf("%d %d %d\n", Cir[a][1], Cir[a][2], Cir[a][0]);
	}
	while(K2.size() >= 2) {
		int l = K2.back(), r = K2[K2.size() - 2];
		K2.pop_back(); K2.pop_back();
		puts("4");
		printf("%d %d %d %d\n", Cir[l][0], Cir[l][1], Cir[r][0], Cir[r][1]);
		printf("%d %d %d %d\n", Cir[l][1], Cir[l][0], Cir[r][1], Cir[r][0]);
	}
	if(K2.size()) {
		puts("2");
		int x = K2.back();
		printf("%d %d\n", Cir[x][0], Cir[x][1]);
		printf("%d %d\n", Cir[x][1], Cir[x][0]);
	}
}