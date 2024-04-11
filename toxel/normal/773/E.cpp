#include<bits/stdc++.h>

const int MAX = 1 << 19;
const int INF = 0x7f7f7f7f;

std::pair <int, int> seg[MAX << 1], rate[MAX << 1];
int lazy[MAX << 1], inv[MAX];
int n;
std::set <int> one, minusone, zero;

int less(std::set <int> &set, int x){
	auto u = set.lower_bound(x);
	if (u == set.begin()){
		return INF;
	}
	return *(-- u);
}

int before(int n){
	int x = less(one, n), y = less(zero, n), z = less(minusone, n);
	int max = -1;
	max = x != INF && x > max ? x : max;
	max = y != INF && y > max ? y : max;
	max = z != INF && z > max ? z : max;
	return max;
}

void push(int sit){
	seg[sit << 1].first += lazy[sit];
	seg[sit << 1 | 1].first += lazy[sit];
	lazy[sit << 1] += lazy[sit];
	lazy[sit << 1 | 1] += lazy[sit];
	lazy[sit] = 0;
}

void pull(int sit){
	seg[sit] = std::min(seg[sit << 1], seg[sit << 1 | 1]);
}

void build(){
	memset(seg, 0x7f, sizeof(seg));
	for (int i = 0; i < n; ++ i){
		seg[i + MAX].second = i;
	}
	for (int i = MAX - 1; i; -- i){
		pull(i);
	}
}

void add(int now, int l, int r, int left, int right, int value){
	if (l <= left && r >= right){
		seg[now].first += value;
		lazy[now] += value;
		return;
	}
	push(now);
	int mid = left + right >> 1;
	if (l <= mid){
		add(now << 1, l, r, left, mid, value);
	}
	if (r > mid){
		add(now << 1 | 1, l, r, mid + 1, right, value);
	}
	pull(now);
}

std::pair <int, int> query(int now, int l, int r, int left, int right){
	if (l <= left && r >= right){
		return seg[now];
	}
	push(now);
	int mid = left + right >> 1;
	std::pair <int, int> ret = {INT_MAX, 0};
	if (l <= mid){
		ret = std::min(ret, query(now << 1, l, r, left, mid));
	}
	if (r > mid){
		ret = std::min(ret, query(now << 1 | 1, l, r, mid + 1, right));
	}
	pull(now);
	return ret;
}

int main(){
	scanf("%d", &n);
	for (int i = 0, x; i < n; ++ i){
		scanf("%d", &x);
		rate[i] = {x, i};
	}
	std::sort(rate, rate + n);
	for (int i = 0; i < n; ++ i){
		inv[rate[i].second] = i;
	}
	build();
	for (int i = 0; i < n; ++ i){
		int nowrate, prerate, max = before(inv[i]);
		if (max == -1){
			nowrate = rate[inv[i]].first > 0 ? 1 : !rate[inv[i]].first ? 0 : -1;
			prerate = 0;
		}
		else{
			prerate = rate[max].first - query(1, max, max, 0, MAX - 1).first;
			int now = prerate - rate[inv[i]].first;
			nowrate = now > 0 ? -1 : !now ? 0 : 1;
		}
		int nowvalue = query(1, inv[i], inv[i], 0, MAX - 1).first;
		add(1, inv[i], inv[i], 0, MAX - 1, rate[inv[i]].first - prerate - nowrate - nowvalue);
		if (nowrate == 0){
			zero.insert(inv[i]);
		}
		else if (nowrate == -1){
			bool flag = true;
			minusone.insert(inv[i]);
			int sit = *(-- minusone.end());
			if (sit <= inv[i]){
				flag = false;
			}
			else{
				if (!query(1, sit, sit, 0, MAX - 1).first){
					minusone.erase(sit);
					zero.insert(sit);
					add(1, inv[i] + 1, sit - 1, 0, MAX - 1, 1);
				}
				else{
					flag = false;
				}
			}
			if (!flag){
				auto u = zero.lower_bound(inv[i]);
				if (u != zero.end()){
					add(1, inv[i] + 1, *u - 1, 0, MAX - 1, 1);
					one.insert(*u);
					zero.erase(u);
				}
				else{
					add(1, inv[i] + 1, MAX - 1, 0, MAX - 1, 1);	
				}
			}
		}
		else{
			one.insert(inv[i]);
			std::pair <int, int> p = query(1, inv[i] + 1, MAX - 1, 0, MAX - 1);
			if (p.first){
				add(1, inv[i] + 1, MAX - 1, 0, MAX - 1, -1);
			}
			else{
				add(1, inv[i] + 1, p.second - 1, 0, MAX - 1, -1);
				one.erase(p.second);
				zero.insert(p.second);
			}
		}
		printf("%d\n", (int) one.size() - (int) minusone.size());
	}
	return 0;
}