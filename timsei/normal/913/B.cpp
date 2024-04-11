#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int M = N * 2;

int fir[N] , ne[M] , to[M] , cnt , x , y , du[N] , n;

void add(int x , int y) {
	ne[++ cnt] = fir[x]; fir[x] = cnt; to[cnt] = y;
}

void link(int x , int y) {
	add(x , y); add(y , x);
}

#define Foreachson(i , x) for(int i = fir[x];i;i = ne[i])

int dfs(int x , int f) {
	int tot = 0 , fff = 0;
	Foreachson(i , x) {
		int V = to[i];
		if(V == f) {
			continue;
		}
		tot += dfs(V , x);fff = 1;
	}
	if(!fff) return 1; 
	if(tot < 3) exit(puts("No") * 0);
	return 0;
}

int main(void) {
	scanf("%d" , &n);
	for(int i = 2;i <= n;++ i) {
		scanf("%d" , &x); link(x , i);
	}
	dfs(1 , 0);
	puts("Yes");
}