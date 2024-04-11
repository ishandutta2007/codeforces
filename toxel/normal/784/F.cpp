#include<bits/stdc++.h>

const int N = 100;

int n;
int a[N];
std::set <int> set;

int main(){
	for (long long i = 0; i < 20000000ll; ++ i){
		set.insert(i);
		set.erase(i);
	}
	scanf("%d", &n);
	for (int i = 0; i < n; ++ i){
		scanf("%d", &a[i]);
	}
	std::sort(a, a + n);
	for (int i = 0; i < n; ++ i){
		printf("%d ", a[i]);
	}
	return printf("\n"), 0;
}