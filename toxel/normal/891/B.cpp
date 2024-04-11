#include<bits/stdc++.h>

typedef std::pair <int, int> pii;
const int N = 30;

pii a[N];
int b[N];

int main(){
	int n;
	scanf("%d", &n);
	for (int i = 0, x; i < n; ++ i){
		scanf("%d", &x);
		a[i] = {x, i};
	}
	std::sort(a, a + n);
	for (int i = 0; i < n; ++ i){
		b[a[i].second] = a[(i + n - 1) % n].first;
	}
	for (int i = 0; i < n; ++ i){
		printf("%d%c", b[i], " \n"[i == n - 1]);
	}
	return 0;
}