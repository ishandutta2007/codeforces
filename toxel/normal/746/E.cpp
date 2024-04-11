#include<bits/stdc++.h>

const int N = 200010;

int a[N], n, m, cnt[2], orz[2], first[N];
std::set <int> set;
bool even[N << 1], odd[N << 1];
std::pair <int, int> p[N];

void print(int ans){
	printf("%d\n", ans);
	for (int i = 0; i < n; ++ i){
		a[p[i].second] = p[i].first;
	}
	for (int i = 0; i < n; ++ i){
		printf("%d ", a[i]);
	}
	putchar('\n');
	exit(0);
}

int main(){
	scanf("%d%d", &n, &m);
	if (m > N << 1){
		m = N << 1;
	}
	int __cnt = 0;
	for (int i = 0; i < n; ++ i){
		scanf("%d", &p[i].first);
		set.insert(p[i].first);
		p[i] = {p[i].first, i};
	}
	std::sort(p, p + n);
	for (int i = 1; i <= m; ++ i){
		if (!set.count(i)){
			if (i & 1){
				odd[i] = true;
				++ orz[1];
				if (!first[1]){
					first[1] = i;
				}
			}
			else{
				even[i] = true;
				++ orz[0];
				if (!first[0]){
					first[0] = i;
				}
			}
		}
	}
	for (int i = 0; i < n; ++ i){
		if (p[i].first != p[i + 1].first){
			++ cnt[p[i].first & 1];
		}
	}
	int ans = 0;
	for (int i = 0; i < n; ++ i){
		if (p[i].first == p[i + 1].first){
			if (cnt[0] < cnt[1]){
				if (!orz[0]){
					return printf("-1\n"), 0;
				}
				p[i].first = first[0];
				++ ans;
				even[first[0]] = false;
				while (!even[first[0]] && first[0] < N << 1){
					++ first[0];
				}
				++ cnt[0];
				-- orz[0];
			}
			else{
				if (!orz[1]){
					return printf("-1\n"), 0;
				}
				p[i].first = first[1];
				++ ans;
				odd[first[1]] = false;
				while (!odd[first[1]] && first[1] < N << 1){
					++ first[1];
				}
				++ cnt[1];
				-- orz[1];
			}
		}
	}
	if (cnt[0] == cnt[1]){
		print(ans);
	}
	for (int i = 0; i < n; ++ i){
		if (cnt[0] < cnt[1]){
			if (!orz[0]){
				return printf("-1\n"), 0;
			}
			if (!(p[i].first & 1)){
				continue;
			}
			p[i].first = first[0];
			++ ans;
			even[first[0]] = false;
			while (!even[first[0]] && first[0] < N << 1){
				++ first[0];
			}
			++ cnt[0];
			-- cnt[1];
			-- orz[0];
		}
		else if (cnt[0] > cnt[1]){
			if (!orz[1]){
				return printf("-1\n"), 0;
			}
			if (p[i].first & 1){
				continue;
			}
			p[i].first = first[1];
			++ ans;
			odd[first[1]] = false;
			while (!odd[first[1]] && first[1] < N << 1){
				++ first[1];
			}
			++ cnt[1];
			-- cnt[0];
			-- orz[1];
		}
		else{
			print(ans);
		}
	}
}