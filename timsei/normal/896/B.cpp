#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;

int a[N] , n , m , k , x , y , c , l = 1 , r;

int read(void) {
	int x;
	scanf("%d" , &x);
	return x;
} 

int cur[N] , tot;

bool cmp(int x , int y) {
	return x > y;
}

void dori(void) {
	for(int i = r + 1;i <= n;++ i) cur[++ tot] = a[i];
	cur[++ tot] = x;
	sort(cur + 1 , cur + tot + 1 , cmp);
	int whe = 0;
	for(int i = 1;i <= tot;++ i) if(cur[i] == x && cur[i + 1] != x) {
		whe = i; break;
	}
	a[n - whe + 1] = x;
	printf("%d\n" , n - whe + 1);
	while(r && a[r]) r --;
}

void dole(void) {
	for(int i = 1;i <l; ++i) cur[++ tot] = a[i];
	cur[++ tot] = x;
	sort(cur + 1 , cur + tot + 1);
	int whe = 0;
	for(int i = 1;i <= tot;++ i) if(cur[i] == x && cur[i + 1] != x) {
		whe = i; break;
	}
	a[whe] = x;
	cout << whe << endl;
	while(a[l]) l ++;
}

int main(void) {
	scanf("%d%d%d" , &n , &m , &c);
	l = 1; r = n;
	for(int i = 1;i <= m; ++ i) {
		x = read(); tot = 0;
		memset(cur , 0 , sizeof(cur));
		if(x > c / 2) dori();
		else dole();
		fflush(stdout);
	}
}