#include<bits/stdc++.h>
#define ll long long

const int N = 100010;

ll a[N], b[N], p[N], Hash[N], n, l, r;

int main(){
	scanf("%I64d%I64d%I64d", &n, &l, &r);
	for (int i = 0; i < n; ++ i){
		scanf("%I64d", &a[i]);
	}
	for (int i = 0; i < n; ++ i){
		scanf("%I64d", &p[i]);
		Hash[p[i]] = i;
	}
	ll left = l, right = r, now_c = -LLONG_MAX;
	bool flag = true;
	for (int i = 1; i <= n; ++ i){
		int sit = Hash[i];
		left = std::max(l, now_c + a[sit]);
		if (left > right){
			flag = false;
			break;
		}
		b[sit] = left;
		now_c = b[sit] - a[sit] + 1;
	}
	if (!flag){
		return printf("-1\n"), 0;
	}
	for (int i = 0; i < n; ++ i){
		printf("%I64d ", b[i]);
	}
	return printf("\n"), 0;	
}