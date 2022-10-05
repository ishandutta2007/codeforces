#include<bits/stdc++.h>

const int N = 3;

std::set <std::pair <int, int>> set;
std::pair <int, int> p[N];

int main(){
	for (int i = 0; i < N; ++ i){
		scanf("%d%d", &p[i].first, &p[i].second);
	}
	for (int i = 0; i < N; ++ i){
		int x = 0, y = 0;
		for (int j = 0; j < N; ++ j){
			if (i == j){
				x -= p[j].first;
				y -= p[j].second;
			}
			else{
				x += p[j].first;
				y += p[j].second;
			}
		}
		set.insert({x, y});
	}
	printf("%d\n", set.size());
	for (auto u = set.begin(); u != set.end(); ++ u){
		printf("%d %d\n", (*u). first, (*u).second);
	}
	return 0;
}