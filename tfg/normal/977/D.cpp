#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>

typedef long long ll;
typedef std::pair<ll, ll> ii;

ll gcd(ll a, ll b) {
	if(!b) return a;
	else return gcd(b, a % b);
}

bool cmp(ll n1, ll n2) {
	ii a(0, 0);
	ii b(0, 0);
	while(n1 % 3 == 0) n1 /= 3, a.first++;
	while(n1 % 2 == 0) n1 /= 2, a.second++;
	while(n2 % 3 == 0) n2 /= 3, b.first++;
	while(n2 % 2 == 0) n2 /= 2, b.second++;
	if(a.first != b.first) return a.first > b.first;
	else return a.second < b.second;
}

int main() {
	int n;
	std::cin >> n;
	std::vector<long long> a(n);
	//long long g = 0;
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
		//g = gcd(a[i], g);
	}
	for(int i = 0; i < n; i++) {
		//a[i] /= g;
	}
	std::sort(a.begin(), a.end(), cmp);
	for(int i = 0; i < n; i++) {
		std::cout << a[i] << (i + 1 == n ? '\n' : ' ');
	}
}