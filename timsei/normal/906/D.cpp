#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <cassert>
#include <vector>
using namespace std;

#define int long long

const int N = 1e6 + 5;

int pr[N] , n , m , cnt , a[N];
bool isp[N];

int Pow(int x , int y , int mod) {
	x %= mod;
	if(!x) return 0;
	if(!y) return 1;
	if(y == 1) return x % mod;
	int it = Pow(x , y >> 1 , mod);
	it = it * 1ll * it % mod;
	if(y & 1) it = it * 1ll * x % mod;
	return it;
}

void pre(int n) {
	memset(isp , 1 , sizeof(isp));
	isp[1] = 0;
	for(int i = 1;i <= n;++ i) {
		if(isp[i]) pr[++ cnt] = i;
		for(int j = 1;j <= cnt && pr[j] * i <= n;++ j) {
			isp[pr[j] * i] = 0;
			if(i % pr[j] == 0) break;
		}
	}
}

int Phi(int x) {
	int now = x;
	for(int i = 1;i <= cnt;++ i) {
		if(x % pr[i] == 0) {
			now /= pr[i]; now *= (pr[i] - 1);
		}
		while(x % pr[i] == 0) x /= pr[i];
	}
	if(x != 1) now /= x , now *= (x - 1);
	return now;
}

vector <int> chg;

int gcd(int x , int y) {
	return (y == 0) ? x : gcd(y , x % y);
}

int bigger (int x , int y , int z) {
	int q = 1;
	if(x == 0 || x == 1) {
		if(x == z) return 0;
		if(x > z) return 1;
		return -1;
	}
	while(q <= z && y) {
		q *= x; y --;
	}
	if(q == z) return 0;
	if(q > z) return 1;
	return -1;
}

main(void) {
	pre(5e4);
	cin >> n >> m;
	chg.push_back(m);
	int p = m;
	while(p != 1) {
		p = Phi(p);
		chg.push_back(p);
	}
	chg.push_back(1); chg.push_back(1); chg.push_back(1);chg.push_back(1);chg.push_back(1);chg.push_back(1);
	for(int i = 1;i <= n;++ i) cin >> a[i];
	int tot = chg.size();
	int l , r , t;
	for(cin >> t;t --;) {
		cin >> l >> r;
		int cur = 1ll , now;
		if(r > l + (int) chg.size() - 3) cur = 0ll;
		r = min(r , l + (int)chg.size() - 3);
		int add = 0;
		for(int i = r;i >= l;-- i) {
			now = cur + chg[i - l + 1] * add;
			if(bigger(a[i] , now , chg[i - l]) >= 0) add = 1; else add = 0;
			cur = Pow(a[i] , now , chg[i - l]);
		}
		cout << cur % m << endl;
	}
}