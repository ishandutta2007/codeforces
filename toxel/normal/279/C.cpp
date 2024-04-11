#include<bits/stdc++.h>

const int N = 100010;

int n, m;
int a[N], left[N], right[N];

int main(){
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++ i){
		scanf("%d", &a[i]);
	}
	right[n - 1] = n - 1;
	for (int i = n - 2; i >= 0; -- i){
		if (a[i] > a[i + 1]){
			right[i] = i;
		}
		else{
			right[i] = right[i + 1];
		}
	}
	left[0] = 0;
	for (int i = 1; i < n; ++ i){
		if (a[i - 1] < a[i]){
			left[i] = i;
		}
		else{
			left[i] = left[i - 1];
		}
	}
	while (m --){
		int l, r;
		scanf("%d%d", &l, &r);
		-- l, -- r;
		puts(right[l] >= left[r] ? "Yes" : "No");
	}
	return 0;
}