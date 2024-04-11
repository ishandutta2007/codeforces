#include<bits/stdc++.h>

#define ll long long

const int N = 100010;

ll b, q, n, m;
std::set <ll> set;

int main(){
	scanf("%I64d%I64d%I64d%I64d", &b, &q, &n, &m);
	for (int i = 0, x; i < m; ++ i){
		scanf("%d", &x);
		set.insert(x);
	}
	if (!q || !b){
		if (std::abs(b) > n){
			return printf("0\n"), 0;	
		}
		if (!set.count(0)){
			return printf("inf\n"), 0;
		}
		return printf("%d\n", !set.count(b) && std::abs(b) <= n), 0;
	}
	if (q == 1){
		return printf(set.count(b) || std::abs(b) > n ? "0\n" : "inf\n"), 0;
	}
	if (q == -1){
		return printf(set.count(b) && set.count(-b) || std::abs(b) > n ? "0\n" : "inf\n"), 0;	
	}
	int cnt = 0;
	while (std::abs(b) <= n){
		cnt += !set.count(b);
		b *= q;
	}
	return printf("%d\n", cnt), 0;
}