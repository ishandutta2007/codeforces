#include<bits/stdc++.h>
#define ll long long

const int N = 2010;

std::set <std::pair <ll, int>> set;
ll a[N][N], dis[N];
bool vis[N];
int n;

int main(){
	scanf("%d", &n);
	memset(dis, 0x7f, sizeof(dis));
	ll mine = LLONG_MAX;
	for (int i = 0; i < n; ++ i){
		for (int j = i + 1; j < n; ++ j){
			scanf("%I64d", &a[i][j]);
			mine = std::min(mine, a[j][i] = a[i][j]);
		}
	}
	for (int i = 0; i < n; ++ i){
		for (int j = 0; j < n; ++ j){
			if (i == j){
				continue;
			}
			a[i][j] -= mine;
			dis[i] = std::min(dis[i], 2 * a[i][j]);
		}
	}
	for (int i = 0; i < n; ++ i){
		set.insert({dis[i], i});
	}
	for (int i = 0; i < n; ++ i){
		std::pair <ll, int> p = *(set.begin());
		set.erase(set.begin());
		vis[p.second] = true;
		for (int j = 0; j < n; ++ j){
			if (!vis[j] && p.second != j){
				set.erase({dis[j], j});
				dis[j] = std::min(dis[p.second] + a[p.second][j], dis[j]);
				set.insert({dis[j], j});
			}
		}
	}
	for (int i = 0; i < n; ++ i){
		printf("%I64d\n", dis[i] + (n - 1) * mine);
	}
	return 0;
}