#include<bits/stdc++.h>

const int N = 200010;

int n, w, k, t[N], a[N];
std::set <std::pair <int, int>> full, part;

int main(){
	scanf("%d%d%d", &n, &w, &k);
	for (int i = 0; i < n; ++ i){
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n; ++ i){
		scanf("%d", &t[i]);
	}
	int ans = 0, now = 0;
	for (int left = 0, right = 0; left < n; ++ left){
		if (left){
			if (full.count({t[left - 1], left - 1})){
				full.erase({t[left - 1], left - 1});
				k += t[left - 1];
				now -= a[left - 1];
			}
			else{
				part.erase({t[left - 1], left - 1});
				k += (t[left - 1] + 1) / 2;
				now -= a[left - 1];
				if (full.size()){
					auto u = full.end();
					-- u;
					std::pair <int, int> p = *u;
					k += p.first / 2;
					full.erase(p);
					part.insert(p);
				}
				else{
					++ w;
				}
			}
		}
		while (right < n){
			if (k < (t[right] + 1) / 2){
				break;
			}
			if (w){
				-- w;
				part.insert({t[right], right});
				now += a[right];
				k -= (t[right] + 1) / 2;
				++ right;
				continue;
			}
			std::pair <int, int> p = *(part.begin());
			if (p.first > t[right]){
				if (k < t[right]){
					break;
				}
				else{
					full.insert({t[right], right});
					now += a[right];
					k -= t[right];
					++ right;
					continue;
				}
			}
			int time = (t[right] + 1) / 2 + p.first / 2;
			if (k < time){
				break;
			}
			else{
				part.erase(p);
				full.insert(p);
				part.insert({t[right], right});
				now += a[right];
				k -= time;
				++ right;
			}
		}
		ans = std::max(ans, now);
	}
	return printf("%d\n", ans), 0;
}