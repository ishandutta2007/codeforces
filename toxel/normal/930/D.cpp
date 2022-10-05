#include<bits/stdc++.h>

const int N = 200010;
typedef long long ll;

int max[N << 1], min[N << 1];
int premax[N << 1], sufmax[N << 1], premin[N << 1], sufmin[N << 1];
int x[N], y[N];

int main(){
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++ i){
		scanf("%d%d", &x[i], &y[i]);
		int tmpx = x[i] + y[i] + N, tmpy = x[i] - y[i] + N;
		x[i] = tmpx;
		y[i] = tmpy;
	}
	for (int i = 0; i < N << 1; ++ i){
		max[i] = 0;
		min[i] = (N << 1) - 1;
	}
	for (int i = 0; i < n; ++ i){
		if (x[i] & 1) continue;
		max[x[i]] = std::max(max[x[i]], y[i]);
		min[x[i]] = std::min(min[x[i]], y[i]);
	}
	premax[0] = 0;
	premin[0] = (N << 1) - 1;
	sufmax[(N << 1) - 1] = 0;
	sufmin[(N << 1) - 1] = (N << 1) - 1;
	for (int i = 1; i < N << 1; ++ i){
		premax[i] = std::max(premax[i - 1], max[i]);
		premin[i] = std::min(premin[i - 1], min[i]);
	}
	for (int i = (N << 1) - 2; i >= 0; -- i){
		sufmax[i] = std::max(sufmax[i + 1], max[i]);
		sufmin[i] = std::min(sufmin[i + 1], min[i]);
	}
	ll sum = 0;
	for (int i = 1; i < (N << 1) - 1; i += 2){
		int up = std::min(premax[i - 1], sufmax[i + 1]);
		int down = std::max(premin[i - 1], sufmin[i + 1]);
		if (up <= down){
			sum += (N << 1) / 2;
			continue;
		}
		if ((up & 1) != (i & 1)){
			++ up;
		}
		if ((down & 1) != (i & 1)){
			-- down;
		}
		sum += ((((N << 1) - 1) - up) >> 1) + 1;
		sum += (down >> 1) + 1;
	}
	for (int i = 0; i < N << 1; ++ i){
		max[i] = 0;
		min[i] = (N << 1) - 1;
	}
	for (int i = 0; i < n; ++ i){
		if (!(x[i] & 1)) continue;
		max[x[i]] = std::max(max[x[i]], y[i]);
		min[x[i]] = std::min(min[x[i]], y[i]);
	}
	premax[0] = 0;
	premin[0] = (N << 1) - 1;
	sufmax[(N << 1) - 1] = 0;
	sufmin[(N << 1) - 1] = (N << 1) - 1;
	for (int i = 1; i < N << 1; ++ i){
		premax[i] = std::max(premax[i - 1], max[i]);
		premin[i] = std::min(premin[i - 1], min[i]);
	}
	for (int i = (N << 1) - 2; i >= 0; -- i){
		sufmax[i] = std::max(sufmax[i + 1], max[i]);
		sufmin[i] = std::min(sufmin[i + 1], min[i]);
	}
	for (int i = 2; i < (N << 1) - 1; i += 2){
		int up = std::min(premax[i - 1], sufmax[i + 1]);
		int down = std::max(premin[i - 1], sufmin[i + 1]);
		if (up <= down){
			sum += (N << 1) / 2;
			continue;
		}
		if ((up & 1) != (i & 1)){
			++ up;
		}
		if ((down & 1) != (i & 1)){
			-- down;
		}
		sum += ((((N << 1) - 1) - up) >> 1) + 1;
		sum += (down >> 1) + 1;
	}
	sum = 1ll * (N << 1) * ((N << 1) - 2) / 2 - sum;
	printf("%I64d\n", sum);
	return 0;
}