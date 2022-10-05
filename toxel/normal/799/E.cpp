#include<bits/stdc++.h>
#define ll long long
#define lowbit(x) ((x) & (-x))

const int N = 200010;

std::pair <ll, int> c[N];

void add(int sit, std::pair <ll, int> value){
	for ( ; sit < N; sit += lowbit(sit)){
		c[sit].first += value.first;
		c[sit].second += value.second;
	}
}

std::pair <ll, int> query(int sit){
	std::pair <ll, int> ret = {0, 0};
	for ( ; sit; sit -= lowbit(sit)){
		ret.first += c[sit].first;
		ret.second += c[sit].second;
	}
	return ret;
}

int n, m, k;
std::pair <int, int> a[N], b[N], ab[N], no[N], price[N];
int inv[N];
std::set <int> seta, setb;

int main(){
	scanf("%d%d%d", &n, &m, &k);
	if (m < k){
		return printf("-1\n"), 0;
	}
	for (int i = 1; i <= n; ++ i){
		scanf("%d", &price[i].first);
		price[i].second = i;
	}
	std::sort(price + 1, price + n + 1);
	for (int i = 1; i <= n; ++ i){
		inv[price[i].second] = i;
	}
	int num;
	scanf("%d", &num);
	if (num < k){
		return printf("-1\n"), 0;
	}
	for (int i = 0, x; i < num; ++ i){
		scanf("%d", &x);
		x = inv[x];
		seta.insert(x);
	}
	scanf("%d", &num);
	if (num < k){
		return printf("-1\n"), 0;
	}
	for (int i = 0, x; i < num; ++ i){
		scanf("%d", &x);
		x = inv[x];
		setb.insert(x);
	}
	int cnta = 0, cntb = 0, cntab = 0, cntno = 0;
	for (auto u : seta){
		if (setb.count(u)){
			ab[cntab ++] = {price[u].first, u};
		}
		else{
			a[cnta ++] = {price[u].first, u};
		}
	}
	for (auto u : setb){
		if (!seta.count(u)){
			b[cntb ++] = {price[u].first, u};
		}
	}
	for (int i = 1; i <= n; ++ i){
		if (!seta.count(i) && !setb.count(i)){
			no[cntno ++] = {price[i].first, i};
			add(i, {price[i].first, 1});
		}
	}
	int sz = std::min(cntab, k);
	ll nowans = 0;
	for (int i = 0; i < cntab; ++ i){
		if (i < sz){
			nowans += ab[i].first;
		}
		else{
			add(ab[i].second, {ab[i].first, 1});
		}
	}
	int nowa = -1, nowb = -1;
	for (int i = 0; i < cnta; ++ i){
		if (i < k - sz){
			nowans += a[i].first;
			nowa = i;
		}
		else{
			add(a[i].second, {a[i].first, 1});
		}
	}
	for (int i = 0; i < cntb; ++ i){
		if (i < k - sz){
			nowans += b[i].first;
			nowb = i;
		}
		else{
			add(b[i].second, {b[i].first, 1});
		}
	}
	ll min = LLONG_MAX;
	for (int i = sz; i >= 0; -- i){
		if (2 * k - i > m){
			break;
		}
		int left = 0, right = n;
		while (left < right){
			int mid = left + right >> 1;
			std::pair <ll, int> ans = query(mid);
			if (ans.second >= m - 2 * k + i){
				right = mid;
			}
			else{
				left = mid + 1;
			}
		}
		min = std::min(min, nowans + query(left).first);
		if (nowa == cnta - 1 || nowb == cntb - 1){
			break;
		}
		if (i > 0){
			add(ab[i - 1].second, {ab[i - 1].first, 1});
			nowans -= ab[i - 1].first;
		}
		++ nowa, ++ nowb;
		nowans += a[nowa].first;
		nowans += b[nowb].first;
		add(a[nowa].second, {-a[nowa].first, -1});
		add(b[nowb].second, {-b[nowb].first, -1});
	}
	return printf("%I64d\n", min == LLONG_MAX ? -1 : min), 0;
}