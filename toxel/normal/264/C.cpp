#include<bits/stdc++.h>

const int N = 100010;
typedef long long ll;

ll max[N];
int v[N], c[N];

int main(){
	int n, q;
	scanf("%d%d", &n, &q);
	for (int i = 0; i < n; ++ i){
		scanf("%d", &v[i]);
	}
	for (int i = 0; i < n; ++ i){
		scanf("%d", &c[i]);
		-- c[i];
	}
	while (q --){
		for (int i = 0; i < n; ++ i){
			max[i] = LLONG_MIN;
		}
		int a, b;
		scanf("%d%d", &a, &b);
		if (n == 1){
			printf("%I64d\n", std::max(0ll, 1ll * v[0] * b));
			continue;
		}
		ll max1 = LLONG_MIN, max2 = LLONG_MIN;
		int sit1 = 0, sit2 = 1;
		for (int i = 0; i < n; ++ i){
			ll x = LLONG_MIN;
			if (max[c[i]] != LLONG_MIN){
				x = std::max(x, max[c[i]] + 1ll * v[i] * a);
			}
			x = std::max(x, std::max(sit1 == c[i] ? max2 : max1, 0ll) + 1ll * v[i] * b);
			if (x > max[c[i]]){
				max[c[i]] = x;
				if (sit1 == c[i]){
					max1 = x;
				}
				else if (sit2 == c[i]){
					if (x > max1){
						max2 = max1;
						max1 = x;
						std::swap(sit1, sit2);
					}
					else{
						max2 = x;
					}
				}
				else if (x > max1){
					max2 = max1;
					sit2 = sit1;
					max1 = x;
					sit1 = c[i];
				}
				else if (x > max2){
					max2 = x;
					sit2 = c[i];
				}
			}
		}
		printf("%I64d\n", std::max(0ll, max1));
	}
	return 0;
}