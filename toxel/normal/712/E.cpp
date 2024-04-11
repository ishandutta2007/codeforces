#include<bits/stdc++.h>

const int MAX = 1 << 17;
const double eps = 1e-9;

struct segment{
	std::pair <double, double> value;
	int left, right;
};

segment seg[MAX << 1];
int n, q;
double p[MAX];

void build(){
	for (int i = MAX; i < MAX + n; ++ i){
		seg[i] = {{p[i - MAX], p[i - MAX]}, i - MAX, i - MAX};
	}
	for (int i = MAX + n; i < MAX << 1; ++ i){
		seg[i] = {{0, 1}, i - MAX, i - MAX};
	}
	for (int i = MAX - 1; i; -- i){
		std::pair <double, double> p1 = seg[i << 1].value, p2 = seg[(i << 1) + 1].value;
		seg[i] = {{p1.first * p2.first / (1 + p1.second * (p2.first - 1)),
				p2.second + (1 - p2.second) * p1.second * p2.first / (1 + p1.second * (p2.first - 1))},
				seg[i << 1].left, seg[(i << 1) + 1].right};
	}
}

void add(int i){
	i += MAX;
	seg[i] = {{p[i - MAX], p[i- MAX]}, i - MAX, i - MAX};
	for (i >>= 1; i; i >>= 1){
		std::pair <double, double> p1 = seg[i << 1].value, p2 = seg[(i << 1) + 1].value;
		seg[i].value = {p1.first * p2.first / (1 + p1.second * (p2.first - 1)),
				p2.second + (1 - p2.second) * p1.second * p2.first / (1 + p1.second * (p2.first - 1))};
	}
}

std::pair <double, double> query(int left, int right, int sit){
	if (left == seg[sit].left && right == seg[sit].right){
		return seg[sit].value;
	}
	if (left >= seg[(sit << 1) + 1].left){
		return query(left, right, (sit << 1) + 1);
	}
	if (right <= seg[sit << 1].right){
		return query(left, right, sit << 1);
	}
	std::pair <double, double> p1 = query(left, seg[sit << 1].right, sit << 1), p2 = query(seg[(sit << 1) + 1].left, right, (sit << 1) + 1);
	return {p1.first * p2.first / (1 + p1.second * (p2.first - 1)),
			p2.second + (1 - p2.second) * p1.second * p2.first / (1 + p1.second * (p2.first - 1))};
}

int main(){
	scanf("%d%d", &n, &q);
	for (int i = 0, a, b; i < n; ++ i){
		scanf("%d%d", &a, &b);
		p[i] = 1.0 * a / b;
	}
	build();
	while (q --){
		int type;
		scanf("%d", &type);
		if (type == 1){
			int sit, a, b;
			scanf("%d%d%d", &sit, &a, &b);
			-- sit;
			p[sit] = 1.0 * a / b;
			add(sit);
			continue;
		}
		int l, r;
		scanf("%d%d", &l, &r);
		-- l, -- r;
		/*if (l == r){
			printf("%.10lf\n", 1 / (1 + p[l]));
			continue;
		}
		if (l == r - 1){
			printf("%.10lf\n", 1 / ((1 + p[l]) * (1 + p[r]) - p[r]));
			continue;
		}*/
		printf("%.10lf\n", query(l, r, 1).first);
	}
	return 0;
}