#include<bits/stdc++.h>

const int N = 110;

int a[N], b[N], cnta[N], cntb[N], ans[N], n;

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; ++ i){
		scanf("%d", &a[i]);
		++ cnta[a[i]];
	}
	for (int i = 0; i < n; ++ i){
		scanf("%d", &b[i]);
		++ cntb[b[i]];
	}
	int ret = 0;
	for (int i = 1; i <= 5; ++ i){
		if (cnta[i] + cntb[i] & 1){
			return printf("-1\n"), 0;
		}
		else{
			ans[i] = cnta[i] + cntb[i] >> 1;
			ret += std::abs(cnta[i] - ans[i]);
		}
	}
	return printf("%d\n", ret >> 1), 0;
}