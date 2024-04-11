#include <cstdio>
#include <vector>
#include <algorithm>

struct query {
	int l, r, ind;
};

struct item {
	int x, amt;
};

const int N = 300005;
const int K = 505;
int n, m, a[N], nextup[N], nextdown[N], l, r, sameup[N], samedown[N];
long long ans, aans[N];
char s[N];
query q[N];
item tmin[N << 1], tmax[N << 1];

bool operator<(query a, query b) 
{
	if (a.l / K != b.l / K) return a.l / K < b.l / K;
	return a.r < b.r;
}

item operator+(item &a, item &b) 
{
	item res;
	res.x = std::max(a.x, b.x);
	res.amt = 0;
	if (a.x == res.x) res.amt += a.amt;
	if (b.x == res.x) res.amt += b.amt;
	return res;
}

inline int f(char ch) 
{
	return ch == '(' ? 1 : -1;
}

void buildmax() 
{
	for (int i = 0; i < n; ++i) {
		tmax[n + i].x = a[i];
		tmax[n + i].amt = 1;
	}
	for (int i = n - 1; i > 0; --i) tmax[i] = tmax[i << 1] + tmax[i << 1 | 1];
}

void buildmin() 
{
	for (int i = 0; i < n; ++i) {
		tmin[n + i].x = -a[i];
		tmin[n + i].amt = 1;
	}
	for (int i = n - 1; i > 0; --i) tmin[i] = tmin[i << 1] + tmin[i << 1 | 1];
}

int query(item *t, int l, int r) 
{
	item res;
	res.x = 1 << 31;
	for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
		if (l & 1) res = res + t[l++];
		if (r & 1) res = res + t[--r];
	}
	return res.amt;
}

void add_s() 
{
	if (nextdown[r] < l) ans += query(tmin, l, r + 1) - 1;
	else ans += samedown[r];
	++r;
}

void rm_s() 
{
	--r;
	if (nextdown[r] < l) ans -= query(tmin, l, r + 1) - 1;
	else ans -= samedown[r];
}

void add_p() 
{
	--l;
	if (nextup[l] > r) ans += query(tmin, l, r) - 1;
	else ans += sameup[l];
}

void rm_p() 
{
	if (nextup[l] > r) ans -= query(tmin, l, r) - 1;
	else ans -= sameup[l];
	++l;
}

int main() 
{
	scanf("%d%d%s", &n, &m, s);
	for (int i = 0; i < n; ++i) a[i + 1] = a[i] + f(s[i]);
	std::vector<int> vec;
	for (int i = 0; i <= n; ++i) {
		while (!vec.empty() && a[i] <= a[vec.back()]) {
			if (a[i] == a[vec.back()]) samedown[i] += samedown[vec.back()] + 1;
			vec.pop_back();
		}
		if (vec.empty()) nextdown[i] = -1;
		else nextdown[i] = vec.back();
		vec.push_back(i);
	}
	vec.clear();
	for (int i = n; i >= 0; --i) {
		while (!vec.empty() && a[i] <= a[vec.back()]) {
			if (a[i] == a[vec.back()]) sameup[i] += sameup[vec.back()] + 1;
			vec.pop_back();
		}
		if (vec.empty()) nextup[i] = n + 1;
		else nextup[i] = vec.back();
		vec.push_back(i);
	}
	++n;
	buildmax();
	buildmin();
	for (int i = 0; i < m; ++i) {
		int type;
		scanf("%d%d%d", &type, &q[i].l, &q[i].r);
		--q[i].l;
		++q[i].r;
		q[i].ind = i;
	}
	std::sort(q, q + m);
	for (int i = 0; i < m; ++i) {
		while (r < q[i].r) add_s();
		while (l > q[i].l) add_p();
		while (r > q[i].r) rm_s();
		while (l < q[i].l) rm_p();
		aans[q[i].ind] = ans;
	}
	for (int i = 0; i < m; ++i) printf("%lld\n", aans[i]);
	return 0;
}