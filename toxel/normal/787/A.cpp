#include<bits/stdc++.h>

int a, b, c, d;

int main(){
	scanf("%d%d%d%d", &a, &b, &c, &d);
	std::set <int> set1, set2;
	for (int i = 0; i <= 50000; ++ i){
		set1.insert(b + a * i);
	}
	for (int i = 0; i <= 50000; ++ i){
		set2.insert(d + c * i);
	}
	for (auto u : set1){
		if (set2.count(u)){
			return printf("%d\n", u), 0;
		}
	}
	return printf("-1\n"), 0;
}