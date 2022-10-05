#include<bits/stdc++.h>

const int N = 200010;
typedef long long ll;
typedef std::pair <ll, int> pii;

int type[N], v[N], a[N], b[N];
ll x[N];
pii y[N];
int n, m, k, s;

bool check(int mid){
	int mina = INT_MAX, minb = INT_MAX;
	for (int i = 1; i <= mid; ++ i){
		mina = std::min(mina, a[i]);
		minb = std::min(minb, b[i]);
	}
	for (int i = 1; i <= m; ++ i){
		if (type[i] == 1){
			x[i] = 1ll * mina * v[i];
		}
		else{
			x[i] = 1ll * minb * v[i];
		}
	}
	std::sort(x + 1, x + m + 1);
	ll sum = 0;
	for (int i = 1; i <= k; ++ i){
		sum += x[i];
	}
	return sum <= s;
}

int main(){
	scanf("%d%d%d%d", &n, &m, &k, &s);
	for (int i = 1; i <= n; ++ i){
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n; ++ i){
		scanf("%d", &b[i]);
	}
	for (int i = 1; i <= m; ++ i){
		scanf("%d%d", &type[i], &v[i]);
	}
	int left = 1, right = n;
	while (left < right){
		int mid = left + right >> 1;
		if (check(mid)){
			right = mid;
		}
		else{
			left = mid + 1;
		}
	}
	if (!check(left)){
		return printf("-1\n"), 0;
	}
	printf("%d\n", left);
	int mina = INT_MAX, minb = INT_MAX, sita, sitb;
	for (int i = 1; i <= left; ++ i){
		if (mina > a[i]){
			mina = a[i];
			sita = i;
		}
		if (minb > b[i]){
			minb = b[i];
			sitb = i;
		}
	}
	for (int i = 1; i <= m; ++ i){
		if (type[i] == 1){
			y[i] = {1ll * mina * v[i], i};
		}
		else{
			y[i] = {1ll * minb * v[i], i};
		}
	}
	std::sort(y + 1, y + m + 1);
	for (int i = 1; i <= k; ++ i){
		int sit = y[i].second;
		printf("%d %d\n", sit, type[sit] == 1 ? sita : sitb);
	}
	return 0;
}