#include<bits/stdc++.h>

const int N = 300010;
typedef std::pair <int, int> pii;

int c[N];
pii p[N];

void check(int x1, int x2, int n, int flag){
	int sit = n - 1;
	std::vector <int> ans1;
	for ( ; sit >= 0; -- sit){
		if (1ll * p[sit].first * (n - sit) >= x1){
			for (int j = sit; j < n; ++ j){
				ans1.push_back(p[j].second);
			}
			break;
		}
	}
	std::vector <int> ans2;
	for (int i = sit - 1; i >= 0; -- i){
		if (1ll * p[i].first * (sit - i) >= x2){
			for (int j = i; j < sit; ++ j){
				ans2.push_back(p[j].second);
			}
			break;
		}
	}
	if (!ans1.size() || !ans2.size()) return;
	std::sort(ans1.begin(), ans1.end());
	std::sort(ans2.begin(), ans2.end());
	puts("Yes");
	if (flag){
		printf("%d %d\n", (int) ans2.size(), (int) ans1.size());
		for (int i = 0, sz = ans2.size(); i < sz; ++ i){
			printf("%d%c", ans2[i], " \n"[i == sz - 1]);
		}
		for (int i = 0, sz = ans1.size(); i < sz; ++ i){
			printf("%d%c", ans1[i], " \n"[i == sz - 1]);
		}
	}
	else{
		printf("%d %d\n", (int) ans1.size(), (int) ans2.size());
		for (int i = 0, sz = ans1.size(); i < sz; ++ i){
			printf("%d%c", ans1[i], " \n"[i == sz - 1]);
		}
		for (int i = 0, sz = ans2.size(); i < sz; ++ i){
			printf("%d%c", ans2[i], " \n"[i == sz - 1]);
		}
	}
	exit(0);
}

int main(){
	int n, x1, x2;
	scanf("%d%d%d", &n, &x1, &x2);
	for (int i = 0; i < n; ++ i){
		scanf("%d", &c[i]);
		p[i] = {c[i], i + 1};
	}
	std::sort(p, p + n);
	check(x1, x2, n, 0);
	check(x2, x1, n, 1);
	puts("No");
	return 0;
}