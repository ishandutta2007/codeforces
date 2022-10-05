#include<bits/stdc++.h>
#define ll long long

const int N = 1000010;

int a[N], n;
int cnt[N << 2];

int main(){
	scanf("%d", &n);
	int small = 0, big = 0;
	ll nowsum = 0;
	for (int i = 1; i <= n; ++ i){
		scanf("%d", &a[i]);
		int x = a[i] - i;
		nowsum += std::abs(x);
		if (x < 0){
			++ small;
		}
		else if (x > 0){
			++ big;
		}
		++ cnt[x + N];
	}
	ll min = nowsum, sit = 0;
	for (int i = 0; i < n - 1; ++ i){
		int x = a[n - i] - n;
		nowsum -= std::abs(x);
		-- cnt[x + N + i];
		if (x > 0){
			-- big;
		}
		else if (x < 0){
			-- small;
		}
		x += n;
		nowsum += std::abs(x);
		++ cnt[x + N + i];
		if (x > 0){
			++ big;
		}
		else if (x < 0){
			++ small;
		}
		nowsum += small - big + cnt[N + i];
		small += cnt[N + i];
		big -= cnt[N + i + 1];
		if (nowsum < min){
			min = nowsum;
			sit = i + 1;
		}
	}
	return printf("%I64d %I64d\n", min, sit), 0;
}