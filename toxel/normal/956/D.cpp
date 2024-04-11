#include<bits/stdc++.h>

typedef long long ll;

struct frac{
	int x, y;
	
	frac (int x = 0, int y = 0):x(y < 0 ? -x : x), y(std::abs(y)){}
	
	bool operator < (const frac &f)const{
		return 1ll * x * f.y < 1ll * y * f.x;
	}
	
	bool operator == (const frac &f)const{
		return 1ll * x * f.y == 1ll * y * f.x;
	}
};

const int N = 100010;
typedef std::pair <int, int> pii;
typedef std::pair <int, pii> piii;
inline int lowbit(int n){return n & -n;}

int x[N], v[N], a[N], b[N];
frac f1[N], f2[N], f[N];
piii p[N];
int c[N];

void add(int sit, int value){
	for ( ; sit < N; sit += lowbit(sit)){
		c[sit] += value;
	}
}

int query(int sit){
	int ret = 0;
	for ( ; sit; sit -= lowbit(sit)){
		ret += c[sit];
	}
	return ret;
}

ll ans;
pii pp[N];

void calc(int l, int r){
	if (l >= r) return;
	int mid = l + r >> 1;
	for (int i = l; i <= r; ++ i){
		pp[i] = p[i].second;
	}
	std::sort(pp + l, pp + mid + 1);
	std::sort(pp + mid + 1, pp + r + 1);
	for (int i = l, j = mid + 1; j <= r; ++ j){
		while (i <= mid && pp[i].first <= pp[j].first){
			add(pp[i ++].second, 1);
		}
		ans += query(pp[j].second);
	}
	for (int i = l, j = mid + 1; j <= r; ++ j){
		while (i <= mid && pp[i].first <= pp[j].first){
			add(pp[i ++].second, -1);
		}
	}
	calc(l, mid);
	calc(mid + 1, r);
}

ll solve(int l, int r){
	ans = 0;
	std::sort(p + l, p + r + 1);
	calc(l, r);
	return ans;
}

int main(){
	int n, w;
	scanf("%d%d", &n, &w);
	for (int i = 0; i < n; ++ i){
		scanf("%d%d", &x[i], &v[i]);
		f1[i] = {x[i], v[i] + w};
		f2[i] = {x[i], v[i] - w};
	}
	for (int i = 0; i < n; ++ i){
		f[i] = f1[i];
	}
	std::sort(f, f + n);
	int cnt = std::unique(f, f + n) - f;
	for (int i = 0; i < n; ++ i){
		a[i] = std::lower_bound(f, f + cnt, f1[i]) - f + 1;
	}
	for (int i = 0; i < n; ++ i){
		f[i] = f2[i];
	}
	std::sort(f, f + n);
	cnt = std::unique(f, f + n) - f;
	for (int i = 0; i < n; ++ i){
		b[i] = std::lower_bound(f, f + cnt, f2[i]) - f + 1;
	}
	for (int i = 0; i < n; ++ i){
		p[i] = {x[i], {a[i], n + 1 - b[i]}};
	}
	std::sort(p, p + n);
	ll ans = 0;
	int sit;
	for (int i = 0; i <= n; ++ i){
		if (i == n || p[i].first > 0){
			sit = i;
			ans += solve(0, i - 1);
			ans += solve(i, n - 1);
			break;
		}
	}
	for (int i = 0; i < n; ++ i){
		p[i].second.first = n + 1 - p[i].second.first;
		p[i].second.second = n + 1 - p[i].second.second;
	}
	for (int i = 0; i < n; ++ i){
		pp[i] = p[i].second;
	}
	std::sort(pp + 0, pp + sit);
	std::sort(pp + sit, pp + n);
	for (int i = 0, j = sit; j < n; ++ j){
		while (i < sit && pp[i].first <= pp[j].first){
			add(pp[i ++].second, 1);
		}
		ans += query(pp[j].second);
	}
	printf("%I64d\n", ans);
	return 0;
}