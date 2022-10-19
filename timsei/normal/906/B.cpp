#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <set>
using namespace std;

const int N = 1e6 + 5;

int n , m , x , y , P[N] , px[N] , py[N] , a[N];

int abs(int x) {
	if(x < 0) return -x;
	return x;
}

int adj(int x , int y) {
	if(x <= 0 || y <= 0 || x > n * m || y > n * m) return 0;
	if(abs(x - y) == m) return 1;
	if(abs(x - y) == 1 && max(x , y) % m != 1) return 1;
	return 0;
}

int ha(int x , int y) {
	return (x - 1) * m + y;
}

typedef pair<int,int> Pair;

int main(void) {
	scanf("%d%d" , &n , &m);
	srand(20020705);
	for(int i = 1;i <= n * m;++ i) {
		P[i] = i;
	}
	bool has = 0;
	for(int asd = 1;asd <= 1000000 / (n * m);++ asd) {
		random_shuffle(P + 1 , P + n * m + 1);
		has = 0;
		set <Pair> S;
		S.clear();
		for(int j = 1;j <= n * m;++ j) S.insert(make_pair(P[j] , j));
		for(int j = 1;j <= n * m;++ j) {
			auto it = S.begin();
			int suc;
			while(1) {
				suc = 1;
				a[j] = it -> second;
				if(adj(j , j - 1) && adj(a[j] , a[j - 1])) suc = 0;
				if(adj(j , j - m) && adj(a[j] , a[j - m])) suc = 0;
				if(suc) {
					S.erase(it); break;
				}
				it ++;
				if(it == S.end()) break;
			}
			if(!suc) {
				has = 1; break;
			}
		}
		if(has) continue;
		puts("YES");
		for(int k = 1;k <= n * m;++ k) {
			printf("%d " , a[k]);
			if(k % m == 0) puts("");
		}
		return 0;
	}
	puts("NO");
}