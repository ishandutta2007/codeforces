#include<bits/stdc++.h>

const int N = 1000010;
const int M = 10000010;

int a[N];
long long cnt[M];
int n, k;

bool check(int mid){
	memset(cnt, 0, sizeof(cnt));
	for (int i = 0; i < n; ++ i){
		++ cnt[a[i]];
	}
	for (int i = M - 1; i > 1; -- i){
		if (i >> 1 < mid){
			break;
		}
		if (!cnt[i]){
			continue;
		}
		cnt[i >> 1] += cnt[i];
		cnt[i + 1 >> 1] += cnt[i];
		cnt[i] = 0;
	}
	long long sum = 0;
	for (int i = mid; i < M; ++ i){
		sum += cnt[i];
	}
	return sum >= k;
}

int main(){
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++ i){
		scanf("%d", &a[i]);
	}
	int left = 0, right = M - 1;
	while (left < right){
		int mid = left + right + 1 >> 1;
		if (check(mid)){
			left = mid;
		}
		else{
			right = mid - 1;
		}
	}
	return printf("%d\n", left ? left : -1), 0;
}