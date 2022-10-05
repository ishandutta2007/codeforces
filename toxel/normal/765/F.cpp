#include<bits/stdc++.h>

const int N = 100010;
const int M = 300010;
const int MAX = 1 << 17;
const int INF = 0x7f7f7f7f;

struct segment{
	int left, right, value, lazy;
};

int n, m, a[N], q[M][2], ans[M], __seg[MAX << 1];
segment seg[MAX << 1];
std::map <int, int, std::greater <int>> __Hash;
std::map <int, std::vector <int>> Hash;

void __build(){
	memset(__seg, -1, sizeof(__seg));
}

void __add(int sit, int value){
	sit += MAX;
	__seg[sit] = std::max(__seg[sit], value);
	for (sit >>= 1; sit; sit >>= 1){
		__seg[sit] = std::max(__seg[sit << 1], __seg[(sit << 1) + 1]);
	}	
}

int __query(int left, int right){
	if (left > right){
		return -1;
	}
	int ret = -1;
	for (int l = left + MAX, r = right + MAX + 1; l < r; l >>= 1, r >>= 1){
		if (l & 1){
			ret = std::max(ret, __seg[l ++]);
		}
		if (r & 1){
			ret = std::max(ret, __seg[-- r]);
		}
	}
	return ret;
}

void build(){
	memset(seg, 0x7f, sizeof(seg));
	for (int i = MAX; i < MAX << 1; ++ i){
		seg[i].left = seg[i].right = i - MAX;
	}
	for (int i = MAX - 1; i; -- i){
		seg[i].left = seg[i << 1].left;
		seg[i].right = seg[(i << 1) + 1].right;
	}
}

void add(int left, int right, int sit, int value){
	if (left == seg[sit].left && right == seg[sit].right){
		seg[sit].value = std::min(seg[sit].value, value);
		seg[sit].lazy = std::min(seg[sit].lazy, value);
		return;
	}
	seg[sit << 1].value = std::min(seg[sit].lazy, seg[sit << 1].value);
	seg[sit << 1].lazy = std::min(seg[sit].lazy, seg[sit << 1].lazy);
	seg[(sit << 1) + 1].value = std::min(seg[sit].lazy, seg[(sit << 1) + 1].value);
	seg[(sit << 1) + 1].lazy = std::min(seg[sit].lazy, seg[(sit << 1) + 1].lazy);
	if (left >= seg[(sit << 1) + 1].left){
		add(left, right, (sit << 1) + 1, value);
	}
	else if (right <= seg[sit << 1].right){
		add(left, right, sit << 1, value);
	}
	else{
		add(left, seg[sit << 1].right, sit << 1, value);
		add(seg[(sit << 1) + 1].left, right, (sit << 1) + 1, value);
	}
	seg[sit].value = std::min(seg[sit << 1].value, seg[(sit << 1) + 1].value);
}

int query(int left, int right, int sit){
	if (left > right){
		return INF;
	}
	if (left == seg[sit].left && right == seg[sit].right){
		return seg[sit].value;
	}
	seg[sit << 1].value = std::min(seg[sit].lazy, seg[sit << 1].value);
	seg[sit << 1].lazy = std::min(seg[sit].lazy, seg[sit << 1].lazy);
	seg[(sit << 1) + 1].value = std::min(seg[sit].lazy, seg[(sit << 1) + 1].value);
	seg[(sit << 1) + 1].lazy = std::min(seg[sit].lazy, seg[(sit << 1) + 1].lazy);
	if (left >= seg[(sit << 1) + 1].left){
		return query(left, right, (sit << 1) + 1);
	}
	if (right <= seg[sit << 1].right){
		return query(left, right, sit << 1);
	}
	return std::min(query(left, seg[sit << 1].right, sit << 1), query(seg[(sit << 1) + 1].left, right, (sit << 1) + 1));
}

void solve(){
	__build();
	build();
	Hash.clear();
	for (int i = 0; i < m; ++ i){
		Hash[q[i][1]].push_back(i);
	}
	for (int i = 0; i < n; ++ i){
		int left = 0, right = __Hash[a[i]];
		while (true){
			int sit = __query(left, right);
			if (sit == -1){
				break;
			}
			add(0, sit, 1, a[sit] - a[i]);
			int x = a[sit] + a[i] >> 1;
			x -= !(a[sit] + a[i] & 1);
			left = __Hash.lower_bound(x) -> second;
		}
		for (auto u : Hash[i]){
			ans[u] = std::min(ans[u], query(q[u][0], i, 1));
		}
		__add(right, i);
	}
}

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; ++ i){
		scanf("%d", &a[i]);
		__Hash[a[i]] = 0;	
	}
	__Hash[-1] = 0;
	int now = 0;
	for (auto u = __Hash.begin(); u != __Hash.end(); ++ u){
		u -> second = now;
		++ now;
	}
	scanf("%d", &m);
	for (int i = 0; i < m; ++ i){
		scanf("%d%d", &q[i][0], &q[i][1]);
		-- q[i][0], -- q[i][1];
	}
	memset(ans, 0x7f, sizeof(ans));
	solve();
	std::reverse(a, a + n);
	for (int i = 0; i < m; ++ i){
		q[i][0] = n - 1 - q[i][0];
		q[i][1] = n - 1 - q[i][1];
		std::swap(q[i][0], q[i][1]);
	}
	solve();
	for (int i = 0; i < m; ++ i){
		printf("%d\n", ans[i]);
	}
	return 0;
}