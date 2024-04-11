#include<bits/stdc++.h>
#define pii std::pair <int, int>

const int N = 100010;
const int MAX = 1 << 17;
const int moder = 1e9 + 7;
const int INF = 0x7f7f7f7f;

struct orz{
	int u, l, r, s;
	
	bool operator < (const orz &p) const &{
		return p.u < u;
	}
};

pii seg[MAX << 1];
int h, w, n;
orz o[N];
std::stack <pii> stack[N];

void build(){
	for (int i = 0; i < w; ++ i){
		seg[i + MAX] = {stack[i].top().first, i};
	}
	for (int i = w; i < MAX; ++ i){
		seg[i + MAX] = {INT_MAX, INT_MAX};
	}
	for (int i = MAX - 1; i; -- i){
		seg[i] = std::min(seg[i << 1], seg[(i << 1) + 1]);
	}
}

void add(int sit, pii value){
	sit += MAX;
	seg[sit] = value;
	for (sit >>= 1; sit; sit >>= 1){
		seg[sit] = std::min(seg[sit << 1], seg[(sit << 1) + 1]);
	}	
}

pii query(int left, int right){
	pii ret = {INT_MAX, INT_MAX};
	for (int l = left + MAX, r = right + MAX + 1; l < r; l >>= 1, r >>= 1){
		if (l & 1){
			ret = std::min(ret, seg[l ++]);
		}
		if (r & 1){
			ret = std::min(ret, seg[-- r]);
		}
	}
	return ret;
}

void operate(int i, pii p){
	if (!stack[i].empty() && stack[i].top().first == p.first){
		p.second = (p.second + stack[i].top().second) % moder;
		stack[i].pop();
		stack[i].push(p);
		return;
	}
	stack[i].push(p);
	add(i, {stack[i].top().first, i});
}

int main(){
	scanf("%d%d%d", &h, &w, &n);
	for (int i = 0; i < n; ++ i){
		scanf("%d%d%d%d", &o[i].u, &o[i].l, &o[i].r, &o[i].s);
		-- o[i].l, -- o[i].r;
	}
	std::sort(o, o + n);
	for (int i = 0; i < w; ++ i){
		stack[i].push({h + 1, 1});
	}
	build();
	for (int i = 0; i < n; ++ i){
		while (true){
			pii p = query(o[i].l, o[i].r);
			if (p.first > o[i].u + o[i].s){
				break;
			}
			pii ball = stack[p.second].top();
			stack[p.second].pop();
			ball.first = o[i].u;
			if (stack[p.second].empty()){
				add(p.second, {INT_MAX, p.second});
			}
			else{
				add(p.second, {stack[p.second].top().first, p.second});
			}
			if (!o[i].l || o[i].r == w - 1){
				int sit = o[i].l ? o[i].l - 1 : o[i].r + 1;
				ball.second = 2ll * ball.second % moder;
				operate(sit, ball);
				continue;
			}
			operate(o[i].l - 1, ball);
			operate(o[i].r + 1, ball);
		}
	}
	int ans = 0;
	for (int i = 0; i < w; ++ i){
		while (!stack[i].empty()){
			ans = (ans + stack[i].top().second) % moder;
			stack[i].pop();
		}
	}
	return printf("%d\n", ans), 0;
}