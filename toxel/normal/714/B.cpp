#include<bits/stdc++.h>

const int N = 100010;

std::set <int> set;
int n;

int main(){
	scanf("%d", &n);
	for (int i = 0, x; i < n; ++ i){
		scanf("%d", &x);
		set.insert(x);
	}
	if ((int) set.size() <= 2){
		return printf("YES\n"), 0;
	}
	if ((int) set.size() >= 4){
		return printf("NO\n"), 0;
	}
	auto u = set.begin();
	int x = *(u ++), y = *(u ++), z = *u;
	return printf(x + z == y << 1 ? "YES\n" : "NO\n"), 0;
}