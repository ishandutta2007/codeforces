#include<bits/stdc++.h>

const int N = 20;
typedef long long ll;

int a[N], b[N];
int cnta, cntb;
std::multiset <int> set;

void dfs(int now, bool flag){
	if (now == cnta){
		for (int i = 0; i < cnta; ++ i){
			putchar('0' + a[i]);
		}
		putchar('\n');
		exit(0);
	}
	if (flag){
		auto u = -- set.end();
		a[now] = *u;
		set.erase(u);
		dfs(now + 1, flag);
		set.insert(a[now]);
		return;
	}
	auto u = set.lower_bound(b[now]);
	if (u != set.end() && *u == b[now]){
		a[now] = b[now];
		set.erase(u);
		dfs(now + 1, flag);
		set.insert(a[now]);
	}
	u = set.lower_bound(b[now]);
	if (u != set.begin()){
		-- u;
		a[now] = *u;
		set.erase(u);
		dfs(now + 1, true);
		set.insert(a[now]);
	}
}

int main(){
	ll A, B;
	scanf("%I64d%I64d", &A, &B);
	while (A){
		a[cnta ++] = A % 10;
		A /= 10;
	}
	while (B){
		b[cntb ++] = B % 10;
		B /= 10;
	}
	std::reverse(a, a + cnta);
	std::reverse(b, b + cntb);
	if (cnta < cntb){
		std::sort(a, a + cnta, std::greater <int>());
		for (int i = 0; i < cnta; ++ i){
			putchar('0' + a[i]);
		}
		putchar('\n');
		return 0;
	}
	for (int i = 0; i < cnta; ++ i){
		set.insert(a[i]);
	}
	dfs(0, false);
	return 0;
}