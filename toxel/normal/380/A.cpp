#include<bits/stdc++.h>

typedef long long ll;
typedef std::pair <ll, int> pii;
const int N = 100010;

int x[N];

int main(){
	int m;
	scanf("%d", &m);
	ll now = 0;
	std::set <pii> set;
	while (m --){
		int type;
		scanf("%d", &type);
		if (type == 1){
			int y;
			scanf("%d", &y);
			set.insert({++ now, -y});
			if (now < N){
				x[now] = y;
			}
		}
		else{
			int l, c;
			scanf("%d%d", &l, &c);
			now += l * c;
			set.insert({now, l});
			if (now - l * c < N){
				for (int i = now - l * c + 1; i < std::min(now + 1, 1ll * N); ++ i){
					x[i] = x[(i - now + l * c - 1) % l + 1];
				}
			}
		}
	}
	int n;
	scanf("%d", &n);
	while (n --){
		ll y;
		scanf("%I64d", &y);
		auto u = set.lower_bound({y, INT_MIN});
		if (u -> second < 0){
			printf("%d%c", -(u -> second), " \n"[!n]);
			continue;
		}
		int l = u -> second;
		y = (l - (u -> first - y) % l) % l;
		y = y ? y : l;
		printf("%d%c", x[y], " \n"[!n]);
	}
	return 0;
}