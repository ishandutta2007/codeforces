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

int n;
int tab[150];

void read(){
	std::scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		int a;
		std::scanf("%d", &a);
		tab[a]++;
	}
	int max = 0;
	for(int i = 0; i < 120; ++i){
		max = std::max(max, tab[i]);
	}
	std::printf("%d\n", max);
}

int main(){
	read();
	return 0;
}