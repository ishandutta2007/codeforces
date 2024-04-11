#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_set>
#include <queue>
#include <deque>
#include <map>
#include <unordered_map>
#include <list>
#include <stack>
#include <functional>
#include <utility>
#include <iomanip>
#include <cstdlib>

int a, b, n;
bool swap = false;
int mat[1001][1001];

void fail(){
	std::cout << "NO\n";
	std::exit(0);
}

void answer(){
	if(a < b){
		swap = true;
		std::swap(a, b);
	}
	if(b != 1) fail();
	if(a == b && (n == 2 || n == 3)) fail();
	int big = n - a + 1;
	auto add_edge = [](int x, int y){
		mat[x][y] = mat[y][x] = true;
	};
	for(int i = 0; i < big-1; ++i){
		add_edge(i, i+1);
	}
	std::cout << "YES\n" << std::endl;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			if(i == j) std::cout << "0";
			else std::cout << (!swap ? (int)mat[i][j] : (int)(!mat[i][j]));
		}
		std::cout << "\n";
	}
}

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> a >> b;
	answer();
	return 0;
}