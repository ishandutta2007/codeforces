#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;

#define int long long

const int N = 2e5 + 5;

int a[N] , m , n , d , Sqr , sum;

map<int,int>Map;

int Pow(int x , int y) {
	if(y == 1) return x;
	if(!y) return 1;
	int it = Pow(x , y >> 1);
	it = it * it % m;
	if(y & 1) it *= x;
	return it % m;
}

int inv(int x) {
	return Pow(x , m - 2);
}

int lsk_is_there;

bool dance(int x) {
	int d = ((sum * 2 % m * inv(n) % m - a[x] * 2) % m + m) % m * inv(n - 1) % m;
	if(d > m / 2) return 0;
	int lsk_is_here = lsk_is_there * d % m * d % m + (n - 1) * n % m * d % m * a[x] % m + n % m * (a[x]) % m * a[x] % m;
	lsk_is_here %= m;
	if(lsk_is_here != Sqr && m != 2) {
		return 0;
	}
	for(int i = 1;i <= n;i ++) Map[a[i]] ++;
	int now = a[x] , cur = 0;
	while(Map[now]) {
		Map[now] --; now = (now + d) % m; cur ++;
	}
	now = a[x]; now -= d; if(now < 0) now += m;now %= m;
	while(Map[now]) {
		cur ++; Map[now] --; now -= d; if(now < 0) now += m;now %= m;
	}
	if(cur == n) {
		printf("%lld %lld\n" , a[x] , d);
		return 1;
	}
	Map.clear();
	return 0;
}


main(void) {
	scanf("%lld%lld" ,&m , &n);
	if(m == n) {
		puts("0 1"); return 0;
	}
	for(int i = 1;i <= n;i ++) scanf("%lld" , &a[i]) , sum = (sum + a[i]) % m , Sqr = (Sqr + (a[i] * a[i])) % m;
	lsk_is_there = (n - 1) * n % m * (2 * n - 1) % m * inv(6) % m;
	for(int i = 1;i <= n;i ++) if(dance(i)) {
		return 0;
	}
	puts("-1");
}