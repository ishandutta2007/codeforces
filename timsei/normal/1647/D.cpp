#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, m, x, y, d, pr[N], isp[N], cnt = 0;
long long C[31][31], ans;

vector <int> who, now;

void dfs(int lst, int x) {
	if(lst == who.size()) return;
	if(ans == 2) return;
	if(x == 1) {
		++ ans;
		return;
	}
	if(x < who[lst]) return;
	if(x % (1LL * d * d) != 0) {
		++ ans; return;
	}
	for(int i = lst; i < (int) who.size(); ++ i) {
		if(x % who[i] == 0) {
			if((x / who[i]) % d == 0 && x >= 1LL * who[i] * who[i])
			dfs(i, x / who[i]);
		}
	}
}

void rmain() {
	ans = 0;
	cin >> x >> d;
	who.clear(); now.clear();
	for(int i = 1; i * i <= x; ++ i) {
		if(x % i == 0) {
			who.push_back(i);
			if(i % (1LL * d * d) == 0 || i % d != 0) who.pop_back();
			if(i * i != x) {
				who.push_back(x / i);
				if((x / i) % (1LL * d * d) == 0 || (x / i) % d != 0) who.pop_back();
			}
		}
	}
	sort(who.begin(), who.end());
	if(x % (1LL * d * d) != 0) {
		puts("NO");
		return;
	}
	dfs(0, x);
	if(ans == 2)
	puts("YES"); 
	else puts("NO"); 
}

main() {
	int t;
	for(cin >> t; t --;) {
		rmain();
	}
}