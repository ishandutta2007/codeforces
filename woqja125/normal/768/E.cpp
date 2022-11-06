#include<stdio.h>
//#include<map>
//using namespace std;
//map<pair<int, long long>, int> d;
int g[100]={0, 1, 1, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8, 8, 8, 8, 8, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 10, 10, 10, 10, 10, 10};
/*int findg(int x, long long b){
	if(x==0) return 0;
	b = b&((1ll<<(x+1))-1);
	if(d.count({x, b}) == 1) return d[{x, b}];
	long long chk = 0;
	for(int i=1; i<=x; i++){
		if((b>>(i-1))&1) continue;
		int g = findg(x-i, b|(1<<(i-1)));
		chk |= 1<<g;
	}
	for(int i=0; i<=62; i++){
		if(((chk>>i)&1) == 0){
			return d[{x, b}] = i;
		}
	}
	return 0;
}*/
int main(){/*
	g[0] = 0;
	g[1] = 1;
	printf("{");
	for(int i=1; i<=60; i++){
		g[i] = findg(i, 0);
		printf("%d, ", g[i]);
//		printf("%d : %d\n", i, g[i]);
	}*/
	int n, t, x=0;
	scanf("%d", &n);
	for(int i=1; i<=n; i++){
		scanf("%d", &t);
		x ^= g[t];
	}
	printf(x==0?"YES":"NO");
	return 0;
}