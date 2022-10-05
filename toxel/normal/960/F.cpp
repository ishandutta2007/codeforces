#include<bits/stdc++.h>

const int N = 100010;
const int MAX = 1 << 17;

typedef std::pair <int, int> pii;
typedef std::pair <pii, int> piii;

struct seg{
	seg(){child[0] = child[1] = NULL; value = 0;}
	
	seg *child[2];
	int value;
};

seg *segpool;
int segcnt = 0;

seg *newseg(){
	if (!segcnt){
		segpool = new seg [N];
		segcnt += N;
	}
	return segpool + (-- segcnt);
}

int dp[N];
seg *segs[N];

void add(seg *segs, int l, int r, int sit, int value){
	if (l == r){
		segs -> value = value;
		return;
	}
	int mid = l + r >> 1;
	if (sit <= mid){
		if (segs -> child[0] == NULL){
			segs -> child[0] = newseg();
		}
		add(segs -> child[0], l, mid, sit, value);
	}
	else{
		if (segs -> child[1] == NULL){
			segs -> child[1] = newseg();
		}
		add(segs -> child[1], mid + 1, r, sit, value);
	}
	segs -> value = 0;
	if (segs -> child[0] != NULL){
		segs -> value = std::max(segs -> value, segs -> child[0] -> value);
	}
	if (segs -> child[1] != NULL){
		segs -> value = std::max(segs -> value, segs -> child[1] -> value);
	}
}

int query(seg *segs, int l, int r, int ql, int qr){
	if (segs == NULL) return 0;
	if (ql <= l && qr >= r){
		return segs -> value;
	}
	int mid = l + r >> 1;
	int ret = 0;
	if (ql <= mid){
		ret = std::max(ret, query(segs -> child[0], l, mid, ql, qr));
	}
	if (qr > mid){
		ret = std::max(ret, query(segs -> child[1], mid + 1, r, ql, qr));
	}
	return ret;
}

piii p[N];

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0, u, v, w; i < m; ++ i){
		scanf("%d%d%d", &u, &v, &w);
		p[i] = {{u, v}, w};
	}
	for (int i = 1; i <= n; ++ i){
		segs[i] = newseg();
	}
	for (int i = m - 1; i >= 0; -- i){
		dp[i] = query(segs[p[i].first.second], 0, MAX - 1, p[i].second + 1, MAX - 1) + 1;
		add(segs[p[i].first.first], 0, MAX - 1, p[i].second, dp[i]);
	}
	int ans = 0;
	for (int i = 0; i < m; ++ i){
		ans = std::max(ans, dp[i]);
	}
	printf("%d\n", ans);
	return 0;
}