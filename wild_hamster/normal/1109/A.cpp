#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
#include <stdlib.h>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include <utility>
#include <omp.h>
#include<ctime>
#include <map>
#include<set>
#include<stdio.h>
#include<unordered_set>
#include<functional>
#define int long long
using namespace std;

#pragma comment(linker, "/STACK:1024000000")
#pragma Gcc optimize("O3")
#pragma Gcc target("sse,sse2,sse3,ssse3,sse4,popc2nt,abm,mmx,avx,tune=native")
#pragma Gcc optimize("unroll-loops")
#define fastio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
long long sum2 = 0;
long long a, b, c = 0, odd = 0, neodd = 0, d = 0, ans = 0, x, y, xx, yy;
map<long long, long long>map1, map2;
vector<long long>vec;
signed main()
{
	char ch;
	long long dp[1002],dp2[1001], ans = 1, ans2 = 0, ans3 = 1;
	string s;
	cin >> a;
	map2[0]++;
	for (int i = 0; i < a; i++) {
		scanf("%I64d", &b);
		c = c ^ b;
		if (i % 2 == 0) {
			map1[c]++;
		}
		else {
			map2[c]++;
		}
		vec.push_back(c);
	}
	b = 0;
	for (int i = 0; i < vec.size(); i++) {
		b += map1[vec[i]] * (map1[vec[i]] - 1) / 2 + map2[vec[i]] * (map2[vec[i]] - 1) / 2;
		map1[vec[i]] = 0;
		map2[vec[i]] = 0;
	}
	cout << b;
	cin >> a;
	return 0;
}