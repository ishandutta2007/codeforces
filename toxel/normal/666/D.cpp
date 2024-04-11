#include<bits/stdc++.h>

const int N = 4;

std::pair <int, int> p[N], ans[N];
int a[N], check[N];
int min;
std::set <int> setd, setx, sety;

void chk(int d, int x, int y){
	int value = -INT_MAX;
	if (1ll * (x - p[a[0]].first) * (y - p[a[0]].second)){
		return;
	}
	check[0] = std::abs(x - p[a[0]].first + y - p[a[0]].second);
	if (1ll * (x + d - p[a[1]].first) * (y - p[a[1]].second)){
		return;
	}
	check[1] = std::abs(x + d - p[a[1]].first + y - p[a[1]].second);
	if (1ll * (x + d - p[a[2]].first) * (y + d - p[a[2]].second)){
		return;
	}
	check[2] = std::abs(x + 2 * d - p[a[2]].first + y - p[a[2]].second);
	if (1ll * (x - p[a[3]].first) * (y + d - p[a[3]].second)){
		return;
	}
	check[3] = std::abs(x + d - p[a[3]].first + y - p[a[3]].second);
	int answer = std::max(std::max(check[0], check[1]), std::max(check[2], check[3]));
	if (min > answer){
		ans[a[0]] = {x, y};
		ans[a[1]] = {x + d, y};
		ans[a[2]] = {x + d, y + d};
		ans[a[3]] = {x, y + d};
		min = answer;
	}
}

int main(){
	int test;
	scanf("%d", &test);
	while (test --){
		min = INT_MAX;
		for (int i = 0, x, y; i < 4; ++ i){
			scanf("%d%d", &x, &y);
			p[i] = {x, y};
		}
		for (int i = 0; i < N; ++ i){
			a[i] = i;
		}
		for (int i = 0; i < N; ++ i){
			for (int j = 0; j < N; ++ j){
				int d = std::abs(p[i].first - p[j].first);
				if (d){
					setd.insert(d);
				}
				d = std::abs(p[i].second - p[j].second);
				if (d){
					setd.insert(d);
				}
			}
		}
		do{
			for (auto u : setd){
				setx.clear();
				sety.clear();
				for (int i = 0; i < N; ++ i){
					setx.insert(p[i].first - u);
					setx.insert(p[i].first);
					setx.insert(p[i].first + u);
					sety.insert(p[i].second - u);
					sety.insert(p[i].second);
					sety.insert(p[i].second + u);
				}
				for (auto v : setx){
					for (auto w: sety){
						chk(u, v, w);
					}
				}
			}
		}
		while (std::next_permutation(a, a + N));
		for (int i = 0; i < N; ++ i){
			a[i] = i;
		}
		do{
			for (auto u : setd){
				p[a[1]].first -= u;
				p[a[2]].first -= u;
				p[a[2]].second -= u;
				p[a[3]].second -= u;
				int maxx = -INT_MAX, maxy = -INT_MAX, minx = INT_MAX, miny = INT_MAX;
				for (int i = 0; i < N; ++ i){
					maxx = std::max(maxx, p[i].first);
					maxy = std::max(maxy, p[i].second);
					minx = std::min(minx, p[i].first);
					miny = std::min(miny, p[i].second);
				}
				if (maxx == minx){
					int answer = maxy - miny + 1 >> 1;
					if (min > answer){
						int y = maxy + miny >> 1;
						ans[a[0]] = {minx, y};
						ans[a[1]] = {minx + u, y};
						ans[a[2]] = {minx + u, y + u};
						ans[a[3]] = {minx, y + u};
						min = answer;
					}
				}
				if (maxy == miny){
					int answer = maxx - minx + 1 >> 1;
					if (min > answer){
						int x = maxx + minx >> 1;
						ans[a[0]] = {x, miny};
						ans[a[1]] = {x + u, miny};
						ans[a[2]] = {x + u, miny + u};
						ans[a[3]] = {x, miny + u};
						min = answer;
					}
				}
				p[a[1]].first += u;
				p[a[2]].first += u;
				p[a[2]].second += u;
				p[a[3]].second += u;
			}
		}
		while (std::next_permutation(a, a + N));
		if (min == INT_MAX){
			printf("-1\n");
			continue;
		}
		printf("%d\n", min);
		for (int i = 0; i < N; ++ i){
			printf("%d %d\n", ans[i].first, ans[i].second);
		}
	}
}